#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1)) + min;

function combinations(n: number, k: number): number[][] {
    const result: number[][] = [];
    const cur: number[] = [];
    const backtrack = (start: number) => {
        if (cur.length === k) {
            result.push([...cur]);
            return;
        }
        for (let i = start; i < n; i++) {
            cur.push(i);
            backtrack(i + 1);
            cur.pop();
        }
    };
    backtrack(0);
    return result;
}

const selectPositions = (len: number, n: number): number[] => {
    const strategic = [
        0, len - 1, Math.floor(len / 2), Math.floor(len / 4),
        Math.floor((3 * len) / 4), Math.floor(len / 3),
        Math.floor((2 * len) / 3), Math.floor(len / 10),
        Math.floor((9 * len) / 10), Math.floor(len / 5),
    ];
    const pos = new Set<number>();
    for (const s of strategic) {
        if (pos.size >= n) break;
        pos.add(s);
    }
    while (pos.size < n) {
        pos.add(rndInt(1, len - 2));
    }
    return [...pos];
};

const formatPlayers = (names: string[], scores: number[]) =>
    names.map((name, i) => `${name} ${scores[i]}`).join("\n") + "\n";

const generateWithScores = async (filename: string, names: string[], scores: number[]) => {
    console.log(filename);
    await Bun.write(filename, formatPlayers(names, scores));
};

const generateLong = async (filename: string, len: number, maxPositions: number[]) => {
    const maxSet = new Set(maxPositions);
    const names = Array.from({ length: len }, (_, i) => `p${String(i).padStart(6, "0")}`);
    const scores = Array.from({ length: len }, (_, i) => maxSet.has(i) ? 10000 : rndInt(1, 9999));
    console.log(filename);
    await Bun.write(filename, formatPlayers(names, scores));
};

const generateAllEqual = async (filename: string, len: number, score: number) => {
    const names = Array.from({ length: len }, (_, i) => `p${String(i).padStart(6, "0")}`);
    const scores = Array.from({ length: len }, () => score);
    console.log(filename);
    await Bun.write(filename, formatPlayers(names, scores));
};

// ── Part 1: Totes les combinacions de 1..4 màxims entre 4 jugadors (15 tests) ──

const names4 = ["anna", "biel", "carla", "dani"];

for (let k = 1; k <= 4; k++) {
    for (const [i, maxPos] of combinations(4, k).entries()) {
        const maxSet = new Set(maxPos);
        const scores = names4.map((_, j) => maxSet.has(j) ? 100 : 50);
        const pad = String(i + 1).padStart(2, "0");
        await generateWithScores(`private-correctesa-exhaust-k${k}-${pad}.inp`, names4, scores);
    }
}

// ── Part 2: Casos petits interessants ──

await generateWithScores("private-correctesa-small-un-sol.inp", ["sola"], [42]);
await generateWithScores("private-correctesa-small-max-primer.inp", ["alta", "baixa"], [100, 50]);
await generateWithScores("private-correctesa-small-max-segon.inp", ["baixa", "alta"], [50, 100]);
await generateWithScores("private-correctesa-small-empat-dos.inp", ["una", "altra"], [100, 100]);
await generateWithScores("private-correctesa-small-ascendent.inp", ["x", "y", "z"], [10, 20, 30]);
await generateWithScores("private-correctesa-small-descendent.inp", ["x", "y", "z"], [30, 20, 10]);
await generateWithScores("private-correctesa-small-dos-max-mig.inp", ["a", "b", "c", "d", "e"], [10, 50, 20, 50, 10]);
await generateWithScores("private-correctesa-small-tots-iguals.inp", ["a", "b", "c", "d", "e"], [77, 77, 77, 77, 77]);

// ── Part 3: Llistes llargues ──

const L = 100_000;

await generateLong("private-long-max-inici.inp", L, [0]);
await generateLong("private-long-max-final.inp", L, [L - 1]);
await generateLong("private-long-max-mig.inp", L, [Math.floor(L / 2)]);
for (let k = 2; k <= 10; k++) {
    await generateLong(`private-long-k${k}.inp`, L, selectPositions(L, k));
}
await generateAllEqual("private-long-tots-iguals.inp", L, 500);
await generateLong("private-long-1M-k5.inp", 1_000_000, selectPositions(1_000_000, 5));
