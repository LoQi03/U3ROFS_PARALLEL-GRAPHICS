# U3ROFS_PARARELL-GRAPHICS

## Pararell beadandók:

### PARARELL/1.beadandó

Téma: Quick Sort(tetszőleges szálon futó)
Leírás: Generál N db számot, majd bekéri hogy hány szálon végezze el. Illetve lefut sekvenciálisan is.

6-szálon lett tesztelve.

    |  Nums  | Pararell | Sequence |
    |  99999 | 0.003000 | 0.006000 |
    |  50000 | 0.003000 | 0.005000 |
    | 150000 | 0.004000 | 0.010000 |

### PARARELL/2.beadandó

Téma: Taylor sorbafejtés
Leírás: kiszámolja az exp,sin,cos értékeket több szálon, illetve a sorbafejtésnél az összeadást is több szálon végzi el.

x=0.5 N=1000000

    Pararell:
    |   f  |    time   |
    |  exp | 21.871000 |
    |  cos | 44.134000 |
    |  sin | 44.208000 |

    Sequence:
    |   f  |    time   |
    |  exp | 21.923000 |
    |  cos | 44.724000 |
    |  sin | 46.850000 |

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
