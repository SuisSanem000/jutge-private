# Especificació dels problemes del Jutge (Jutge.org)

Els problemes del [Jutge](https://jutge.org) són problemes que
els estudiants poden resoldre de forma autònoma. Un estudiant
envia un programa que el Jutge compila i executa amb diferents
jocs de prova. Si les sortides del programa coincideixen amb les
sortides esperades i el temps d'execució no supera un cert
llindar, el programa es considera correcte. El resultat és,
doncs, un "veredicte" que indica si el programa és correcte i
eficient.

Els veredictes del Jutge més comuns són:

- `AC`, Accepted: el programa és correcte i eficient.
- `WA`, Wrong Answer: el programa no és correcte.
- `EE, time-limit exceeded`: el programa sembla correcte però no
  ha pogut executar-se en el temps donat.
- `EE, execution error`: el programa ha abortat a mitja execució
  abans d'acabar, o bé s'ha quedat sense memòria.
- `PE`, Presentation Error: la sortida és gariebé igual que
  l'esperada, excepte per espais o majúscules.

## Problemes de tipus `G++17`, `PRO2` i `MakePRO2`

El tipus d'un problema el decideix el fitxer `handler.yml` (veure
detalls més endavant). La opció més important per distingir els
problemes és `compilers`. Segons el valor de `compilers` hi ha 3
tipus de problemes:

- **`G++17`, s'envia un sol fitxer**: si `compilers` és `G++17`,
  l'enviament és un sol fitxer `.cc`, que potser es modificar,
  però que es compila individualment.

    En funció de `source_modifier` tenim:
    - `none`: un programa sencer.

    - `no_main`: una sola funció (sense programa principal), que
      es combina amb un `main.cc` en 1 sol fitxer de codi,
      compilat individualment.

    - `structs`: per problemes que necessiten `structs`
      (definicions de tipus), on es demana una sola funció (amb o
      sense programa principal), que es combina amb un `main.cc`
      en 1 sol fitxer de codi, compilat individualment.

    El fitxer de la solució és sempre `solution.cc`.

- **`PRO2` un sol fitxer que es compila amb altres**: si
  `compilers` és `PRO2`, llavors el fitxer que envia l'estudiant
  s'afegeix a un grup d'altres fitxers i es compilen tots alhora.
  Els fitxers ja preparats que l'estudiant pot descarregar per
  provar el seu programa es troben a la carpeta `public`
  (s'explica més endavant), i també `private`.

    El fitxer de la solució pot ser `solution.cc` o bé
    `solution.hh`.

- **`MakePRO2`, s'envien molts fitxers en un `.tar`**: si
  `compilers` és `MakePRO2`, s'envia tota una carpeta (en
  realitat, un `.tar`), que es compilen alhora utilitzant el
  `Makefile` que ha d'estar present al `.tar` enviat. En aquest
  cas també hi haurà fitxers preparats (típicament, que cal
  modificar), a la carpeta `public` i potser fitxers que
  l'estudiant no pot veure a `private`.

    El fitxer solució serà `solution.tar`, però aquest es crea a
    partir de la carpeta `solution` (fent el `.tar` d'aquesta).

## Estructura de la carpeta d'un problema de Jutge.org

La carpeta d'un problema amb compilador `PRO2` és la següent:

```
NN-titol-del-problema.pbm
├── handler.yml                  # Handler del problema
├── problem.yml                  # Fitxer amb metadades per fer `jtk upload`
├── problem.ca.tex               # Enunciat en català
├── problem.ca.yml               # Metadades de la versió en català
├── problem.es.tex               # Enunciat en castellà
├── problem.es.yml               # Metadades de la versió en castellà
├── solution.cc                  # Solució de l'exercici
├── public                       # Carpeta pública que es poden descarregar els estudiants
│   ├── .clang-format            # Configuració del format de C++ amb `clang-format`
│   ├── .vscode                  # Settings per compilar i debuggar amb VSCode
│   |   ├── launch.json
│   |   └── tasks.json
│   ├── ...                      # Fitxers extra
│   ├── main.cc                  # Programa principal (si el `source_modifier` és "no_main")
│   └── Makefile                 # Makefile per compilar el projecte
├── sample-1.inp                 # Joc de prova públic 1
├── sample-2.inp                 # Joc de prova públic 2
├── ...                          # ... resta de jocs de prova públics
├── generate.ts                  # Generador de jocs de prova (Typescript, amb shebang i chmod +x)
├── private-correctesa-1.inp     # Joc de prova privat 1 (correctesa)
├── private-correctesa-1.inp     # Joc de prova privat 2 (correctesa)
├── ...                          # ... resta de jocs de prova privats de correctesa
├── private-1.inp                # Joc de prova privat 1 (eficiència)
├── private-2.inp                # Joc de prova privat 2 (eficiència)
├── ...                          # ... resta de jocs de prova privats (eficiència)
└── tags.yml                     # Tags per classificar el problema
```

Els dígits `NN` són per poder posar un ordre als problemes quan
estan junts en una carpeta.

## Enunciat

L'enunciat ha de tenir les parts següents (que els exemples
segueixen força bé):

