#!/usr/bin/env bun

const lower = "abcdefghijklmnopqrstuvwxyz";

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1)) + min;

const randWord = (): string => {
    const len = rndInt(3, 7);
    return Array.from({ length: len }, () => lower[rndInt(0, lower.length - 1)]).join("");
};

const generateTest = async (filename: string, n: number) => {
    const pairs = Array.from({ length: n }, () => `${randWord()} ${rndInt(0, 99)}`);
    console.log(filename);
    await Bun.write(filename, pairs.join("\n") + "\n");
};

// Joc 1: Llista petita (10 parelles)
await generateTest("private-correctesa-1.inp", 10);

// Joc 2: Llista mitjana (100 parelles)
await generateTest("private-correctesa-2.inp", 100);

// Joc 3: Llista gran (1000 parelles)
await generateTest("private-correctesa-3.inp", 1000);
