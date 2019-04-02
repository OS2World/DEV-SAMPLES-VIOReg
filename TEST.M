test.obj : test.c
     cl -c -Alnu -G2s -Zi test.c

test.dll : test.obj test.def
     link test.obj, test.dll /co , test.map/map, llibce.lib doscalls.lib, test.def
     implib test.lib test.def
