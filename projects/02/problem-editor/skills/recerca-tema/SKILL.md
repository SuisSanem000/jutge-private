---
name: recerca-tema
description: |
    Recercar material per a un tema nou del curs, donada una breu descripció dels conceptes centrals.
---

<!-- totes les referències a fitxers són començant a l'arrel del projecte -->

Llegeix primer la [constitució](spec/constitucio.md), que cal
complir sempre, en qualsevol cas, i amb la màxima prioritat.

1. **Generar un nom de la carpeta**:
    - Segons la descripció, cal pensar un títol, en majúscules.
    - Cal transformar-lo en "kebab-case", però preservant les
      majúscules. Per exemple:
        - "Arbres Binaris i Recursivitat" ->
          `Arbres-Binaris-i-Recursivitat`
    - Cal determinar el seu índex:
        - Si l'usuari indica l'ordre, s'utilitza aquest:
            - Si ja existia un tema en aquella posició, llavors
              cal reordenar els temes posteriors, desplaçant-los
              1 número més amunt, començant pel que tenia l'ordre
              desitjat.
        - Si l'usuari no indica l'ordre, llavors cal posar-lo al
          final.
    - El format complet de la carpeta és: `XX-El-Nom-del-Tema`
      (li direm `NOM_TEMA`)

2. **Crear la carpeta del tema**:
    - Cal crear la carpeta `NOM_TEMA` a l'arrel del directori.

Ara es tracta de recopilar molt de material de diverses fonts,
sempre buscant exemples de codi.

3. **Fer recerca**: Cal recopilar:
    - **Articles**: Articles curts que parlin sobre el tema, amb
      exemples de codi intercalats.
    - **Documentació**: Cal buscar la documentació oficial sobre
      el tema a la web.
    - **Programes**: Cal buscar programes (a GitHub, per
      exemple), que facin servir les estructures de dades del
      tema o les tècniques que el tema vol explicar.
    - **Problemes**: Cal buscar col·leccions de problemes sobre
      el tema i veure si aquests problemes tenen solucions amb
      codi per obtenir-les.
    - **Exercicis**: Cal anar a pàgines web amb exercicis sobre
      el tema i si és possible obtenir les solucions en forma de
      codi.
    - **Qüestionaris**: Cal anar a pàgines web amb qüestionaris
      sobre el tema.

4. **Arxivar** tot el que s'ha trobat:
    - Codi font a `NOM_TEMA/recerca/src`. Per a cada programa
      trobat cal posar, com a comentari en el codi, la URL de la
      font.
    - Articles i documentació a
      `NOM_TEMA/recerca/referencies.md`.
    - Els problemes a `NOM_TEMA/recerca/src`, posant l'enunciat
      del problema com a comentari dins del codi. Amb els
      exercicis cal fer el mateix.
    - Les preguntes de qüestionari a
      `NOM_TEMA/recerca/qüestionaris.md`.
    - Els problemes a `NOM_TEMA/recerca/problemes.md`.
    - Els exercicis a `NOM_TEMA/recerca/exercicis.md`.

## Fonts interessants per fer la cerca

- Google.
- GitHub (cerca per repositoris i a dins, pel codi).
- Per a C++: `https://cppreference.com`.
- Lliçons de Jutge.org: `https://lliçons.jutge.org`.

## Lista de comprovació

- [ ] Carpeta `NOM_TEMA` existeix.

- [ ] `NOM_TEMA/recerca/src` existeix i conté almenys 30 fitxers
      de codi font amb exemples diversos. Cada fitxer:
    - [ ] Ha de ser un programa que es pugui compilar i executar.
    - [ ] Ha de tenir un comentari a la capçalera amb:
        - [ ] la URL de la font.
        - [ ] nom descriptiu.
        - [ ] comentari que expliqui el seu funcionament.
        - [ ] comentari que expliqui quins conceptes utilitza.
        - [ ] si és un problema: l'enunciat del problema.
        - [ ] si és un exercici: l'enunciat de l'exercici.

- [ ] `NOM_TEMA/recerca/referencies.md` existeix i conté almenys
      30 referències a documentació, articles, etc.

- [ ] `NOM_TEMA/recerca/qüestionaris.md` existeix i conté almenys
      15 preguntes sobre el tema.

- [ ] `NOM_TEMA/recerca/problemes.md` existeix i conté almenys 5
      problemes sobre el tema.

- [ ] `NOM_TEMA/recerca/exercicis.md` existeix i conté almenys 10
      exercicis sobre el tema.
