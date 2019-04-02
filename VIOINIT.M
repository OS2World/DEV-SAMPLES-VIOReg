file=vioinit

$(file).obj : $(file).c
     cl -c -AH -G2 -Os -Zp -Zi $(file).c

$(file).exe : $(file).obj
      link $(file), $(file)/co, $(file)/map, llibce.lib doscalls.lib ;
