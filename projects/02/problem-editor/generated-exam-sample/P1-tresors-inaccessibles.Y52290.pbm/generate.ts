#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1)) + min;

const CHARS = [".", "X", "*"];
const rndChar = () => CHARS[rndInt(0, 2)];

const NUM_ARBRES_MITJANS = 50;
const NUM_ARBRES_GRANS = 30;
const ALCADA_ARBRE_MITJA = 5;
const ALCADA_ARBRE_GRAN = 10;

type BinTree = null | { value: string; left: BinTree; right: BinTree };

const rndBinTree = (maxHeight: number): BinTree => {
    if (maxHeight <= 0) return null;
    if (maxHeight === 1) return { value: rndChar(), left: null, right: null };
    const hasLeft = rndInt(0, 1) === 1;
    const hasRight = rndInt(0, 1) === 1;
    if (!hasLeft && !hasRight) {
        return { value: rndChar(), left: null, right: null };
    }
    return {
        value: rndChar(),
        left: hasLeft ? rndBinTree(maxHeight - 1) : null,
        right: hasRight ? rndBinTree(maxHeight - 1) : null,
    };
};

// Genera tots els arbres possibles amb un conjunt de valors
const allBinTrees = (height: number): BinTree[] => {
    if (height === 0) return [null];
    if (height === 1) return CHARS.map((c) => ({ value: c, left: null, right: null }));
    const smaller = allBinTrees(height - 1);
    const allSub = [null, ...smaller];
    const result: BinTree[] = [];
    for (const c of CHARS) {
        for (const l of allSub) {
            for (const r of allSub) {
                if (l === null && r === null) continue;
                result.push({ value: c, left: l, right: r });
            }
        }
    }
    return result;
};

const treeToVisual = (tree: BinTree): string => {
    let output = "";
    const write = (t: BinTree, prefixHead: string, prefixRest: string) => {
        if (!t) {
            output += `${prefixHead}#\n`;
            return;
        }
        output += `${prefixHead}${t.value}\n`;
        if (t.left || t.right) {
            write(t.left, `${prefixRest}|-- `, `${prefixRest}|   `);
            write(t.right, `${prefixRest}'-- `, `${prefixRest}    `);
        }
    };
    write(tree, "", "");
    output += "\n";
    return output;
};

const writeTestFile = async (apartat: string, trees: BinTree[], filename: string) => {
    let content = `${apartat}\n`;
    for (const t of trees) {
        content += treeToVisual(t);
    }
    await Bun.write(filename, content);
};

let testNum = 1;

// ── Apartat 1: tresors accessibles ──

// Exhaustiu: tots els arbres d'alçada <= 2
const petits1 = allBinTrees(1).concat(allBinTrees(2));
await writeTestFile("apartat1", petits1, `private-apartat1-${testNum}-exhaustiu-petits.inp`);
testNum++;

// Exhaustiu: tots els arbres generats amb paràmetre d'alçada 3 (6345 arbres: 3 × (46² − 1))
const exhaustiuH3 = allBinTrees(3);
await writeTestFile("apartat1", exhaustiuH3, `private-apartat1-${testNum}-exhaustiu-alcada3.inp`);
testNum++;

// Arbres aleatoris d'alçada moderada
let arbres: BinTree[] = [];
for (let i = 0; i < NUM_ARBRES_MITJANS; i++) arbres.push(rndBinTree(ALCADA_ARBRE_MITJA));
await writeTestFile("apartat1", arbres, `private-apartat1-${testNum}-mitjans.inp`);
testNum++;

// Arbres aleatoris d'alçada gran
arbres = [];
for (let i = 0; i < NUM_ARBRES_GRANS; i++) arbres.push(rndBinTree(ALCADA_ARBRE_GRAN));
await writeTestFile("apartat1", arbres, `private-apartat1-${testNum}-grans.inp`);
testNum++;

// Cas especial: arbre amb arrel X (tot inaccessible, resultat 0)
const arbreArrelX: BinTree = {
    value: "X",
    left: { value: "*", left: { value: "*", left: null, right: null }, right: null },
    right: { value: "*", left: null, right: { value: "*", left: null, right: null } },
};
await writeTestFile("apartat1", [arbreArrelX], `private-apartat1-${testNum}-arrel-x.inp`);
testNum++;

// Cas especial: arbre tot de tresors
const arbreTresors: BinTree = {
    value: "*",
    left: { value: "*", left: { value: "*", left: null, right: null }, right: { value: "*", left: null, right: null } },
    right: { value: "*", left: { value: "*", left: null, right: null }, right: { value: "*", left: null, right: null } },
};
await writeTestFile("apartat1", [arbreTresors], `private-apartat1-${testNum}-tot-tresors.inp`);
testNum++;

console.log(`Apartat 1: ${testNum - 1} jocs de prova`);

// ── Apartat 2: tresors inaccessibles ──

let testNum2 = 1;

// Exhaustiu: tots els arbres d'alçada <= 2
await writeTestFile("apartat2", petits1, `private-apartat2-${testNum2}-exhaustiu-petits.inp`);
testNum2++;

// Exhaustiu: mateix conjunt d'alçada 3 que a l'apartat 1
await writeTestFile("apartat2", exhaustiuH3, `private-apartat2-${testNum2}-exhaustiu-alcada3.inp`);
testNum2++;

// Arbres aleatoris d'alçada moderada
arbres = [];
for (let i = 0; i < NUM_ARBRES_MITJANS; i++) arbres.push(rndBinTree(ALCADA_ARBRE_MITJA));
await writeTestFile("apartat2", arbres, `private-apartat2-${testNum2}-mitjans.inp`);
testNum2++;

// Arbres aleatoris d'alçada gran
arbres = [];
for (let i = 0; i < NUM_ARBRES_GRANS; i++) arbres.push(rndBinTree(ALCADA_ARBRE_GRAN));
await writeTestFile("apartat2", arbres, `private-apartat2-${testNum2}-grans.inp`);
testNum2++;

// Cas especial: arbre amb arrel X (tots inaccessibles)
await writeTestFile("apartat2", [arbreArrelX], `private-apartat2-${testNum2}-arrel-x.inp`);
testNum2++;

// Cas especial: arbre amb X al mig que bloqueja tresors
const arbreXmig: BinTree = {
    value: ".",
    left: {
        value: "X",
        left: { value: "*", left: null, right: null },
        right: { value: "*", left: { value: "*", left: null, right: null }, right: null },
    },
    right: {
        value: "*",
        left: null,
        right: { value: ".", left: { value: "*", left: null, right: null }, right: null },
    },
};
await writeTestFile("apartat2", [arbreXmig], `private-apartat2-${testNum2}-x-al-mig.inp`);
testNum2++;

// Cas especial: arbre sense cap tresor
const arbreSenseTresors: BinTree = {
    value: ".",
    left: { value: "X", left: { value: ".", left: null, right: null }, right: null },
    right: { value: ".", left: null, right: { value: "X", left: null, right: null } },
};
await writeTestFile("apartat2", [arbreSenseTresors], `private-apartat2-${testNum2}-sense-tresors.inp`);
testNum2++;

console.log(`Apartat 2: ${testNum2 - 1} jocs de prova`);
console.log(`\nTotal: ${testNum - 1 + testNum2 - 1} jocs de prova generats.`);
