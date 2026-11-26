- **Tipus de problema**: PRO2
- **Center d'interès**: Correctesa
- **Títol**: Urgències Hospitalaries.

## Fitxers

A la carpeta `public`, cal tenir `heap.hh` i `assert.hh`. També la carpeta `.vscode` per poder compilar i debuggar.

## Idea

Es tracta de fer un programa que rebi com a entrada les arribades de pacients (prioritat, codi i "timestamp") a les urgències d'un hospital, també els moments en els quals el proper pacient entra per ser atès i calculi dues coses:
1. L'ordre en què els pacients són atesos.
2. El temps d'espera mitjà dels pacients amb cada prioritat.

La prioritat dels pacients pot ser 1, 2 o 3. A l'hora d'atendre els pacients, 

Per implementar-ho, cal fer servir una cua de prioritat amb una tupla `Pacient`, que pugui ser ordenat per prioritat (té `operator<`, aquest sí que cal que hi sigui).  

L'entrada té tres tipus d'events:
- Arriba un pacient. `arriba <ID pacient> <timestamp>`.
- Entra un pacient per ser atès. `seguent <timestamp>`.
- Un pacient surt perquè s'ha finalitzat la seva atenció. `surt <timestamp>`.

Suposarem que només 1 pacient pot estar dins de la consulta, per simplificar. Però els events de `seguent` i `surt` no tenen perquè tenir el mateix `<timestamp>` perquè de vegades es requereix un temps entre que surt un pacient i n'entra un altre. L'entrada ha de garantir que els events tenen sentit, és a dir, que mai hi ha més d'un pacient a la consulta (sempre s'alternen els events `seguent` i `surt`).

Tots els events tenen un instant temporal (un "timestamp", per simplificar, o sigui un número de segons).

La sortida de la mitjana cal fer-la amb 2 decimals fent servir el següent codi per posar la precisió des de l'inici:

```c++
cin.setf(std::ios::fixed);
cin.precision(2);
```

