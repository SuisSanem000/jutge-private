---
name: exemples-canonics
description: |
    Aquesta habilitat es fa servir si l'usuari vol obtenir els 
    "exemples canònics" d'un tema, o els "programes canònics" d'un tema.
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

2. **Determina si s'ha fet la recerca del tema**:
    - Cal comprovar que existeixen els fitxers:
        - [ ] `TEMA_DIR/recerca/src`
        - [ ] `TEMA_DIR/recerca/referencies.md`
        - [ ] `TEMA_DIR/recerca/qüestionaris.md`
        - [ ] `TEMA_DIR/recerca/problemes.md`
        - [ ] `TEMA_DIR/recerca/exercicis.md`
    - Si no existeixen, cal parar i **donar un missatge d'error**
      a l'usuari informant de que encara no s'ha fet la recerca
      del tema i per tant no es pot continuar.

---

Llegint cada un dels fitxers de codi de `TEMA_DIR/recerca/src`,
els passos són:1

3. **Llistar tècniques que es fan servir**:
    - Cada exemple pot tenir vàries parts, i ser molt complex.
      Volem fixar-nos en cada part i en quin principi utilitza.
    - Per a cada exemple, hi haurà parts que estan relacionades
      amb el tema i altres que no tant. És important identificar
      aquelles parts rellevants per al tema i que ajuden a un
      estudiant a progressar en el tema.
    - Si el llistat de tècniques, idees o principis no està entre
      15 i 20, el tema no té el tamany adequat:
        - Si és massa curt, cal avisar l'usuari i parar.
        - Si és massa llarg, també cal avisar l'usuari i parar.

4. **De cada tècnica o idea, escriure un exemple perfecte**:
    - Un exemple perfecte és un exemple que:
        - És correcte i funciona. En particular, es pot compilar
          i executar sense errors.
        - És simple i fàcil de comprendre perquè només ilustra un
          concepte o idea.
        - Té comentaris en punts clau per ajudar a la comprensió.
        - Tot allò que no és estrictament necessari per entendre
          el concepte o idea ha estat eliminat. Es diu que un
          exemple d'aquests no té "complexitat accidental".
    - Per a cada concepte, idea, tècnica o principi, cal escriure
      un exemple perfecte en un fitxer que tingui un nom curt
      (entre 2 i 4 paraules) escrit en "kebab-case".
    - Els fitxers s'han de posar a la carpeta
      `TEMA_DIR/exemples`.

Assegura't d'haver fet el següent:

- [ ] De cada fitxer a `TEMA_DIR/recerca/src` s'ha determinat,
      per parts, quines idees, tècniques o principis utilitza.
- [ ] De cada idea, tècnica o principi s'ha escrit un exemple
      perfecte a la carpeta `TEMA_DIR/exemples`. Cadascún d'ells
      és:
    - [ ] Curt i simple.
    - [ ] Es pot compilar i executar sense errors.
    - [ ] Només ilustra un concepte o idea.
    - [ ] Té comentaris en punts clau per ajudar a la comprensió.
- [ ] Hi ha, aproximadament, entre 15 i 20 exemples a la carpeta
      `TEMA_DIR/exemples`.
