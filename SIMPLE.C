/* This is a sample program to show the use of function VIOREGISTER ().
The VIOREGISTER () call is used to register the function VIOPRTSC (), which
is defined by the user in dynamic link library.

MASK1 enables the mask for VIOPRTSC ()      */

#define   MASK1   0x01004000
#define   MASK2   0x00000000

#include "subcalls.h"

extern unsigned far pascal VIOPRTSC (unsigned);
#define LIMIT 100
main() {
 int i ;
 static char string [ ] = "hello" ;

/*  test is the name of dynamic link library file   */

        VIOREGISTER ((char far *) "test", (char far *) "_VIDEOROUTER" ,
              (unsigned long) MASK1, (unsigned long) MASK2) ;
        // VIOPRTSC ((unsigned) 1) ;
        for( i = 0 ; i < LIMIT ; i ++ ) {
         VIOWRTTTY ( string , sizeof( string ) , 0 ) ;
        }
        VIODEREGISTER ( ) ;
    }
