
- **Tipus de Problema**: PRO2.
- **Centre d'interès**: Correctesa.
- **Títol**: Tresors Inaccessibles.

## Codi necessari

En la carpeta `public` es necessita el `bintree.hh`, `bintree-io.hh`, i `assert.hh`. També la carpeta `.vscode` amb els fitxers a punt per poder compilar i debuggar.

## Problema amb 2 apartats

- Aquest problema tindrà una diferència amb respecte als problemes del jutge típics, perquè té dos apartats (a on cal desenvolupar codi diferent en cadascún). Per fer-ho caldrà fer el següent:

    1) En el `main.cc` cal llegir una linia sencera amb `getline` i després mirar si és "apartat1" o "apartat2". Si és l'apartat 1, cal cridar un `main_apartat1`, i si és el 2, `main_apartat2`. Per tant, és com ajuntar 2 problemes en un de sol, perquè en funció de l'entrada, s'executa un codi o un altre. Cada `main_apartatX` cridarà una funció diferent de les que es demanen en el problema, i la resta de l'entrada la llegirà cada `main_apartatX` cridant la funció de l'apartat que sigui i fent el típic per a un problema normal.
    2) En els `scores.yml` cal, precisament, separar l'apartat 1 del 2. Tots els jocs de prova de l'apartat 1 comencen amb "apartat1" com a primera línia, i "apartat2" com a segona linia.


### Puntuació

Apartat 1: 5 punts
Apartat 2: 5 punts

## Idea

La idea és que un arbre binari de `char`s és com el mapa d'una cova, en la que cada node indica una de tres possibles coses: `' '`, hi ha un passadís que es pot creuar; `'X'` un passadís que no es pot creuar; i `'*'` un _tresor_. A la cova s'entra per l'arrel de l'arbre i per tant, segons l'accessibiltat de cada branca, es podrà o no accedir a certs tresors.

El problema té dos apartats:
1) Fer una funció `compta_tresors_accessibles`, que és recursiva i no requereix inmersió (fer una funció recursiva apart).
2) Fer una funció `compta_tresors_inaccessibles`, que és recursiva i sí requereix inmersió (cal fer una funció recursiva apart que tingui un paràmetre `bool` que permeti saber si estem en una part de l'arbre que és inaccessible o no.

