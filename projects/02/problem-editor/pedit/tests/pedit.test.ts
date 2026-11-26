import { afterAll, describe, expect, test } from "bun:test";
import { mkdtempSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import {
  applyFileWrites,
  assertSafeRelativePath,
  discoverProblems,
  inspectProblem,
  updateProblemHandler,
  updateProblemMeta,
} from "../src/pbm.ts";

const tempDirs: string[] = [];

afterAll(() => {
  for (const d of tempDirs) {
    rmSync(d, { recursive: true, force: true });
  }
});

describe("pedit pbm helpers", () => {
  test("refuses writing *.cor, problem.yml, or path traversal", () => {
    const dir = mkdtempSync(join(tmpdir(), "pedit-test-"));
    tempDirs.push(dir);

    expect(() => assertSafeRelativePath(dir, "sample-1.cor")).toThrow();
    expect(() => assertSafeRelativePath(dir, "problem.yml")).toThrow();
    expect(() => assertSafeRelativePath(dir, "../escape.txt")).toThrow();
    expect(() => assertSafeRelativePath(dir, "solution.cc")).not.toThrow();
  });

  test("applies writes, updates metadata/handler, and inspects problem", () => {
    const base = mkdtempSync(join(tmpdir(), "pedit-ws-"));
    tempDirs.push(base);
    const pbm = join(base, "demo-prob.pbm");

    const written = applyFileWrites(pbm, {
      "solution.cc": "#include <iostream>\nint main(){return 0;}\n",
      "sample-1.inp": "1\n",
      "problem.en.tex": "\\Problem{Demo}\n\\Statement\nHi\n\\Input\nx\n\\Output\ny\n\\SampleTwoCol\n",
    });
    expect(written).toEqual(["solution.cc", "sample-1.inp", "problem.en.tex"]);

    updateProblemMeta(pbm, "en", { title: "Demo Title", author: "Tester" });
    updateProblemHandler(pbm, { handler: "std", compilers: "G++17", source_modifier: "none" });
    writeFileSync(join(pbm, "sample-1.cor"), "1\n", "utf8");

    const info = inspectProblem(pbm, base);
    expect(info.title).toBe("Demo Title");
    expect(info.languages).toEqual(["en"]);
    expect(info.hasHandler).toBe(true);
    expect(info.solutions).toEqual(["solution.cc"]);
    expect(info.sampleTests).toEqual(["sample-1.inp"]);
    expect(info.missingCor).toEqual([]);

    const found = discoverProblems(base);
    expect(found.length).toBe(1);
    expect(found[0].name).toBe("demo-prob.pbm");
  });
});
