#!/usr/bin/env bun

const generateTest = async (filename: string, min: number, max: number) => {
    let output = "";
    for (let i = min; i < max; i++) {
        output += `${i}\n`;
    }
    console.log(filename);
    await Bun.write(filename, output);
};

// Tots els nombres d'almenys 2 xifres fins a 6 xifres
await generateTest("private-correctesa-001.inp", 10, 1000000);