1. **Conceptes previs**: Explicar algun concepte, si és necessari
   per entendre el problema. Aquests conceptes solen necessitar
   exemples si són complexos d'entendre, amb moltes idees noves
   juntes.

2. **Explicació del problema**:
    - Si es tracta d'una funció, posar la declaració amb
      comentaris de tipus Doxygen resumint l'explicació i amb les
      precondicions a `@pre` i les postcondicions a `@post`. El
      nom de la funció ha d'estar en català i ha de representar
      perfectament el càlcul que cal fer.

    - Si es tracta d'un programa principal cal explicar què ha de
      fer el programa. En particular, quines són les entrades (i
      quines condicions compleixen) i quines són les sortides (i
      quines condicions han de complir).

    - Si els conceptes a explicar són llargs, és bona idea posar
      un **exemple**, o referirse als jocs de prova públics
      perquè el lector entengui què fa el programa o funció.
      Aquesta explicació és sobre què fa la funció o programa i
      és diferent de l'explicació de conceptes del punt 1.

3. **Observacions**: si el centre d'interès del problema és
   l'eficiència, cal dir-ho explícitament. Això cal que estigui
   indicat a la idea del problema (IDEA.md), i en el fet que els
   algoritmes utilitzats siguin cerques (com la dicotòmica),
   ordenacions, i potser la fusió ordenada.

    Les observacions sovint posen detalls de què cal enviar, i si
    el problema demana només una funció, segons el tipus de
    problema i el compilador és possible que calgui esborrar el
    `main` abans d'enviar, per exemple. Els problemes d'exemple
    tenen cassos d'aquests.

    **IMPORTANT**: En problemes tipus `PRO2` és molt un
    requeriment essencial dir què cal enviar, o sigui quin fitxer
    s'espera que l'estudiant enviï (típicament, pot ser un dels
    fitxers de la carpeta `public` modificats o bé un fitxer nou,
    ja sigui `.cc` o bé `.hh`)

4. **Descripció de l'entrada i sortida**. Per separat. Aquestes
   seccions utilitzen marques específiques i han de descriure
   l'entrada del programa i la sortida amb la major precisió
   possible.

    Encara que el problema sigui sobre només fer una funció,
    sovint les entrades i sortides són les que gestiona el
    `main.cc`, que és un fitxer públic que els estudiants es
    poden descarregar per començar.

Cal escriure els enunciats ens els 3 idiomes següents: Català
(`ca`), Castellà (`es`). L'anglès (`en`) és opcional, només cal
fer-lo si es demana explícitament.

**PARÀGRAFS**: En els fitxers `.tex`, cal posar un `\medskip`
entre els paràgrafs perquè tinguin l'espaiat correcte!

## Detalls dels diferents fitxers

### Fitxer `handler.yml`

Fitxer amb la configuració següent:

```yaml
handler: std | graphic | quiz | game
source_modifier: none | no_main
func_name: <nom de la funció> # opcional
compilers: PRO2 | MakePRO2 | G++17
```

El `handler` és, gairebé sempre, **`std`**: per a problemes on es
miren parells d'entrades i sortides (els jocs de prova). Els
altres són molt poc freqüents.

