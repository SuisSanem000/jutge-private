#!/usr/bin/env bun

const nameMinLen = 15
const nameMaxLen = 25

const allChs = "abcdefghijklmnopqrstuvwxyz"
const allDigits = "0123456789"

const rnd = {
    int: (n: number) => Math.floor(Math.random() * n),
    char: (s: string) => s[rnd.int(s.length)],
    name: () =>
        Array.from({ length: nameMinLen + rnd.int(nameMaxLen - nameMinLen) })
            .map((_) => rnd.char(allChs))
            .join(""),
    elem: (array: string[]) => array[rnd.int(array.length)],
    bool: () => rnd.int(2) == 1,
}

const accumulate = (array: number[]): number[] => {
    const result: number[] = []
    let sum = 0
    for (const value of array) {
        sum += value
        result.push(sum)
    }
    return result
}

const mkArray = (length: number) => Array.from({ length })
const randomShuffle = <T>(array: T[]) => {
    const shuffled = array.slice()
    for (let i = shuffled.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1))
        ;[shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]]
    }
    return shuffled
}

const generatePlayersAndQueries = async (
    filename: string,
    numPlayers: number,
    numQueries: number
) => {
    const players = mkArray(numPlayers).map((_) => rnd.name())
    const sortedPoints = accumulate(mkArray(numPlayers).map((_) => 1 + rnd.int(10)))
    const points = randomShuffle(sortedPoints)

    let result = ``
    for (let i = 0; i < numPlayers; i++) {
        result += `${players[i]} ${points[i]}\n`
    }
    result += `---\n\n`
    for (let i = 0; i < numQueries; i++) {
        result += `${rnd.elem(players)}\n`
    }
    console.log(filename)
    await Bun.write(filename, result)
}

// Jocs de prova de correctesa (petits)
for (const i of [1, 2, 4]) {
    await generatePlayersAndQueries(`private-correctesa-${i}.inp`, i * 100, i * 10000)
}

// Jocs de prova d'eficiència (grans)
for (const i of [8, 16, 32]) {
    await generatePlayersAndQueries(`private-${i}.inp`, i * 100, i * 10000)
}
