#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1)) + min;

const rndName = (len: number) => {
    const chars = "abcdefghijklmnopqrstuvwxyz";
    let name = chars[rndInt(0, chars.length - 1)].toUpperCase();
    for (let i = 1; i < len; i++) {
        name += chars[rndInt(0, chars.length - 1)];
    }
    return name;
};

type Contribucio = { empresa: string; quantitat: number };

const generateTest = (
    numEmpreses: number,
    contribPerEmpresa: number,
    llindar: number,
    maxQuantitat: number,
    minContribPerEmpresa: number = 1,
): string => {
    const empreses: string[] = [];
    for (let i = 0; i < numEmpreses; i++) {
        empreses.push(`Emp${String(i).padStart(5, "0")}`);
    }

    const contribucions: Contribucio[] = [];
    for (const emp of empreses) {
        const n = rndInt(minContribPerEmpresa, contribPerEmpresa);
        for (let j = 0; j < n; j++) {
            contribucions.push({ empresa: emp, quantitat: rndInt(1, maxQuantitat) });
        }
    }

    // Barrejar
    for (let i = contribucions.length - 1; i > 0; i--) {
        const j = rndInt(0, i);
        [contribucions[i], contribucions[j]] = [contribucions[j], contribucions[i]];
    }

    let output = `${llindar}\n`;
    for (const c of contribucions) {
        output += `${c.empresa} ${c.quantitat}\n`;
    }
    return output;
};

let testNum = 1;

// ── Correctesa: casos petits i mitjans ──

// Cas molt petit: 3 empreses, poques contribucions
await Bun.write(
    `private-correctesa-${testNum}-petit.inp`,
    generateTest(3, 5, 100, 50)
);
testNum++;

// Cas on cap empresa supera el llindar
await Bun.write(
    `private-correctesa-${testNum}-cap.inp`,
    generateTest(5, 3, 100000, 10)
);
testNum++;

// Cas on totes superen
await Bun.write(
    `private-correctesa-${testNum}-totes.inp`,
    generateTest(5, 10, 10, 1000)
);
testNum++;

// Cas amb empreses amb 1 o 2 contribucions (menys de 3)
let output = `50\n`;
output += `Unica 100\n`;
output += `Dues 30\nDues 25\n`;
output += `Tres 10\nTres 20\nTres 15\n`;
output += `Petita 5\nPetita 3\n`;
await Bun.write(`private-correctesa-${testNum}-poques-contrib.inp`, output);
testNum++;

// Cas mitjà: 50 empreses
await Bun.write(
    `private-correctesa-${testNum}-mitja.inp`,
    generateTest(50, 10, 500, 200)
);
testNum++;

// Cas mitjà: 100 empreses
await Bun.write(
    `private-correctesa-${testNum}-mitja2.inp`,
    generateTest(100, 20, 1000, 500)
);
testNum++;

console.log(`Correctesa: ${testNum - 1} jocs de prova`);

// ── Eficiència: casos grans ──
// Poques empreses amb milers de donacions cadascuna, per penalitzar
// solucions que recorren linealment les contribucions de cada empresa.

let effNum = 1;

// 100 empreses, 10000 contribucions cadascuna
await Bun.write(
    `private-eficiencia-${effNum}-gran.inp`,
    generateTest(100, 10000, 5000, 2000, 10000)
);
effNum++;

// 50 empreses, 20000 contribucions cadascuna
await Bun.write(
    `private-eficiencia-${effNum}-gran2.inp`,
    generateTest(50, 20000, 3000, 1000, 20000)
);
effNum++;

// 200 empreses, 5000 contribucions cadascuna
await Bun.write(
    `private-eficiencia-${effNum}-gran3.inp`,
    generateTest(200, 5000, 2000, 1000, 5000)
);
effNum++;

// 20 empreses, 50000 contribucions cadascuna
await Bun.write(
    `private-eficiencia-${effNum}-molt-gran.inp`,
    generateTest(20, 50000, 10000, 5000, 50000)
);
effNum++;

// 100 empreses, 15000 contribucions, cap supera
await Bun.write(
    `private-eficiencia-${effNum}-cap-gran.inp`,
    generateTest(100, 15000, 1000000, 100, 15000)
);
effNum++;

console.log(`Eficiència: ${effNum - 1} jocs de prova`);
console.log(`\nTotal: ${testNum - 1 + effNum - 1} jocs de prova generats.`);
