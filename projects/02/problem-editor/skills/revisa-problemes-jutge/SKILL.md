---
name: revisa-problemes-jutge
description: |
    Habilitat per quan l'usuari vol revisar un o més "problemes del Jutge", 
    "problemes del jutge", o inclús només "problemes".
    Es tracta de problemes en el format de [Jutge.org](https://jutge.org).
---

<!-- totes les referències a fitxers són començant a l'arrel del projecte -->

Llegeix primer la [constitució](/spec/constitucio.md), que cal
complir sempre, en qualsevol cas, i amb la màxima prioritat.

Després, cal llegir
l'[especificació dels problemes](/spec/problema-jutge.md) del
Jutge, per conèixer la seva estructura.

## Revisar problemes del jutge

Un problema del jutge té moltes parts i estan relacionades entre
elles.

### Tipus de problema

Segons cada tipus de problema, la solució esperada és una cosa
diferent o bé hi ha d'haver carpeta `public` o no. Cal revisar
que tot és tal com està definit per problemes de tipus `G++17`,
`PRO2` i `MakePRO2`: carpetes necessàries, permeses i fitxers de
solució.

També cal mirar que els paràmetres de `handler.yml` siguin
compatibles. Això també ho fa `jtk make` per tant fer un
`jtk make` permet esbrinar si hi ha problemes.

### Enunciat

Cal revisar l'enunciat, primer en català i després en castellà.
L'enunciat en castellà cal que sigui una traducció directa i
sense canvis de la versió en català.

1. Ortografia i gramàtica (català o castellà):
    - Faltes d'ortografia.
    - Errors d'accentuació, apostrofació, guionets.
    - Concordança de gènere i nombre.
    - Ús incorrecte de preposicions o pronoms febles.

2. Matemàtiques:
    - Errors en noms de variable, variables amb noms millorables.
    - Errors lògics en les fórmules.
    - Errors en els símbols.
    - Errors en el codi LaTeX per produir els símbols.

3. Contingut tècnic (C++, estructures de dades, algorismes)
    - Errors en fragments de codi C++ (sintaxi, lògica).
    - Explicacions tècniques incorrectes o imprecises.
    - Incoherències entre el text i el codi que l'acompanya.
    - Comentaris fora de lloc o equivocats.
    - Trossos de codi sense comentar que són difícils d'entendre.
    - Exemples posats al text que no concorden amb els fitxers
      adjunts.
    - Errors al LaTeX que permet incloure codi.

4. Entrada y Sortida:
    - L'entrada y la sortida han d'estar perfectament
      especificades.
    - Els exemples d'entrada i sortida s'han de correspondre
      exactament amb l'especificació.
    - Els exemples d'entrada i sortida han de mostrar exemples
      diversos per ajudar la comprensió.
    - Cal comprovar no hi ha ambigüitat en l'ordre dels elements
      de la sortida. Per exemple, si tenim jugadors ordenats per
      punts, cal dir quin és l'ordre si hi ha empats (típicament
      el nom del jugador). Això ha de ser explícit a l'enunciat.

### Codi de la solució

Cal revisar que l'estil sigui:

- Clar: noms molt ben pensats per la comprensió, tant de funcions
  com de variables.
- Sense repetició, sempre utilitzant funcions auxiliars
  reutilitzables i amb bons noms.
- Cal formatar amb `clang-format -i <nom-fitxer>` si el format no
  és perfecte.
- Amb comentaris en punts clau en què està bé per didàctica
  aclarir què passa.

Cal revisar que no s'utilitzin estructures avançades de C++:

- L'estàndar ha de ser C++17. Però cal fer un codi molt estàndard
  que no utilitzi característiques complicades de C++, que poca
  gent conegui.

- Es pot fer servir: `auto`, `tolower`, `toupper`, `max` i `min`,
  `swap` i també les funcions `islower`, `isupper`, etc.

### Generador (`generator.ts`)

Del generador de jocs de prova cal mirar:

- Que genera cada fitxer `.inp` amb una funció diferent que a més
  té com a paràmetres els tamanys de cada aspecte.

- Que hi ha constants per ajustar els paràmetres generals que
  afecten tot el fitxer i no números "màgics" en el codi.

- Que té el bit d'executable per poder-lo executar a la línia de
  comandes.

- Que té la línia `#!/usr/bin/env bun` per poder-lo executar amb
  Bun.

### Fitxers `.ops`

- Si hi ha jocs de prova amb una sortida major que 2MB, cal mirar
  si hi ha un fitxer `.ops` que digui `--maxoutput=XMB`, a on `X`
  és una cota superior al tamany real que té el fitxer de
  sortida. (Això és bo mirar-ho o bé a la sortida de `jtk make` o
  bé directament en els fitxers `.cor`.)

### Carpetes `public`

En els problemes tipus `PRO2` volem que cada carpeta `public`
tingui tant:

- El fitxer `.clang-format` per configurar el format del codi.
- El directori `.vscode`, que conté els fitxers `tasks.json` i
  `launch.json` que permeten compilar i debuggar en cada cas com
  faci falta, en funció de si hi ha `Makefile` o no.

### Fitxer `scores.yml`

- Que tingui més d'una secció i cadascuna tingui un prefix
  correcte que es correspòn amb els prefixos dels jocs de prova
  privats (o públics, potser).

- També que la descripció de cada secció **no doni pistes** sobre
  els jocs de prova que facin que l'estudiant pugui saber què
  s'està provant (cosa que faria el problema molt més fàcil).
