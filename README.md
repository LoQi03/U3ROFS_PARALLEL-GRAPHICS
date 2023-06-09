# U3ROFS PARALLEL-GRAPHICS

# PARALLEL beadandók:

## PARALLEL/1.beadandó

### Téma: Quick Sort
### Leírás:
A program vár 2 paramétert: egy "n" értéket, és egy "threads_count" értéket. Az első bemeneti paraméter az, hogy mennyi számot generáljon a program, a második paraméter pedig az, hogy hány szálon végezze el az algoritmus. Az algoritmus a tömb elemeit résztömbökre osztja, majd a résztömbök elemeit összehasonlítja egy "pivot" értékkel, majd azokat a résztömböket rendezni, amelyekben az elemeik kisebbek vagy nagyobbak a pivotnál. A program ezen kívül tartalmaz egy párhuzamosított verziót is, amelyben a munkát több szál végzi el egyszerre.

 ### Futtatás:

    ./main {N} {threads_count}

 ### Mérések:

 <table>
    <tr>
        <th>N</th>
        <th>Szekvenciális(ms)</th>
        <th>6 szálon(ms)</th>
        <th>12 szálon(ms)</th>
        <th>18 szálon(ms)</th>
    <tr>
    <tr>
        <td>10000</td>
        <td>0.001000</td>
        <td>0.001000</td>
        <td>0.004000</td>
        <td>0.002000</td>
    </tr>
     <tr>
        <td>100000</td>
        <td>0.006000</td>
        <td>0.002000</td>
        <td>0.002000</td>
        <td>0.004000</td>
    </tr>
    <tr>
        <td>150000</td>
        <td>0.009000</td>
        <td>0.003000</td>
        <td>0.003000</td>
        <td>0.009000</td>
    </tr>
        <tr>
        <td>1500000</td>
        <td>0.009000</td>
        <td>0.003000</td>
        <td>0.003000</td>
        <td>0.009000</td>
    </tr>
</table>

![alt text](./assets/beadando1.png "Grafikon")

## PARALLEL/2.beadandó

### Téma: Taylor sorbafejtés
### Leírás:
A program vár három bemeneti paramétert: egy lebegőpontos "x" értéket, egy egész "n" értéket és egy egész "thread_count" értéket. Az első bemeneti paraméterre a cos, sin és exp függvények számítása során lesz szükség, a második bemeneti paraméter pedig meghatározza, hogy hány tagot kell számolni a Taylor sorozatokban. A harmadik bemeneti paraméter a párhuzamosított számítások száma, amelyeket a "cos_taylor", "sin_taylor" és "exp_taylor" függvényekben hajtanak végre.

 #### Futtatás:

    ./main {x} {n} {threads_count}

 #### Mérések:
 
 x=0.5

Szekvenciális: 
 <table>
    <tr>
        <th>N</th>
        <th>cos</th>
        <th>sin</th>
        <th>exp</th>
    <tr>
    <tr>
        <td>1000</td>
        <td>0.004000</td>
        <td>0.006000</td>
        <td>0.001000</td>
    </tr>
        <tr>
        <td>10000</td>
        <td>0.378000</td>
        <td>0.381000</td>
        <td>0.190000</td>
    </tr>
    </tr>
        <tr>
        <td>100000</td>
        <td>38.223000</td>
        <td>38.301000</td>
        <td>19.030000</td>
    </tr>
</table>



6 szálon:
 <table>
    <tr>
        <th>N</th>
        <th>cos</th>
        <th>sin</th>
        <th>exp</th>
    <tr>
    <tr>
        <td>1000</td>
        <td>0.002000</td>
        <td>0.003000</td>
        <td>0.001000</td>
    </tr>
        <tr>
        <td>10000</td>
        <td>0.117000</td>
        <td>0.117000</td>
        <td>0.060000</td>
    </tr>
    </tr>
        <tr>
        <td>100000</td>
        <td>11.852000</td>
        <td>11.765000</td>
        <td>5.869000</td>
    </tr>
</table>

12 szálon:
 <table>
    <tr>
        <th>N</th>
        <th>cos</th>
        <th>sin</th>
        <th>exp</th>
    <tr>
    <tr>
        <td>1000</td>
        <td>0.002000</td>
        <td>0.001000</td>
        <td>0.001000</td>
    </tr>
        <tr>
        <td>10000</td>
        <td>0.063000</td>
        <td>0.061000</td>
        <td>0.031000</td>
    </tr>
    </tr>
        <tr>
        <td>100000</td>
        <td>6.230000</td>
        <td>6.244000</td>
        <td>3.132000</td>
    </tr>
</table>

18 szálon:
 <table>
    <tr>
        <th>N</th>
        <th>cos</th>
        <th>sin</th>
        <th>exp</th>
    <tr>
    <tr>
        <td>1000</td>
        <td>0.003000</td>
        <td>0.000000</td>
        <td>0.000000</td>
    </tr>
        <tr>
        <td>10000</td>
        <td>0.046000</td>
        <td>0.042000</td>
        <td>0.022000</td>
    </tr>
    </tr>
        <tr>
        <td>100000</td>
        <td>4.256000</td>
        <td>4.421000</td>
        <td>2.105000</td>
    </tr>
</table>

<strong>Összesítés:</strong>
N=100000 esetén...

![alt text](./assets/beadando2.png "Grafikon:")

## PARARELL/3.beadandó

### Téma: Order By, Search
### Leírás:
Több szálon történő rendezés, illetve keresés. C# nelyven, Windows és .Net környezetben. Az adatokat a program indulásakor generálom.


AsPararell().OrderBy összevetése az OrdeBy-al

AsPararell().Where összevetése a Where-el


A mérési eredményt az aktuális lekérdezéskor írja ki a program. A programban egy gombbal tetszőlegesen állítható az aktuális lekérdezés, vagyis hogy a program párhuzamosan vagy szekvenciálisan hajtja végre a kérést, ennek mérési eredményét is a gomb alatt írja ki.

# Grafika beadandó:

## GRAPHICS/beadandó

### Téma: Dinós játék
### Leírás: 
Ez egy Endless runner game, amiben egy dinót irányítunk akinek át kell kelnie a sivatagon. A raptoron és a napon kívül minden objektum procedurálisan van generálva. Ahogy a raptorral elérünk egy házat a raptor sebessége megnő, így nehezíti meg a játékot.

### Irányítás: 

<kbd>-></kbd> - jobbra

<kbd><-</kbd> - balra

<kbd>L</kbd> - kamera rögzítése

<kbd>3</kbd> - fényerő növelése

<kbd>4</kbd> - fényerő csökkentése

<kbd>SPACE</kbd> - Játék újrakezdése

 #### Futtatás:

    ./dino_run
