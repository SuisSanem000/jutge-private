#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1)) + min;

const shuffle = (arr: number[]): number[] => {
    const result = [...arr];
    for (let i = result.length - 1; i > 0; i--) {
        const j = rndInt(0, i);
        [result[i], result[j]] = [result[j], result[i]];
    }
    return result;
};

const permutations = (arr: number[]): number[][] => {
    if (arr.length <= 1) return [arr];
    const result: number[][] = [];
    for (let i = 0; i < arr.length; i++) {
        const rest = [...arr.slice(0, i), ...arr.slice(i + 1)];
        for (const perm of permutations(rest)) {
            result.push([arr[i], ...perm]);
        }
    }
    return result;
};

const generateTest = async (filename: string, list: number[]) => {
    console.log(filename);
    await Bun.write(filename, list.join(" ") + "\n");
};

// Jocs de prova de mostra
await generateTest("sample-1.inp", [5, 3, 1, 4, 2]);
await generateTest("sample-2.inp", [1, 2, 3, 4, 5]);
await generateTest("sample-3.inp", [5, 4, 3, 2, 1]);

// ── Part 1: Casos petits ──

await generateTest("private-correctesa-small-buit.inp", []);
await generateTest("private-correctesa-small-un.inp", [42]);
await generateTest("private-correctesa-small-dos-ordenats.inp", [1, 2]);
await generateTest("private-correctesa-small-dos-invertits.inp", [2, 1]);
await generateTest("private-correctesa-small-dos-iguals.inp", [5, 5]);

// ── Part 2: Totes les permutacions de [1,2,3] ──

for (const [i, perm] of permutations([1, 2, 3]).entries()) {
    const pad = String(i + 1).padStart(2, "0");
    await generateTest(`private-correctesa-perm3-${pad}.inp`, perm);
}

// ── Part 3: Totes les permutacions de [1,2,3,4] ──

for (const [i, perm] of permutations([1, 2, 3, 4]).entries()) {
    const pad = String(i + 1).padStart(2, "0");
    await generateTest(`private-correctesa-perm4-${pad}.inp`, perm);
}

// ── Part 4: Casos especials i mitjans ──

await generateTest("private-correctesa-mid-tots-iguals.inp", Array.from({ length: 200 }, () => 7));
await generateTest("private-correctesa-mid-ja-ordenada.inp", Array.from({ length: 500 }, (_, i) => i));
await generateTest("private-correctesa-mid-ordre-invers.inp", Array.from({ length: 500 }, (_, i) => 500 - i));
await generateTest("private-correctesa-mid-random-50.inp", Array.from({ length: 50 }, () => rndInt(-1000, 1000)));
await generateTest("private-correctesa-mid-random-100.inp", Array.from({ length: 100 }, () => rndInt(-1000, 1000)));
await generateTest("private-correctesa-mid-random-200.inp", Array.from({ length: 200 }, () => rndInt(-1000, 1000)));
await generateTest("private-correctesa-mid-random-500.inp", Array.from({ length: 500 }, () => rndInt(-1000, 1000)));
await generateTest("private-correctesa-mid-duplicats.inp", Array.from({ length: 300 }, () => rndInt(1, 5)));
await generateTest("private-correctesa-mid-negatius.inp", Array.from({ length: 200 }, () => rndInt(-100, 100)));
await generateTest("private-long-5000.inp", shuffle(Array.from({ length: 5000 }, (_, i) => i)));
