/*   this is a dynamic link library file to test VIOREGISTER call for
     VIOPRTSC () .*/

#define ADDRESSING far
#define CALLING pascal
#define CONVENTION ADDRESSING CALLING
#include "doscalls.h"

/*   user defined VIOPRTSC ()   */

unsigned CONVENTION VIOPRTSC (j)
unsigned j ;
{
int i ;

/*   test message to verify the working of this function   */

   DOSWRITE (1, "This is from DLL", sizeof ("This is from DLL"), &i) ;
   return 0  ;

}


/*   compiler emits _acrtused as an external to pull in crt0.obj that
     defines _astart and calls _main. Add a dummy so crt0 is not pulled
     in.  */

struct route_information {
 unsigned      last_parameter  ;
 unsigned long return_address  ;
 unsigned      function_number ;
 unsigned      callers_ds      ;
 unsigned long vio_router      ;
} ;

#if defined( Use_viotty )
unsigned CONVENTION VIOWRTTTY (
char far * CharStr ,
unsigned Length ,
unsigned VioHandle
)
{
int i ;

struct route_information far * route_information = & VioHandle ;
/*   test message to verify the working of this function   */

   DOSWRITE (1, "This is from DLL", sizeof ("This is from DLL"), &i) ;
   return -1 ;

}
#endif

int far  VIDEOROUTER (unsigned temp2,
                      unsigned temp1,
                      unsigned index,
                      unsigned long stuff,
unsigned VioHandle ,
unsigned Length ,
char far * CharStr
) ;

int far  VIDEOROUTER (unsigned temp2,
                      unsigned temp1,
                      unsigned index,
                      unsigned long stuff,
unsigned VioHandle ,
unsigned Length ,
char far * CharStr
)
{
int i ;

/*   test message to verify the working of this function   */

   //DOSWRITE (1, "This is from DLL", sizeof ("This is from DLL"), &i) ;
   DOSWRITE (1, &index , sizeof ( index ), &i) ;
   DOSWRITE (1, & VioHandle , sizeof ( VioHandle ), &i) ;
   DOSWRITE (1, & Length , sizeof ( Length ), &i) ;
   DOSBEEP ( 20000 , 1 ) ;
   return -1 ;
   return 0  ;

}
#undef CALLING
#define CALLING cdecl

int CONVENTION _acrtused(){} ;


/*   the start up routine must be called _astart and it must return
     success or failure. Return success.  */

int CONVENTION _astart() {
    return 1 ;
    }

