---
name: extreure-esquelet
description: |
  Extreure l'esquelet (o resumir els punts clau) d'un tema és comprimir
  un document d'`APUNTS.md` d'un tema del curs en un fitxer `ESQUELET.md` 
  que conté les idees darrere de cada part del document, per tant l'essència.
---

## Relació entre `ESQUELET.md` i `APUNTS.md`

L'`ESQUELET.md` (al que anomenarem esquelet) i els `APUNTS.md`
(als que direm "apunts") estan relacionats, ja que l'esquelet és
un resum molt comprimit dels apunts. Per extreure l'esquelet, cal
llegir apunts i resumir moltíssim cada punt, però mantenint la
seqüència i certs detalls clau. Si l'`ESQUELET.md` està prou ben
fet, un expert pot llegir-lo i crear els apunts de nou, perquè
pot entendre'n el sentit i reomplir els detalls que falten.

## Subtítols

Els subtítols del document apunts tots són ja un resum del tema,
per tant cal començar incloent els títols i subtítols a
l'esquelet. L'esquelet tindrà una llista de punts com:

```md
- Les girafes són mamífers.
  - Els humans són mamífers.
- Els cocodrils són rèptils.
- Les orenetes són aus.
```

que provenen dels títols del fitxer apunts

```md
## Les girafes són mamífers

### Els humans són mamífers

## Els cocodrils són rèptils

## Les orenetes són aus
```

Per tant, el nivell dels súbtítols determina el nivell dels punts
de la llista a l'`ESQUELET.md`. Els textos i exemples que van
entremig d'aquests títols s'han d'intercalar entre els punts
provinents de títols i subtítols a l'`ESQUELET.md`.

## Textos

En els textos, cal resumir d'una forma molt agressiva, a
l'esquelet mai pot haver-hi paràgrafs, només frases. A més, se
suposa que la persona que llegeix l'esquelet coneix el tema i sap
a què ens referim i podria reconstruir el document a partir de
l'esquelet.

Una explicació als apunts com

```md
Les dues marques `public:` i `private:` afecten als membres
declarats a sota, fins que no aparegui alguna altra marca que ho
contradigui. En particular, en la declaració que hem fet,
`private:` afecta als camps de dades `hores`, `minuts`, i
`segons`, i `public:` afecta a tots els mètodes.
```

esdevindrà

```md
- Marques `public` i `private`. Efecte sobre l'exemple del
  `Rellotge`.
```

## Exemples

En els exemples de codi passa semblant, per descriure un exemple,
simplement es menciona de forma breu. Amb el codi:

```c++
#include "rellotge.hh" // Declaració de Rellotge
#include <iostream>
using namespace std;

int main() {
    int segons;
    Rellotge r;
    while (r.llegeix()) {
        cin >> segons;
        r.avansa(segons);
        r.escriu();
        cout << endl;
    }
}
```

la frase pot ser

```md
Exemple sobre una seqüència de rellotges que avancem un número de
segons, usant la classe `Rellotge`.
```

Un altre exemple seria:

```c++
Rellotge r;
r.hores = 25;      // ERROR: `hores`  és privat
r.minuts = 1007;   // ERROR: `minuts` és privat
r.segons = -90922; // ERROR: `segons` és privat
```

on la frase seria:

```md
Exemple que declara un `Rellotge` i intenta accedir als seus
camps provocant errors d'accés.
```

## Comprovacions

Un cop es té l'esquelet és bo revisar si l'esquelet realment
conté tots els punts que apareixen als apunts, per no deixar-se
res. També és bo repassar la seqüència exacte, per comprovar que
és la mateixa en els dos documents.
