#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1) + min);

const rndChoice = <T>(arr: T[]): T => arr[rndInt(0, arr.length - 1)];

function shuffleArray<T>(array: T[]) {
    for (var i = array.length - 1; i >= 0; i--) {
        var j = Math.floor(Math.random() * (i + 1));
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

const rndValue = () => String(rndInt(1, 9));
const rndOperator = () => rndChoice(["+", "-", "*"]);

type Tree = null | { value: string; children: Tree[] };

const rndTreeOrValue = (height: number, numChildren: number): Tree => {
    if (height === 1) {
        return { value: rndValue(), children: [] };
    }
    return rndInt(1, 8) <= 5
        ? { value: rndValue(), children: [] }
        : rndTree(height, numChildren);
};

const rndTree = (height: number, numChildren: number): Tree => {
    if (height === 0) {
        return null;
    }
    if (height === 1) {
        return { value: rndValue(), children: [] };
    }
    let children = [];
    for (let i = 0; i < numChildren; i++) {
        const nonNulls = children.some((c) => c !== null);
        if (nonNulls) {
            children.push(rndTreeOrValue(height - 1, rndInt(2, 5)));
        } else {
            children.push(rndTree(height - 1, rndInt(2, 5)));
        }
    }
    shuffleArray(children);
    return { value: rndOperator(), children };
};

const treeToString = (
    tree: Tree,
    prefixHead: string = "",
    prefixRest: string = ""
) => {
    if (!tree) {
        return `${prefixHead}#\n`;
    }
    let result = `${prefixHead}${tree.value}\n`;
    if (tree.children.some((c) => c !== null)) {
        for (let i = 0; i < tree.children.length - 1; i++) {
            result += treeToString(
                tree.children[i],
                `${prefixRest}|-- `,
                `${prefixRest}|   `
            );
        }
        result += treeToString(
            tree.children[tree.children.length - 1],
            `${prefixRest}'-- `,
            `${prefixRest}    `
        );
    }
    return result;
};

const generateTestcase = async (
    filename: string,
    numTrees: number,
    height: () => number
) => {
    let output = ``;
    for (let i = 0; i < numTrees; i++) {
        output += `${treeToString(
            rndTree(height(), rndInt(2, 4))
        )}\n`;
    }
    console.log(filename);
    await Bun.write(filename, output);
};

// Correctesa: arbres petits (alçada 1-3, 100 arbres)
await generateTestcase("private-correctesa-1-petits.inp", 100, () => rndInt(1, 3));

// Correctesa: arbres mitjans (alçada 4-8, 150 arbres)
await generateTestcase("private-correctesa-2-mitjans.inp", 150, () => rndInt(4, 8));

// Correctesa: arbres grans (alçada 9-14, 200 arbres)
await generateTestcase("private-correctesa-3-grans.inp", 200, () => rndInt(9, 14));
