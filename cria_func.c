/* Lucas Ebrenz Fernandes Pereira 20011488 3WC */
/* version 0.1 */

//#define DEBUG // comente essa linha para desativar o modo debug.
#include <stdio.h>
#include "cria_func.h"
/**
* Cria funcoes.
* 
* @param f  Tem o endereco da funcao original a ser chamada pelo cod gerado.
* @param params[] array contendo desc dos params para chamar essa func: max 3
* @param n Qnts params estao no array params[].
* @param codigo[] Vetor onde devera ser gravado o codigo gerado.
* @return Essa funcao nao retorna nada.
*/
void cria_func (void* f, DescParam params[], int n, unsigned char codigo[]){


/*              Prologo
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 20          	sub    $0x20,%rsp   */
      codigo[0] = 0x55; 
      codigo[1] = 0x48; codigo[2] = 0x89; codigo[3] = 0xe5;
      codigo[1] = 0x48; codigo[2] = 0x83; codigo[3] = 0xec; codigo[7] = 0x20; 
    /*int i=0, escreve =1; 
    while(escreve){
      /* Preangulo */
      i++;
    }*/
    
    /* Finalizacao */
    codigo[8] = 0xc9;
    codigo[9] = 0xc3;
}
