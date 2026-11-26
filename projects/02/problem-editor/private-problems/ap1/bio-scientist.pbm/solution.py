import yogi


def search_at(gene, dna, position):
    m = len(dna)
    mutations = 0
    for i in range(m):
        if gene[position + i] != dna[i]:
            if mutations == 0:
                mutations = 1
            else:
                return False, None
    return True, mutations


def search(gene, dna):
    n = len(gene)
    m = len(dna)
    for position in range(n - m + 1):
        match, mutations = search_at(gene, dna, position)
        if match:
            return True, position, mutations
    return False, None, None


def main():
    gene = yogi.read(str)
    for dna in yogi.tokens(str):
        match, position, mutations = search(gene, dna)
        if match:
            print(position, mutations)
        else:
            print('-')


main()
