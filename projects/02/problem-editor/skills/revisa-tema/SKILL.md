---
name: revisa-documentacio-tema
description: |
    Aquesta habilitat s'ha d'utilitzar quan l'usuari vol "revisar els documents d'un tema", 
    és a dir, revisar els apunts o bé el guió de laboratori d'un tema.
---

## Objectiu

Revisar els fitxers `APUNTS.md` i `Lab/GUIO.md` d'un tema donat,
buscant errors de tot tipus: ortogràfics, gramaticals, de
contingut tècnic, de format i d'estil.

## Context

- Els apunts estan escrits en **català**.
- El format és Markdown amb algunes extensions HTML (marques
  d'índex, `<warning>`, `<DownloadButton>`).
- Consulta l'especificació del repositori a `spec/SPEC.md` per
  entendre les convencions de format.

## Instruccions

1. Buscar la carpeta del tema, que serà CARPETA_TEMA.

2. Llegeix els fitxers `<CARPETA_TEMA>/APUNTS.md` i
   `<CARPETA_TEMA>/Lab/GUIO.md` del tema indicat per l'usuari.

3. Busca fitxers de codi en els directoris `<CARPETA_TEMA>/src` i
   `<CARPETA_TEMA>/Lab/src` i llegeix-los, perquè són adjunts al
   text i cal tenir-los presents.

4. Analitza el document sencer en tot el detall possible i
   reporta els errors trobats, organitzats per categoria.

## Categories d'errors a revisar

### 1. Ortografia i gramàtica (català)

- Faltes d'ortografia.
- Errors d'accentuació, apostrofació, guionets.
- Concordança de gènere i nombre.
- Ús incorrecte de preposicions o pronoms febles.

### 2. Contingut tècnic (C++, estructures de dades, algorismes)

- Errors en fragments de codi C++ (sintaxi, lògica).
- Explicacions tècniques incorrectes o imprecises.
- Incoherències entre el text i el codi que l'acompanya.
- Comentaris fora de lloc o equivocats.
- Trossos de codi sense comentar que són difícils d'entendre.
- Exemples posats al text que no concorden amb els fitxers
  adjunts.

### 3. Seqüenciació

- Mencions de conceptes que no s'han explicat en els apunts en
  temes anteriors. Això requereix mirar els documents de temes
  anteriors, utilitzant l'ordre dels directoris.

- Utilització d'instruccions, classes, funcions, tipus, o
  tècniques en el codi que no s'han explicat abans en el mateix
  document o en documents anteriors (tant `APUNTS.md` com
  `Lab/GUIO.md`)

### 4. Format Markdown i convencions del repositori

- Marques d'índex (`<div id="..." />`) absents o amb `id`
  duplicats.

- Títols/subtítols que no resumeixen el contingut de la secció.

- Ús incorrecte de blocs de codi (language tags, indentació).

- Elements HTML especials mal formatats (`<warning>`,
  `<DownloadButton>`).

### 5. Estil i claredat

- Frases massa llargues o confuses.
- Repeticions innecessàries.
- Transicions brusques entre seccions.
- Codi d'exemple amb:
    1. Estil confús o que es pot simplificar.
    2. Noms de variable difícils d'entendre.

## Format del report

Per a cada error, indica:

- **Línia** (aproximada): número o rang de línies.
- **Categoria**: una de les 4 categories anteriors.
- **Descripció**: què és l'error.
- **Suggeriment**: correcció proposada (si escau).

Exemple:

> **Línia 42** | Ortografia | "recursivilitat" → "recursivitat"

Al final, inclou un resum amb el nombre d'errors per categoria.
