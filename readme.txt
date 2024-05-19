Ez a beadandó hatalmas munka volt, de nagy örömmel csináltam.

Egy kicsit eltértem a feladatkiírástól abban,
hogy nem minden eleme van a programnak widget-ként kezelve.
Azonban a MainScreen osztlyban van egy event-loop, ami a RightPanel nevű osztályon keresztül
egy polimorfikus grafikai kezelőrendszerré megy át, ahol már megtalálhatóak a widgetek.
Ennek a választásnak az oka a program futásának lelassulása volt és a MainScreen-ben megjelenő
különböző panelek és textúrák. Megértem, ha pontlevonást kapok érte.

Az esc-gombot biztonsággal meg lehet nyomni a játék közben a kilépés veszélye nélkül.