#include <stdio.h>

int lire_entier(void)
{
   char c;
   printf("entier> ");
   c=getchar();
   while ( (c=getchar()) != '\n' && c!= EOF ) {
       c=getchar();
       if (c >= '0' && c <= '9') {
           printf("%d est un entier\n" , c);
       }
       else{
           return -1;
       }
   }
  return 0;
}

int main(void){
    for (;;) lire_entier(); /* L2 */
    return 0;
}
