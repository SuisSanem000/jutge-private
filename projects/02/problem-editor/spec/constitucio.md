## Didàctica de la programació

Tot el material ha de ser estricte amb respecte als següents
punts, perquè són crítics:

- **L'eficiència**: Un programa que té instruccions supèrflues i
  realitza càlculs innecessaris no és acceptable.
    - **Cerques**: si un algorisme no ha de recórrer tots els
      elements d'una seqüència per donar el resultat, _no ho ha
      de fer_. És un error garrafal no abandonar una iteració si
      per donar el resultat correcte no cal fer-ho.

- **L'elegència**: El codi ha de ser simple, però no comprimit ni
  críptic, els noms de variables han de ser entenedors però
  tampoc massa llargs. Cal minimitzar constantment l'esforç
  mental per llegir programes.

- **Consistència**: Tot el codi ha de ser del mateix estil, no hi
  ha d'haver parts amb estils diferents. L'estil ha de ser molt
  homogeni en tota la documentació.

## Estàndard de C++

L'estàndard de C++ que es fa servir és el C++17. Tot i això,
posem aquí una taula de les característiques que es fan servir i
quines no:

| Característica            | S'utilitza?                               |
| ------------------------- | ----------------------------------------- |
| `auto`                    | SÍ                                        |
| `enum`s                   | NO                                        |
| `typename` en `template`  | SÍ, però molt infreqüentment              |
| `for (... : ...)`         | Només en strings i vector de tipus bàsics |
| Literals amb UTF-8        | NO                                        |
| lambdas `[](...) { ... }` | NO                                        |
| `constexpr`               | NO                                        |
| `std::string_view`        | NO                                        |
| `std::unordered_map`      | NO                                        |
| `std::variant`            | NO                                        |
| _Destructuring_           | NO                                        |
| Excepcions                | NO                                        |

En certs problemes de contenidors, però sempre segons sigui
necessari per al problema, es pot necessitar l'`operator<` per
poder comparar elements d'un contenidor. Per exemple, en un
`Heap<T>`, i també en un `map<K,V>` o `set<K>`. Apart d'aquest,
en general no farem servir cap més `operator` perquè és un tema
més avançat.

## Conceptes

Un concepte és una idea que es pot explicar en 10 o 12 minuts,
aportant exemples positius i negatius. Els conceptes solen tenir
pre-requisits, que són altres conceptes. Si els pre-requisits no
es tenen, el concepte no es pot entendre bé.

Un concepte pot ser:

- Una nova estructura de dades.
- Una tècnica aplicable en certs problemes.
- Una idea per resoldre cert tipus de problemes.
- La forma de demostrar o entendre per què una tècnica o idea és
  millor que una altra.
- Un tipus d'instrucció o construcció del llenguatge.
- Una funció o mètode de la llibreria estàndard i el context a on
  és útil.

Una seqüència de conceptes explicats té un ordre especial:

1. Cada cop que s'explica un concepte, s'han hagut d'explicar
   abans tots els pre-requisits.
2. Quan es demostra el concepte, cal fer-ne variacions petites
   per demostrar què és fix i què és variable.
3. Opcionalment, també es pot explicar, per contraposició, idees
   que no compleixen amb el concepte, i comparar-les amb aquest.

Els conceptes formen un graf acíclic dirigit, on les arestes
indiquen pre-requisits. Aquest graf sempre ha de ser la llavor
dels objectius d'un curs. A partir dels conceptes que es vol
aconseguir que els estudiants aprenguin, es dedueix la resta.

### Estimació de durada

- En una sola sessió de teoria, de 2h, es poden explicar
  aproximadament 10 conceptes, com a màxim.

Duració típica de les activitats:

- Lectura d'apunts d'un tema: 1h.
- Guió de sessió de laboratori: 3h a 6h.
- Pregunta de test: ~1 minut.
- Exercici: ~10 minuts.
- Problema: ~1h.

## Creació de temes

Els passos típics per crear un tema són:

1. Fer recerca sobre el tema (`TEMA_DIR/recerca`).
2. Extreure els programes clau (exemplars) del tema
   (`TEMA_DIR/src`).
3. Extreure el graf de conceptes del tema
   (`TEMA_DIR/conceptes.md`).
4. Crear una especificació del tema, amb la millor seqüència de
   conceptes possible (`TEMA_DIR/especificacio.md`), i amb un
   esboç del guió.
5. Generar el material del tema a partir de l'especificació, els
   programes clau, i el graf de conceptes.

## Documents

Els documents de qualsevol tipus, com ara apunts, guions de
laboratori, exercicis, problemes, preguntes de test, etc. han
d'estar tots en **català**.

La prosa és de tipus informal, sense arribar a ser col·loquial.
El to és amicable i de tant en quant està bé posar exclamacions,
emojis (com ara 😄, 😉, o 🤓). Els documents poden tenir petites
bromes, per fer el contingut més entretingut. Per altra banda, en
els exemples hi ha d'haver, sovint, algun tipus de tema secundari
divertit, o bé un tipus d'"easter egg" que faci que es generi
interès per llegir l'exemple.

Tots els documents han d'explicar d'una forma concisa i anar al
grà, i tenir com a objectiu la comprensió del lector. Sempre cal
usar petits trossos de codi per il·lustrar cada punt.

## Codi font

Els fitxers de codi font han de complir:

- **noms de funcions**: anglès o català.
- **comentaris**: català.
- **entrada/sortida**: català.

En C++ l'extensió dels fitxers de codi font és `.cc`, i la dels
arxius de capçalera és `.hh`.

Quan es defineix una funció que l'alumne ha de desenvolupar,
l'especificació de la funció ha d'anar en un comentari de tipus
Doxygen, amb una descripció concisa i, si és necessari, amb
`@pre` i `@post`, per pre-condicions i post-condicions.

El codi font s'ha de formatar amb `clang-format` (hi ha una
configuració a `.clang-format`, a l'arrel del projecte).

## Públic objectiu

El públic del material són estudiants de capacitat variable, i
per tant el material troncal ha de pensar en l'estudiant mitjà.
Alhora, cal tenir material extra de més complexitat o nivell més
alt perquè aquells estudiants d'una major capacitat tinguin
formes d'aprofundir. Tanmateix, el material més difícil ha de
tenir algun tipus de marca que indiqui que és material extra.
