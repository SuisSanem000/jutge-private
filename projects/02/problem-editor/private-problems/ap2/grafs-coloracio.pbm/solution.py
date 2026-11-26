# solució claude.ai editada per jpetit

import yogi

def greedy_coloring(n, edges):
    """
    Implementa l'algorisme golafre per colorar un graf.

    Args:
        n: nombre de vèrtexs (0 a n-1)
        edges: llista d'arestes [(u,v), ...]

    Returns:
        llista amb el color assignat a cada vèrtex
    """
    # Crear llista d'adjacència
    graph = [[] for _ in range(n)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # Inicialitzar colors dels vèrtexs (-1 significa no colorejat)
    colors = [-1] * n

    # Colorar cada vèrtex seqüencialment
    for vertex in range(n):
        # Trobar els colors utilitzats pels veïns
        neighbor_colors = set()
        for neighbor in graph[vertex]:
            if colors[neighbor] != -1:
                neighbor_colors.add(colors[neighbor])

        # Assignar el color més baix possible
        color = 0
        while color in neighbor_colors:
            color += 1
        colors[vertex] = color

    return colors



if __name__ == "__main__":
    for n in yogi.tokens(int):
        m = yogi.read(int)
        edges = [(yogi.read(int), yogi.read(int)) for _ in range(m)]
        colors = greedy_coloring(n, edges)
        print(len(set(colors)))
