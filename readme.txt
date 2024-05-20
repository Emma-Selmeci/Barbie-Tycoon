Ez a beadandó hatalmas munka volt, de nagy örömmel csináltam. Ez a legkomplexebb program, amit valaha írtam.

https://github.com/Emma-Selmeci/Bevprog2-Beadand-3
Megtalálható ezen a linken is, valamint a Githubomon megtalálható a félresikerült korábbi próbálkozás is,
ami csak a grafikai részig jutott el.

Egy kicsit eltértem a feladatkiírástól abban,
hogy nem minden eleme van a programnak widget-ként kezelve.
Azonban a MainScreen osztlyban van egy event-loop, ami a RightPanel nevű osztályon keresztül
egy polimorfikus grafikai kezelőrendszerré megy át, ahol már megtalálhatóak a widgetek, reményeim szerint tankönyvbe illően.
Ennek a választásnak az oka a program futásának lelassulása volt és a MainScreen-ben megjelenő
különböző panelek és textúrák. Megértem, ha pontlevonást kapok érte.

Mivel későn jöttem rá, mekkora nehézséget okozott az értelmezése, konzolba írtam ki a szállítás alatt álló termékek listáját.
Természetesen e nélkül is működik a játék, de elég nehéz febjen tartani különben a dolgokat.

Az esc-gombot biztonsággal meg lehet nyomni a játék közben a kilépés veszélye nélkül.
Amennyiben nehéznek bizonyulna a játék, 'c' gombbal lehet becsalni pénzt.

Előfordul, hogy beakadnak gombok :/
Ez szerintem az könyvtár okozta overhead hibája. Tessék kétszer megnyomni, másodjára működni szokott.

Ui.: Sajnos reményeimmel ellentétben nem sikerült befejeznem a projektet.
A leadási határidő idejében feltöltött állapot ugyan működik, de hiányzik belőle
sajnos a tech tree második része,
és a játék története sem bontakozik ki. Igyekszem befejezni még holnap a projektet,
így játszhatóvá válik a nem félkész verzió is.

Ui2.: Befejezem a projektet. A dolgok, amiket a leadás határideje és a befejezés között hozzáadtam:
-Az épületek lehelyezése pénzbe kerül
-Pár menüben megjelenő üzenet kijavítva
-Átállítottam az árakat és kutatási költségeket, hogy ne csődöljön be a játékos
-A "More Research" technológiától lefelé üzenetet állítottam be a technológiákhoz
-A "More Research" technológiától lefelé játékbeli eseményeket csináltam
-Cutscene-t raktam a játék közepére