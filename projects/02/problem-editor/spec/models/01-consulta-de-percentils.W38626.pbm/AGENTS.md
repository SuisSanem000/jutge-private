- Aquest problema és una mostra d'un problema normal (driver
  `std` i `source_modifier: none`).

- Però utilitza dos paràmetres: `checker: epsilon`, i
  `epsilon: 0.02`, perquè la sortida té valors reals i cal
  comparar la sortida de la solució i l'enviament de l'estudiant
  mirant que el valor absolut de la diferència sigui menor que
  `epsilon`. Això és degut als errors de precisió que es
  produeixen en els càlculs amb nombres reals.
