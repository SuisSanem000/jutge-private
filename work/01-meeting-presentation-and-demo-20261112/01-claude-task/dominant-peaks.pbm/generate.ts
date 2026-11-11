#!/usr/bin/env bun

// Problem limits and test parameters.
const maxN = 100000
const maxE = 1000000000
const smallRange = 5
const smallMaxN = 15
const mediumMaxN = 30

// Deterministic pseudo-random generator (mulberry32), so tests are reproducible.
let seed = 20240607
const random = (): number => {
    seed = (seed + 0x6d2b79f5) | 0
    let t = Math.imul(seed ^ (seed >>> 15), 1 | seed)
    t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296
}

// Random integer in [lo, hi].
const randInt = (lo: number, hi: number): number => lo + Math.floor(random() * (hi - lo + 1))

type Case = number[]

const randomCase = (n: number, lo: number, hi: number): Case =>
    Array.from({ length: n }, () => randInt(lo, hi))

const increasingCase = (n: number): Case =>
    Array.from({ length: n }, (_, i) => -maxE + i * 20000)

const decreasingCase = (n: number): Case =>
    Array.from({ length: n }, (_, i) => maxE - i * 20000)

const write = async (filename: string, cases: Case[]) => {
    const lines: string[] = []
    for (const c of cases) {
        lines.push(`${c.length}`)
        lines.push(c.join(" "))
    }
    console.log(filename)
    await Bun.write(filename, lines.join("\n") + "\n")
}

const generateEdgeCases = async (filename: string) => {
    await write(filename, [
        [0],
        [5],
        [-7],
        [maxE],
        [-maxE],
        [3, 3],
        [4, 4, 4, 4, 4],
        [-2, -2, -2],
        [-5, -3, -4, -1, -9],
        [-maxE, maxE],
        [maxE, -maxE],
        [maxE, maxE, -maxE, -maxE],
        [1, 2, 3, 4, 5],
        [5, 4, 3, 2, 1],
        [1, 4, 2, 3, 5],
        [7, 7, 8, 8, 6, 6],
        [2, 1, 2, 1, 2],
    ])
}

// Alternating sequences of every length up to maxLength, plus small random
// sequences with many ties (values in [-smallRange, smallRange]) and a few
// with the full range of elevations.
const generateAlternatingAndSmall = async (
    filename: string,
    maxLength: number,
    numTies: number,
    numWide: number
) => {
    const cases: Case[] = []
    for (let n = 2; n <= maxLength; n++) {
        cases.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? 10 : -10)))
        cases.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? -10 : 10)))
        cases.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? i : -i)))
    }
    for (let k = 0; k < numTies; k++) {
        cases.push(randomCase(randInt(1, smallMaxN), -smallRange, smallRange))
    }
    for (let k = 0; k < numWide; k++) {
        cases.push(randomCase(randInt(1, mediumMaxN), -maxE, maxE))
    }
    await write(filename, cases)
}

// Large random sequences: `count` cases of length n and elevations in [-range, range].
const generateRandom = async (filename: string, count: number, n: number, range: number) => {
    const cases: Case[] = []
    for (let k = 0; k < count; k++) {
        cases.push(randomCase(n, -range, range))
    }
    await write(filename, cases)
}

// Monotone sequences of length n. Strictly decreasing ones are the worst case for
// the quadratic solution (every peak is dominant, so each one is compared with
// all the peaks to its right); the increasing ones have a single dominant peak.
// The expected output can exceed the default 2 MB limit, hence the .ops file.
const generateMonotone = async (
    filename: string,
    n: number,
    numIncreasing: number,
    numDecreasing: number,
    maxOutputMB: number
) => {
    const cases: Case[] = []
    for (let k = 0; k < numIncreasing; k++) {
        cases.push(increasingCase(n))
    }
    for (let k = 0; k < numDecreasing; k++) {
        cases.push(decreasingCase(n))
    }
    await write(filename, cases)
    await Bun.write(filename.replace(".inp", ".ops"), `--maxoutput=${maxOutputMB}\n`)
}

await generateEdgeCases("private-correctness-1-edge.inp")
await generateAlternatingAndSmall("private-correctness-2-alternating-small.inp", 12, 300, 100)
await generateRandom("private-efficiency-1-random.inp", 2, maxN, maxE)
await generateRandom("private-efficiency-1-random-ties.inp", 2, maxN, 3)
await generateMonotone("private-efficiency-2-monotone.inp", maxN, 2, 3, 4)
