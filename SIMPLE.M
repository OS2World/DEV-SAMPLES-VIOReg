simple.obj : simple.c
     cl -c -AH -G2 -Os -Zp -Zi simple.c

#simple.exe : simple.obj simple.def
simple.exe : simple.obj
#    link simple, simple/co, simple/map, test.lib llibc5.lib doscalls.lib, simple.def
#    link simple, simple/co, simple/map, test.lib llibce.lib doscalls.lib ;
     link simple, simple/co, simple/map, llibce.lib doscalls.lib ;