| `source_modifier` | Significat                                                                               |
| :---------------- | :--------------------------------------------------------------------------------------- |
| `none`            | El programa conté un `main` i es compila de forma normal.                                |
| `no_main`         | La solució ha de ser una funció. Cal dir el nom de la funció amb `func_name` (opcional). |

### Carpetes `public` i `private`

```
NN-titol-del-problema.pbm
├── ...
├── public           # Carpeta amb els fitxers públics (descarregables)
│   ├── classe1.cc   # Classe necessària pel problema (implementació)
│   ├── classe1.hh   # Classe necessària pel problema (declaració)
│   ├── ...          # ... altres classes necessàries pel problema
│   ├── util.cc      # Funcions auxiliars (opcional)
│   ├── main.cc      # Programa principal
│   └── Makefile     # Makefile per compilar el projecte (obligatori)
├── ...
├── private          # Carpeta amb fitxers privats (OPCIONAL)
│   ├── classe1.cc
│   ├── classe1.hh
│   ├── ...
│   ├── util.cc
│   ├── main.cc
│   └── Makefile
└── ...
```

La compilació del problema en els dos cassos és similar:
l'enviament de l'estudiant es "barreja" amb les dues carpetes
`public` i `private`.

#### Subcarpeta `.vscode`

En tots els problemes de tipus `PRO2` o `MakePRO2` volem tenir
una subcarpeta **`.vscode`** a `public` perquè els estudiants
puguin descarregar i directament compilar i debuggar amb VSCode
fàcilment. A dins d'aquesta carpeta hi ha dos fitxers
`tasks.json` i `launch.json` que defineixen les comandes per
poder compilar (ja sigui amb `Makefile` o sense) i llançar el
programa en mode debug.

### Problemes tipus `PRO2`

1. L'estudiant enviarà un sol fitxer de codi (`program.cc` o
   `program.hh`)
2. Es parteix d'una còpia de la carpeta `public`.
3. El fitxer enviat es copia a la carpeta `public`.
4. Els fitxers de la carpeta `private` sobreescriuen els de la
   carpeta `public`. Per tant, la carpeta `private` pot estar
   buida o bé sobreescriure qualsevol dels fitxers que la carpeta
   `public` (o tots).
5. Es compila el problema fent servir el `Makefile`

Per tant, el problema ha de tenir `solution.cc` o bé
`solution.hh` com a solucions.

### Problemes tipus `MakePRO2`

1. L'estudiant enviarà un fitxer `problem.tar`.
2. Es parteix d'una còpia de la carpeta `public`.
3. El fitxer `problem.tar` es descomprimeix a la carpeta `public`
   (sobreescrivint els fitxers de `public`, parcial o totalment).
4. Els fitxers de la carpeta `private` sobreescriuen els de la
   carpeta `public`. Per tant, la carpeta `private` pot estar
   buida o bé sobreescriure qualsevol dels fitxers que la carpeta
   `public` (o tots).
5. Es compila el problema fent servir el `Makefile`

Donat que l'enviament és una carpeta, la solució és també una
carpeta, de nom `solution`:

```
NN-titol-del-problema.pbm
├── ...
├── solution         # Carpeta amb la solució (només a `MakePRO2`)
│   ├── classe1.cc
│   ├── classe1.hh
│   ├── ...
│   ├── util.cc
│   ├── main.cc
│   └── Makefile
└── ...
```

En resum:

| `compiler` | Solució                                      |
| :--------- | :------------------------------------------- |
| `PRO2`     | **un fitxer**: `solution.cc` o `solution.hh` |
| `MakePRO2` | una **carpeta**: `solution`                  |

## Altres Fitxers

### Fitxer `problem.yml`

Aquest fitxer, si no existeix, vol dir que el problema mai ha
estat carregat al Jutge, per tant **no s'ha de crear mai
manualment**. Quan existeix, conté les dades del problema al
Jutge, incloent el `problem_nm` que és com un ID, i altres dades.

La **pàgina web** del problema al Jutge segueix el patró
`https://jutge.org/problems/` seguit del valor de `problem_nm`
(per exemple, si `problem_nm` és `Y52290`, l'URL és
`https://jutge.org/problems/Y52290`). Alguns problemes ofereixen
també una URL per idioma afegint el sufix `_ca`, `_es` o `_en` al
codi (per exemple `https://jutge.org/problems/Y52290_ca`). Si el
problema és privat o cal permisos, la mateixa URL pot no ser
accessible sense haver iniciat sessió amb un compte autoritzat.

