#include <stdio.h>
#include "cria_func.h"

char fixa[] = "asd";

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

int main (void) {
  DescParam params[2];
  func_ptr f_mult;
  int i;
  unsigned char codigo[500];

  params[0].tipo_val = INT_PAR; /* o primeiro parãmetro de mult é int */
  params[0].orig_val = FIX;   /* a nova função repassa seu parämetro */
  params[0].valor.v_int = 10;


/*
  params[1].tipo_val = INT_PAR; /* o segundo parâmetro de mult é int *
  params[1].orig_val = FIX;     /* a nova função passa para mult a constante 10 *
  params[1].valor.v_int = 10;
*/
  cria_func (mult, params, 2, codigo);
  f_mult = (func_ptr) codigo;   

  for (int j=0; j<50; j++){
    printf("%x ", codigo[j]);
  }

/*
  for (i = 1; i <=10; i++) {
    printf("%d\n", f_mult(i)); /* a nova função só recebe um argumento 
  }*/

  return 0;
}
