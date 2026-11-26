import { existsSync } from "node:fs";
import { join, resolve } from "node:path";

export interface CmdResult {
  ok: boolean;
  command: string[];
  cwd: string;
  exitCode: number;
  stdout: string;
  stderr: string;
  durationMs: number;
}

const DEFAULT_TIMEOUT_MS = 120_000;

export async function runCmd(
  args: string[],
  cwd: string,
  timeoutMs = DEFAULT_TIMEOUT_MS,
): Promise<CmdResult> {
  const start = Date.now();
  const absCwd = resolve(cwd);
  const proc = Bun.spawn(args, {
    cwd: absCwd,
    stdout: "pipe",
    stderr: "pipe",
    env: { ...process.env },
  });

  let timedOut = false;
  const timer = setTimeout(() => {
    timedOut = true;
    try {
      proc.kill();
    } catch {
      // ignore if already exited
    }
  }, timeoutMs);

  const [stdout, stderr, exitCode] = await Promise.all([
    new Response(proc.stdout).text(),
    new Response(proc.stderr).text(),
    proc.exited,
  ]);
  clearTimeout(timer);

  return {
    ok: !timedOut && exitCode === 0,
    command: args,
    cwd: absCwd,
    exitCode: timedOut ? 124 : exitCode,
    stdout: stdout.trim(),
    stderr: timedOut
      ? `${stderr.trim()}\n[pedit] Command timed out after ${timeoutMs}ms`.trim()
      : stderr.trim(),
    durationMs: Date.now() - start,
  };
}

export async function runGenerator(pbmDir: string): Promise<CmdResult | null> {
  const genTs = join(pbmDir, "generate.ts");
  if (existsSync(genTs)) {
    return runCmd(["bun", "run", "generate.ts"], pbmDir, 60_000);
  }
  return null;
}

export function jtkMake(pbmDir: string, tasks: string[] = ["all"]): Promise<CmdResult> {
  return runCmd(["jtk", "make", ...tasks, "-d", pbmDir], pbmDir);
}

export function jtkPdf(pbmDir: string): Promise<CmdResult> {
  return runCmd(["jtk", "make", "pdf", "-d", pbmDir], pbmDir);
}

export function jtkLint(pbmDir: string): Promise<CmdResult> {
  return runCmd(["jtk", "lint", "-d", pbmDir], pbmDir);
}

export function jtkVerify(pbmDir: string, programs: string[] = []): Promise<CmdResult> {
  return runCmd(["jtk", "verify", "-d", pbmDir, ...programs], pbmDir);
}

export function jtkClean(pbmDir: string): Promise<CmdResult> {
  return runCmd(["jtk", "clean", "-d", pbmDir], pbmDir);
}