### Fitxers `problem.<lang>.tex` i `problem.<lang>.yml`

Els idiomes (`<lang>`) poden ser: `ca`, `es`, `en`.

- `problem.<lang>.tex`: L'enunciat d'un cert idioma.
    - Els problemes han d'estar sempre en:
        - català (`ca`) i
        - castellà (`es`).
    - **Ordre de creació**: el·laborar l'enunciat en català
      primer (el principal), i després traduir al castellà.

- `problem.<lang>.yml`: El fitxer de configuració de cada idioma.
    - A l'idioma principal, hi ha:

        ```yaml
        title: <títol del problema en l'idioma corresponent>
        author: <nom de l'autor>
        email: <correu electrònic>
        ```

    - En les traduccions es posa:

        ```yaml
        title: <títol del problema en l'idioma corresponent>
        translator: <nom del traductor>
        translator_email: <correu electrònic del traductor>
        ```

### Fitxer `main.cc`

Present si és necessari que l'estudiant tingui codi de suport per
provar la funció que hagi de fer al seu ordinador.

- En problemes de tipus `PRO2`, aquest fitxer de suport es
  converteix en la carpeta `public`, ja que típicament no només
  hi ha el `main.cc` sinó que també hi ha altres fitxers i potser
  un `Makefile`.

### Solució

- `solution.cc`: El fitxer amb la solució al problema, tal com
  l'hauria d'enviar un estudiant.

- `solution-*.cc`: El fitxer d'una potencial solució incorrecta o
  alternativa que potser un estudiant podria enviar. Aquesta
  solució no passaria els jocs de prova del jutge ja sigui per
  incorrectesa en jocs de prova, o bé perquè és ineficient amb
  respecte la solució de referència (`solution.cc`). En `N` del
  nom és pel fet que pot haver-hi vàries possibles solucions
  dolentes i llavors, un comentari dins del codi explica perquè
  aquella solució no és bona. El nom del fitxer pot tenir, a la
  part marcada amb `*`, alguna descripció curta per recordar
  quina solució "dolenta" és. També pot haver-hi solucions
  equivalents a la bona que també es vol veure que tenen la
  mateixa eficiència.

### Jocs de prova

- `sample-N.inp`: Fitxer de joc de prova **públic**. Aquest joc
  de prova es passa com a entrada al programa per crear una
  sortida (que es grava a `sample-1.cor`), i que representa un
  cas senzill de llegir per entendre què fa el programa.
  Normalment aquests jocs de prova són curts i si tenen més d'un
  cas, són cassos amb molt poca entrada perquè resultin fàcil
  d'entendre.

- `private-*.inp`: Fitxer de joc de prova **privat**.

    **⚠️ No llegeixis MAI aquests fitxers! ⚠️**

    Aquests fitxers es generen amb un script (`generate.ts`) ja
    que seria molta feina crear-los a mà. El _script_ produeix
    jocs de prova de diversos tipus i produeix aquests fitxers
    per testar aspectes de la correctesa o l'eficiència del
    problema. El nom del fitxer sol explicar, en una paraula, de
    quin joc de prova es tracta.

    Els jocs de prova privats solen tenir una estructura com:
    1. Si el problema permet generar totes les combinacions
       possibles per cassos de certa longitud petita, llavors els
       jocs de prova de correctesa han de generar exhaustivament
       totes les combinacions.

    2. A partir d'aquí, per a jocs de prova més grans (o sigui
       tamanys de les seqüències de 1000, 10000, fins a
       1_000_000), cal tenir en compte el tamany del fitxer
       resultant. És bona idea generar jocs de prova
       d'aproximadament 1MB, per exemple, i generar `N` cassos
       amb `M` elements cadascún (si es tracta de seqüències o
       vectors) de tal manera que `N * M` produeixi un fitxer de
       1MB, més o menys. A vegades, però, per poder testar
       l'eficiència i produir un error de tipus "time-limit
       exceeded" en el Jutge, és necessari fer jocs de prova més
       llargs i per tant cal fer servir fitxers `.ops`
       (mencionats al punt següent), per augmentar el límit de la
       sortida, ja que sovint la sortida és proporcional a
       l'entrada.

