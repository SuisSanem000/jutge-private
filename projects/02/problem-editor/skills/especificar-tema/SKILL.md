---
name: especificar-tema
description: |
    Habilitat que s'utilitza quan s'ha d'especificar un tema del curs, un cop es té el graf de conceptes.
    Utilitzat quan es vol "especificar un tema", "seqüenciar un tema", o "crear l'especificació d'un tema".
---

<!-- totes les referències a fitxers són començant a l'arrel del projecte -->

Llegeix la [constitució](spec/constitucio.md), que cal _complir
sempre_, en qualsevol cas, i amb la màxima prioritat.

Abans de començar, comprova que existeix la carpeta `TEMA_DIR` a
l'arrel del projecte.

1. **Comprovar que la carpeta del tema existeix**:
    - El tema que menciona l'usuari ha de tenir una carpeta a
      l'arrel del projecte, en el format: `XX-El-Nom-del-Tema`.
    - Si no existeix, cal parar i donar un missatge d'error a
      l'usuari informant de que el tema que ha indicat no
      existeix encara.
    - A la carpeta del tema li direm `TEMA_DIR`.

2. **Comprovar que tenim els fitxers necessaris**:
    - Cal comprovar que existeixen:
        1. **Els exemples canònics**: `TEMA_DIR/recerca/src`.
        2. **Les referències**:
           `TEMA_DIR/recerca/referencies.md`.
        3. **Els conceptes**: `TEMA_DIR/conceptes.md`.

Ara ja podem especificar el tema, que vol dir:

3. **Pensar l'ordre dels conceptes**:
    - Donats els pre-requisits, cal pensar una ordenació adient
      per presentar els conceptes en seqüència, de tal manera que
      es compleixi que cap concepte s'explica sense haver
      explicat els seus pre-requisits.

4. **Dividir els conceptes en teòrics o pràctics**:
    - Els conceptes teòrics són idees i tenen a veure amb el
      model mental i la comprensió.
    - Els conceptes pràctics són petites accions que cal fer i
      tècniques que cal practicar.

5. **Omplir l'especificació**:
    - Crear un fitxer `TEMA_DIR/especificació.md` omplint la
      [plantilla d'especificació](spec/templates/especificació.md)
      amb els detalls de la recerca feta, però preservant
      l'estructura indicada.

## Lista de comprovació

- [ ] S'han classificat tots els conceptes en teòrics o pràctics.
- [ ] S'han determinat els programes canònics per cada concepte.
- [ ] Tenim la llista de conceptes, per ordre.
- [ ] `TEMA_DIR/spec.md` existeix i segueix la plantilla amb el
      llistat de conceptes.
