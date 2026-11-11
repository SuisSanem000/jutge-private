#!/usr/bin/env bun

const maxN = 100000
const maxE = 1000000000

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

// Edge cases: N = 1, identical heights, negatives, extreme values, simple shapes.
await write("private-correctness-1-edge.inp", [
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

// Alternating values, small random sequences with many ties.
const mixed: Case[] = []
for (let n = 2; n <= 12; n++) {
    mixed.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? 10 : -10)))
    mixed.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? -10 : 10)))
    mixed.push(Array.from({ length: n }, (_, i) => (i % 2 == 0 ? i : -i)))
}
for (let k = 0; k < 300; k++) {
    mixed.push(randomCase(randInt(1, 15), -5, 5))
}
for (let k = 0; k < 100; k++) {
    mixed.push(randomCase(randInt(1, 30), -maxE, maxE))
}
await write("private-correctness-2-alternating-small.inp", mixed)

// Efficiency: large random sequences, wide and narrow ranges.
await write("private-efficiency-1-random.inp", [
    randomCase(maxN, -maxE, maxE),
    randomCase(maxN, -maxE, maxE),
    randomCase(maxN, -1000, 1000),
    randomCase(maxN, -3, 3),
])

// Efficiency: monotone sequences. Strictly decreasing ones are the worst case for
// the quadratic solution (every peak is dominant, so each one is compared with
// all the peaks to its right); the increasing ones have a single dominant peak.
await write("private-efficiency-2-monotone.inp", [
    increasingCase(maxN),
    increasingCase(maxN),
    decreasingCase(maxN),
    decreasingCase(maxN),
    decreasingCase(maxN),
])

// The expected output of the monotone test is larger than the default 2 MB limit.
await Bun.write("private-efficiency-2-monotone.ops", "--maxoutput=4\n")