- `private-*.cor`: Els resultats d'haver executat els jocs de
  prova privats, és a dir, la sortida del programa solució en
  cada cas. És important mirar si els `*.cor` són a un fitxer
  `.gitignore` a la carpeta pare o més amunt, perquè no haurien
  d'estar al repositori.

#### Solucions "lentes"

En problemes amb centre d'interès d'**eficiència**, es necessita
una "solució lenta" del problema, és a dir, una implementació que
faria algú que encara no ha copsat com fer el problema eficient,
però que, excepte per l'eficiència, és correcte. Les sortides,
per tant, han de ser les mateixes, i l'únic que canvia és el
temps d'execució.

Per exemple, si un algorisme és $O(n·log n)$, la versió lenta
s'ha de fer $O(n²)$, i si la solució és $O(log n)$, llavors la
versió lenta hauria de ser $O(n)$.

- **Verificació de la solució lenta**: Amb la "solució lenta" es
  pot fer un `jtk verify` (consultar amb `--help` per veure les
  opcions) i mesurar els temps que dóna per poder comparar amb la
  solució ràpida.

- **Factor d'almenys 5x**: La diferència en temps d'execució de
  la solució lenta i la ràpida hauria de ser d'un factor 5, és a
  dir, la solució lenta triga un temps 5 vegades més gram.

- **Canvis en els jocs de prova**: si la diferència entre la
  solució ràpida i la lenta no és prou gran, cal canviar els
  paràmetres utilitzats en el generadors de jocs de prova perquè
  siguin suficientment grans per discernir la solució lenta de la
  ràpìda.

### Fitxer `scores.yml`: avaluar independentment l'eficiència de la correctesa

En problemes d'eficiència, cal avaluar independentment la part de
correctesa de la part d'eficiència. Si un problema és correcte
però no eficient, pot tenir com a màxim una nota de 5.

- El fitxer `scores.yml` conté els grups de jocs de prova
  (agrupats pel prefix del nom del fitxer `.inp`), que es
  consideren com una part de les proves i donen una quantitat de
  punts en conjunt.

- La quantitat total de punts dels diferents grups de jocs de
  prova hauria de sumar 10 punts. Els punts, a més, han de ser
  nombres enters, no poden tenir decimals.

- En els jocs de prova d'eficiència, al ser molt grans, cal tenir
  proves variades i incloure proves que ja s'han posat en els
  jocs de prova més petits, perquè el mecanisme dels `scores.yml`
  executa cada secció dels jocs de prova independentment, i per
  tant podria passar que un joc de proves d'eficiència s'accepti
  en un programa que és erroni, simplement perquè té massa pocs
  casos.

#### Inclusió de jocs de prova de correctesa en els d'eficiència

Donat que els jocs de prova d'eficiència només haurien de donar
verd si passen els de correctesa (per sentit comú), però el
fitxer `scores.yml` implica que cada grup de tests és
independent, pot passar que un programa erroni tingui la sort de
passar els d'eficiència perquè dóna la solució correcta (com sí o
no) sense haver fet el càlcul realment.

Per evitar això, el que caldria és fer "parts" en els
`scores.yml` però de tal manera que els jocs de prova
d'eficiència sempre incloguin tots els de correctesa. Per fer
això, tenim les següents maneres:

1. Que el prefix dels d'eficiència inclogui els de correctesa.
   Per exemple, si tenim els fitxer següents:

    ```
    private-correctesa-1.inp
    private-correctesa-2.inp
    private-correctesa-3.inp
    private-1.inp
    private-2.inp
    private-3.inp
    ```

    i posem dos grups com:

    ```yaml
    - part: Correctesa
      prefix: private-correctesa-
      points: 5
    - part: Eficiència
      prefix: private-
      points: 5
    ```

    Com es pot veure, els 3 primers jocs de prova compleixen que
    tenen el prefix `private-correctesa-`, que inclou els 3
    primers jocs de prova, i després els d'eficiència inclouen
    tots 6, fitxers, perquè tots 6 tenen el prefix `private-`.

