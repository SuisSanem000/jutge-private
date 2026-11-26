- **Tipus**: PRO2
- **Centre d'interès**: Eficiència
- **Títol**: Campanya Presidencial

## Fitxers

En aquest problema no volem donar CAP pista sobre quins contenidors caldrà utilitzar, i per tant en els fitxers de la carpeta `public` hi hauria d'haver els fitxers: `stack.hh`, `queue.hh`, `heap.hh` i `assert.hh`. 

## Idea: acumular contribucions a una campanya i mostrar les tres més grans de cada donant

- Cal posar una miqueta d'història aquí dient que les eleccions presidencials dels UUEE (és una broma de EEUU) estan molt dominades pels diners, i es vol saber quins són els contribuyents que més diners han aportat.

La idea és llegir, primer un llindar de contribucions que suposen que excessives, i després un llistat de contribucions monetàries (nom d'empresa i quantitat en dòlars), i al final llistar aquelles empreses a on les tres contribucions més grans superen el llindar.

## Idea `solution.cc` 

Es tracta de posar un `map<string, Heap<int>>` i anar posant totes les contribucions que es van llegint. Al final, cal recórrer el `map` i fer `pop` 3 vegades de cada cua de prioritat, i calcular la suma d'aquestes quantitats. Si se supera el llindar, es mostra el nom de l'empresa per pantalla. Si no hi ha cap empresa, cal mostrar "eleccions netes!".


