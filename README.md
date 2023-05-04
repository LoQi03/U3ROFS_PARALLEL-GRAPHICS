# U3ROFS_PARARELL-GRAPHICS

## Pararell beadandók:

### PARARELL/1.beadandó

***Téma:*** Quick Sort
***Leírás:***
A program vár 2 paramétert: egy "n" értéket, és egy "threads_count" értéket. Az első bemeneti paraméter az, hogy mennyi számot generáljon a program, a második paraméter pedig az, hogy hány szálon végezze el az algoritmus. Az algoritmus a tömb elemeit résztömbökre osztja, majd a résztömbök elemeit összehasonlítja egy "pivot" értékkel, majd azokat a résztömböket rendezni, amelyekben az elemeik kisebbek vagy nagyobbak a pivotnál. A program ezen kívül tartalmaz egy párhuzamosított verziót is, amelyben a munkát több szál végzi el egyszerre.

 ***Futtatás:***   ./main {N} {threads_count}

 ***Mérések:*** 

### PARARELL/2.beadandó

***Téma:*** Taylor sorbafejtés
***Leírás:*** 
A program vár három bemeneti paramétert: egy lebegőpontos "x" értéket, egy egész "n" értéket és egy egész "thread_count" értéket. Az első bemeneti paraméterre a cos, sin és exp függvények számítása során lesz szükség, a második bemeneti paraméter pedig meghatározza, hogy hány tagot kell számolni a Taylor sorozatokban. A harmadik bemeneti paraméter a párhuzamosított számítások száma, amelyeket a "cos_taylor", "sin_taylor" és "exp_taylor" függvényekben hajtanak végre.

 ***Futtatás:***   ./main {x} {n} {threads_count}

 ***Mérések:*** 

### PARARELL/3.beadandó

Téma: Order By, Search
Leírás: Több szálon történő rendezés, illetve keresés. C# nelyven, blazor és ASP .Net segítségével.
AsPararell().OrderBy összevetése az OrdeBy-al
AsPararell().Where összevetése a Where-el
Mérési eredmények a programban.
Tetszőlegesen állítható a szekvenciális és a párhuzamos futás.

## Grafika beadandó:

### GRAPHICS/beadandó

Téma:Dinós játék
Leírás: Egy dinóval kell kikerülni a kaktuszokat a sivatagban. A játéknak vége ha a dinó meghal.