2. Si la tècnica de posar un prefix no es pot utilitzar (perquè
   la relació entre els de correctesa i eficiència és més
   complexa), cal copiar els jocs de prova de correctesa amb el
   prefix dels jocs de prova d'eficiència. Això fa que s'executin
   dos cops.

#### Paràmetres d'execució de cada joc de prova (`private-*.ops`)

Quan un joc de proves és molt llarg i la solució genera també una
sortida llarga, és necessari posar un fitxer `.ops` que afegeix
opcions al jutge perquè augmenti els límits d'execució amb
respecte al temps o el tamany de la sortida. Les dues opcions
típiques són:

- `--maxoutput=N`, necessària quan la sortida (el fitxer `.cor`
  associat al joc de proves), és més gran que 2MB, i indica que
  la sortida màxima serà de `N` MB, en comptes dels 2MB per
  defecte.

- `--maxtime=S`, necessària quan el temps d'execució supera els 2
  segons, i permet allargar el límit d'execució d'aquest joc de
  proves a `S` segons, en comptes dels 2 segons per defecte.

El fitxer `private-*.ops` ha de tenir _exactament_ el mateix nom
que el joc de prova que està configurant, excepte per l'extensió
(`.ops` en comptes de `.inp`). D'aquesta manera el Jutge sap
quines opcions aplicar a cada joc de proves (si n'hi ha). Per
altra banda, les opcions `--maxoutput` i `--maxtime` cal
posar-les en una sola línia (la primera del fitxer), i si
apareixen les dues, cal posar un espai entremig, perquè són
opcions que es posaran a la línia de comandes per llençar el
programa que fa el processat de cada joc de proves dins del
Jutge.

#### `generate.ts`: Generador de jocs de prova

El generador de jocs de prova és un programa en Typescript, fent
servir [Bun](https://bun.com/). Aquest és l'_script_ que genera
els jocs de prova `private-*.inp` mencionats abans. Té un "shebang":

```
#!/usr/bin/env bun
...
```

i també cal posar-li el bit d'execució amb `chmod +x ./generate.ts`.

Aquest script hauria de tenir diferents funcions per generar cada
joc de proves, a on cada funció té paràmetres que permeten
controlar el tamany dels jocs de prova o el número d'instàncies
d'una entrada que hi ha, a més del nom del fitxer que cal
escriure.

Per exemple, en un _script_ `generate.ts` sobre arbres binaris
podria haver-hi, al final:

```ts
// tots els arbres d'alçada 2
await generaArbresExhaustiu(`private-correctesa-1-arbres-petits.inp`, 2)

// mostra d'arbres mitjans (alçada 10, 100 arbres)
await generaArbresMitjans(`private-correctesa-2-mitjans.inp`, 10, 100)

// mostra d'arbres grans (alçada 250, 10 arbres)
await generaArbresGrans(`private-arbres-grans.inp`, 250, 10)
```

que generaria 3 jocs de proves privats amb arbres de diferents
tamanys i diferents quantitats.

- **IMPORTANT**: Sempre que es crear un script `generate.ts`,
  cal cridar-lo per generar els jocs de prova _abans_ de fer
  `jtk make`, ja que la compilació del problema provarà la
  solució amb tots els jocs de prova i generarà els fitxer
  `.cor`.

### Fitxers `.cor` de més de 2MB

Si la sortida d'un programa supera els 2MB en un joc de prova,
cal escriure, al costat del joc de proves que supera aquest
tamany, un fitxer `.ops`. Aquest fitxer ha de tenir el mateix nom
que el joc de prova però canviant l'extensió de `.inp` a `.ops`.
Per exemple, si el joc de prova es diu
`private-3-sequencies-llargues.inp`, llavors el fitxer `.ops`
serà `private-3-sequencies-llarges.ops`.

El contingut del fitxer ha de ser:

```bash
--maxoutput=XX
```

a on `XX` és el nombre de megabytes màxim que se li permet al
programa a la sortida. Aquest límit ha de **superar**, i amb una
mica de marge, el tamany del fitxer `.cor` que s'ha generat al
fer `jtk make`. La pròpia sortida de la comanda mostra els
tamanys i si no és suficient amb fer un `ls` amb els paràmetres
adequats per veure quins fitxers `.cor` superen els 2MB.

## Com es compila un problema

Cal tenir instal·lada una utilitat anomenada New Jutge Toolkit,
de nom `jtk` per la línia de comandes.

- `jtk make`: compila un problema, i cal estar a la carpeta del
  problema. Això genera un informe força exhaustiu sobre què ha
  passat en cada fase (compilació de la solució execució dels
  jocs de prova, generació dels enunciats en diferents formats,
  etc.).

- `jtk clean`: permet esborrar fitxers intermitjos, ja que se'n
  generen bastants. Si es fa `jtk clean -af` s'esborren tots els
  fitxers intermijos possibles i no es pregunta, s'esborren
  incondicionalment.

## Sempre `jtk make` per verificar

Sempre, després d'editar els problemes, cal executar `jtk make` a
la carpeta del problema per verificar que els canvis no generen
errors de compilació en el codi o errors al compilar els
enunciats en LaTeX, etc.

## Problemes d'exemple (models de referència)

Hi ha models de problemes que es poden utilitzar com a inspiració
per crear nous problemes. Cal llegir aquestes carpetes en funció
del problema que s'hagi de crear o modificar per veure com estan
estructurats.

### `G++17`

| Carpeta                                                                     | `driver` | `compilers` | `source_modifier` |
| --------------------------------------------------------------------------- | -------- | ----------- | ----------------- |
| [Consulta de Percentils](/spec/models/01-consulta-de-percentils.W38626.pbm) | `std`    | `G++17`     | `none`            |
| [Nombres Bicolor](/spec/models/02-nombres-bicolor.T80784.pbm)               | `std`    | `G++17`     | `no_main`         |
| [Llista de Parelles](/spec/models/06-llista-de-parelles.U77364.pbm)         | `std`    | `G++17`     | `no_main`         |

### `PRO2`

La taula següent llista problemes de tipus `PRO2`, que poden
servir de model:

| Carpeta                                                                                           | `driver` | `compilers` |
| ------------------------------------------------------------------------------------------------- | -------- | ----------- |
| [Ordenació per Selecció](/spec/models/03-ordenacio-seleccio.S54195.pbm)                           | `std`    | `PRO2`      |
| [Camí més llarg en un arbre binari](/spec/models/04-cami-mes-llarg-en-un-arbre-binari.V22704.pbm) | `std`    | `PRO2`      |
| [Imprimir expressions](/spec/models/05-imprimir-expressions.Z14339.pbm)                           | `std`    | `PRO2`      |
| [Guanyadors](/spec/models/07-guanyadors.S92412.pbm)                                               | `std`    | `PRO2`      |

### `MakePRO2`

Encara no hi ha exemples de problemes de tipus `MakePRO2`, si et
cal crear-ne un, demana a l'usuari que et posi un model a
`spec/models`.

## Llista de comprovació

Abans de donar un problema per fet comprova tot això:

- [ ] El generador de jocs de prova té funcions separades per
      cada fitxer que genera.
- [ ] Les funcions del generador tenen paràmetres per controlar
      els tamanys.
- [ ] Els jocs de prova s'han generat invocant el generador i són
      més recents que el propi generador.
- [ ] Si hi ha `scores.yml`, les puntuacions són enteres i
      sumen 10.
- [ ] Si hi ha parts de `scores.yml` per eficència, els jocs de
      prova tenen prou varietat de sortides.
- [ ] S'ha utilitzat `jtk verify` per comprobar que la solució
      "lenta" triga almenys 3x més que la ràpida.
- [ ] L'enunciat menciona què cal enviar i quins fitxers es
      proporcionen.
- [ ] La carpeta `public` conté els fitxers que es mencionen en
      l'enunciat.
- [ ] La versió castellana de l'enunciat realment és una
      traducció directa del català (és gairebé idèntica en
      contingut).
- [ ] S'ha comprovat que els fitxers `.cor` de tamany >2MB
      tinguin un fitxer `.ops`.
- [ ] El codi de `public` conté exactament la mateixa declaració
      que surt a l'enunciat en totes les seves versions.
- [ ] El problema s'ha compilat i no conté ni tan sols "warnings"
      del compilador.
- [ ] A la carpeta `public` hi ha una subcarpeta `.vscode` que
      conté els fitxers a punt per compilar el programa i
      debuggar-lo.
