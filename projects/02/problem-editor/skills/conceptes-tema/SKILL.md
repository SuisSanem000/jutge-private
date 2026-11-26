---
name: conceptes-tema
description: |
    Aquesta habilitat es fa servir si l'usuari vol "destilar un tema", 
    "catalogar els conceptes d'un tema", "extreure els conceptes d'un tema", 
    o "crear el graf de conceptes d'un tema". És típic fer-la servir quan s'ha 
    fet la recerca del tema.
---

<!-- totes les referències a fitxers són començant a l'arrel del projecte -->

Llegeix primer la [constitució](spec/constitucio.md), que cal
complir sempre, en qualsevol cas, i amb la màxima prioritat.

Per poder determinar els conceptes d'un tema, primer cal tenir
els **programes clau** del tema.

1. **Comprovar que la carpeta del tema existeix**:
    - El tema que menciona l'usuari ha de tenir una carpeta a
      l'arrel del projecte, en el format: `XX-El-Nom-del-Tema`.
    - Si no existeix, cal parar i donar un missatge d'error a
      l'usuari informant de que el tema que ha indicat no
      existeix encara.
    - A la carpeta del tema li direm `TEMA_DIR`.

2. **Determina si tenim els programes clau**:
    - Cal comprovar que existeixen almenys 15 fitxers a la
      carpeta `TEMA_DIR/src`, amb exemples de codi sobre el tema.
    - Si no existeixen, cal parar i donar un missatge d'error a
      l'usuari informant de que no tenim prou material per
      determinar els conceptes del tema.

Assegura't del següent per continuar:

- [ ] Hem comprovat que tenim almenys 15 fitxers a
      `TEMA_DIR/src`, amb exemples de codi diferents i ben
      variats.

---

Llegint el codi font de `TEMA_DIR/src`, cal fer un llistat
exhaustiu dels conceptes que es fan servir i s'utilitzen en tot
el material.

3. **Definir els conceptes**:
    - Cada exemple tractarà, possiblement, conceptes diferents.
      Per a cada exemple de codi cal mirar quins conceptes
      utilitza.
    - Després, cal fer la unió de tots els conceptes en una sola
      llista general, eliminant les repeticions.
    - També cal determinar quins conceptes depenen de quins
      altres, és a dir, quins pre-requisits té cada concepte.
    - Finalment, cal tenir present de quins exemples canònics
      prové cada concepte.

4. **Pensar l'ordre**:
    - Donats els pre-requisits, cal pensar una ordenació adient
      per presentar els conceptes en seqüència, de tal manera que
      es compleixi que cap concepte s'explica sense haver
      explicat els seus pre-requisits.

5. **Omplir el fitxer de conceptes**:
    - Crear un fitxer `TEMA_DIR/conceptes.md` omplint la
      [plantilla de conceptes](spec/templates/conceptes.md) amb
      la llista de conceptes pensada, però preservant
      l'estructura indicada.

Assegura't d'haver fet el següent:

- [ ] De cada fitxer a `TEMA_DIR/src` s'ha determinat quins
      conceptes utilitza.
- [ ] S'han posat els conceptes en comú i s'han eliminat les
      repeticions.
- [ ] De cada concepte s'ha determinat quins pre-requisits té.
- [ ] De cada concepte s'ha determinat quins exemples canònics
      prové.
- [ ] S'ha creat un nou fitxer `TEMA_DIR/conceptes.md` amb la
      llista de conceptes, els seus pre-requisits i els exemples
      canònics.
