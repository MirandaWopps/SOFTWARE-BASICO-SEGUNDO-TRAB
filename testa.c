#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr)(int x);

int mult(int x, int y) {
  return x * y;
}

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main(void) {
  DescParam params[2];
  func_ptr f_mult;
  int i;
  unsigned char codigo[500];
  
// caracterizar parametros

  params[0].tipo_val = INT_PAR; /* o primeiro parãmetro de mult é int */
  params[0].orig_val = PARAM;   /* a nova função repassa seu parämetro */

  params[1].tipo_val = INT_PAR; /* o segundo parâmetro de mult é int */
  params[1].orig_val = FIX;     /* a nova função passa para mult a constante 10 */
  params[1].valor.v_int = 10;
    
//void cria_func (void* f, DescParam params[], int n, unsigned char codigo[]){    
    cria_func(mult, params, 2 , codigo);
    for (int i=0; i<50 ;i++){
      printf("%x ", codigo[i] );
    }    	
    dump(codigo,50);
    
	return 0;
}
