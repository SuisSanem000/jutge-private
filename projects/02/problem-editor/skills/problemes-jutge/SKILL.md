---
name: problemes-jutge
description: |
    Habilitat per quan l'usuari vol treballar (crear, modificar, etc.) amb 
    "problemes del Jutge", "problemes del jutge", o inclús només "problemes".
    Es tracta de problemes en el format de [Jutge.org](https://jutge.org).
---

<!-- totes les referències a fitxers són començant a l'arrel del projecte -->

Llegeix primer la [constitució](/spec/constitucio.md), que cal
complir sempre, en qualsevol cas, i amb la màxima prioritat.

Després, cal llegir
l'[especificació dels problemes](/spec/problema-jutge.md) del
Jutge, per conèixer la seva estructura.

## Creació de problemes

Si la carpeta del problema ja existeix, és possible que l'usuari
hi hagi deixat un fitxer [IDEA.md](<carpeta-problema>/IDEA.md),
que explica la idea del problema i potser un esboç de la solució
i detalls concrets del tipus de problema i dels jocs de prova que
cal fer.

Llavors:

1. Cal crear tots els fitxers indicats a l'especificació del
   problema del Jutge, seguint estrictament la seva estructura i
   format. Els jocs de prova públics cal fer-los manualment.

2. Cal executar el `generate.ts` per generar els jocs de prova
   privats, ja que `jtk make` no ho fa per si sol.

## Modificació de problemes

En el cas de modificacions, cal seguir les instruccions de la
comanda, i revisar, al final que tot és consistent segons es diu
a l'especificació.

## Validació

Un cop creat o modificat un problema, cal validar que compila
correctament amb `jtk make` i observar la sortida d'aquesta
comanda per veure que tot estigui bé.
