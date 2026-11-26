# LABERINTO

| `char` | Significado                      |
| ------ | -------------------------------- |
| `' '`  | se puede pasar                   |
| `'X'`  | no se puede pasar                |
| `'*'`  | hay un tesoro (y se puede pasar) |

Dado un árbol (binario) de `char` (`" X*"`):

- Determinar si hay algún tesoro accesible.
- Contar cuantos tesoros accesibles hay.
- Contar cuántos tesoros inaccesibles hay (inmersión).
- Quitar del árbol los tesoros accesibles.
- Eliminar los subárboles inaccesibles (que en la raíz tienen
  `'X'`).
