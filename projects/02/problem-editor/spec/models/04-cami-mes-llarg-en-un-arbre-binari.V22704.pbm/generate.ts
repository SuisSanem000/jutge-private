#!/usr/bin/env bun

const rndInt = (min: number, max: number) =>
    Math.floor(Math.random() * (max - min + 1) + min);

let rndMax = 10;
const rndValue = () => rndInt(1, rndMax);

type BinTree = null | { value: number; left: BinTree; right: BinTree };
type Shape = null | { left: Shape; right: Shape };

// Genera totes les formes d'arbre amb alçada <= h
// (alçada de null = 0, alçada d'una fulla = 1)
const allShapesUpTo = (h: number): Shape[] => {
    if (h === 0) return [null];
    const smaller = allShapesUpTo(h - 1);
    const result: Shape[] = [null];
    for (const left of smaller) {
        for (const right of smaller) {
            result.push({ left, right });
        }
    }
    return result;
};

const shapeHeight = (s: Shape): number => {
    if (s === null) return 0;
    return 1 + Math.max(shapeHeight(s.left), shapeHeight(s.right));
};

const shapesOfHeight = (h: number): Shape[] =>
    allShapesUpTo(h).filter((s) => shapeHeight(s) === h);

const assignRandomValues = (shape: Shape): BinTree => {
    if (shape === null) return null;
    return {
        value: rndValue(),
        left: assignRandomValues(shape.left),
        right: assignRandomValues(shape.right),
    };
};

const rndDeepTree = (height: number): BinTree => {
    if (height === 0) {
        return null;
    }
    let left: BinTree = rndDeepTree(height - 1);
    let right: BinTree = { value: rndValue(), left: null, right: null };
    if (rndInt(1, 2) == 1) {
        [left, right] = [right, left];
    }
    return { value: rndValue(), left, right };
};

// Arbre degenerat cap a l'esquerra (el camí més llarg va sempre a l'esquerra)
const deepTreeLeft = (height: number): BinTree => {
    if (height === 0) return null;
    return {
        value: rndValue(),
        left: deepTreeLeft(height - 1),
        right: { value: rndValue(), left: null, right: null },
    };
};

// Arbre degenerat cap a la dreta (el camí més llarg va sempre a la dreta)
const deepTreeRight = (height: number): BinTree => {
    if (height === 0) return null;
    return {
        value: rndValue(),
        left: { value: rndValue(), left: null, right: null },
        right: deepTreeRight(height - 1),
    };
};

const treeToStringVisual = (tree: BinTree) => {
    let output = ``;

    const _tree2str = (
        tree: BinTree,
        prefixHead: string,
        prefixRest: string
    ) => {
        if (!tree) {
            output += `${prefixHead}#\n`;
            return;
        }
        output += `${prefixHead}${tree.value}\n`;
        if (tree.left || tree.right) {
            _tree2str(tree?.left, `${prefixRest}|-- `, `${prefixRest}|   `);
            _tree2str(tree?.right, `${prefixRest}'-- `, `${prefixRest}    `);
        }
    };

    _tree2str(tree, "", "");

    output += `\n`;
    return output;
};

const treeToStringInline = (tree: BinTree) => {
    const _tree2str = (tree: BinTree) => {
        if (!tree) {
            return ``;
        } else if (!tree.left && !tree.right) {
            return `${tree.value}`;
        } else {
            let left = _tree2str(tree.left);
            let right = _tree2str(tree.right);
            return `${tree.value}(${left},${right})`;
        }
    };

    return _tree2str(tree) + `\n`;
};

const generateCorrectness = async (filename: string) => {
    let output = `visual\n`;
    for (const h of [2, 3, 4]) {
        for (const shape of shapesOfHeight(h)) {
            output += treeToStringVisual(assignRandomValues(shape));
        }
    }
    console.log(filename);
    await Bun.write(filename, output);
};

const generatePrivate = async (filename: string, height: number) => {
    let output = `inline\n`;
    rndMax = 10;
    // Arbre degenerat aleatori
    output += treeToStringInline(rndDeepTree(height));
    // Arbre degenerat a l'esquerra
    output += treeToStringInline(deepTreeLeft(height));
    // Arbre degenerat a la dreta
    output += treeToStringInline(deepTreeRight(height));
    console.log(filename);
    await Bun.write(filename, output);
};

await generateCorrectness(`private-correctesa-1.inp`);
await generatePrivate("private-deep.inp", 10000);
