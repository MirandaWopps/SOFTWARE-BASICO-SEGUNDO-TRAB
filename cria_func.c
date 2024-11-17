/* Lucas Ebrenz Fernandes Pereira 20011488 3WC */
/* version 0.1 */

#define DEBUG // comente essa linha para desativar o modo debug.
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
      codigo[4] = 0x48; codigo[5] = 0x83; codigo[6] = 0xec; codigo[7] = 0x20; 
      
      
    int i=7; // contador de indices de 'codigo'
    /*int i=0, escreve =1; 
    while(escreve){
      i++;
    }*/
    /*ARRUMAR 1st PARAMETRO*/
  if (n!=0){ // se existe algum parametro
    if (params[0].orig_val = PARAM  )   {
      if (params[0].tipo_val == INT_PAR){ // int param: reg de 32, logo, eax
        codigo[8] = 0x89; // movl %edi,%edi 
        codigo[9] = 0xff; // 
        i+=2;
      }else{ // PTR_ PAR pede 64 bits
        codigo[8] = 0x48; // movq %rdi, %rdi
        codigo[9] = 0x89;
        codigo[10]= 0xff;
        i+=3;
      }
      
    } else if (params[0].orig_val = FIX){// VALOR FIXO A SER PASSADO !
        if (params[0].tipo_val == INT_PAR){ // int param: reg de 32, logo, eax
          codigo[8] = 0xbf; // movl $0x5,%edi
          codigo[9] = (unsigned char)params[0].valor.v_int; // 2
          codigo[10] = 0x00; // 3
          codigo[11] = 0x00; // 4
          codigo[12] = 0x00; //5
          i+=5;
        }else{ // PTR_ PAR pede 64 bits
          codigo[8] = 0x48; // movq $0x5,%rdi
          codigo[9] = 0xc7; // 2
          codigo[10]= 0xc7; // 3
          codigo[11] = (unsigned char)params[0].valor.v_ptr;
          codigo[12]= 0x00; // 5
          codigo[13] = 0x00; // 6
          codigo[14]= 0x00; // 7
          i+=7;
        }
        #ifdef DEBUG
        printf("entrou aq\n");
        #endif
        
    }
    else { // IND- endereco
          if (params[0].tipo_val == INT_PAR){ // int: 32bits, logo, eax
          codigo[8] = 0xbf; // movl $0x5,%edi
          codigo[9] = (unsigned char)params[0].valor.v_int; // 2
          codigo[10]= 0x00; // 3
          codigo[11]= 0x00; // 4
          codigo[12]= 0x00; //5
          i+=5;
        }else{ // PTR_ PAR pede 64 bits
          codigo[8] = 0x48; // movq $0x5,%rdi
          codigo[9] = 0xc7; // 2
          codigo[10]= 0xc7; // 3
          codigo[11]= (unsigned char)params[0].valor.v_ptr;
          codigo[12]= 0x00; // 5
          codigo[13]= 0x00; // 6
          codigo[14]= 0x00; // 7
          i+=7;
        }
    }// fim ind
  }//fim first param
   
   
   /*
  /*ARRUMAR 2st PARAMETRO*
  if (n<2){ // se existe algum parametro 
    if (params[2].orig_val = PARAM  )   { // CASO REPASSSE O PARAM ('PARAM')
       if (params[2].tipo_val == INT_PAR){ // int param: reg de 32, logo, eax
          codigo[8] = 0x89; // movl %esi,%esi 
          codigo[9] = 0xf6; // 
          i+=2;
       } else{ // PTR_ PAR pede 64 bits
          codigo[8] = 0x48; // movq %rsi, %rsi
          codigo[9] = 0x89;
          codigo[10]= 0xf6;
          i+=3;
      }
      
    }
  }  
    
    
    /*ARRUMAR 3st PARAMETRO
  if (n<3){ // se existe algum parametro 
    if (params[2].orig_val = PARAM  )   { // CASO REPASSSE O PARAM ('PARAM')
       if (params[2].tipo_val == INT_PAR){ // int param: reg de 32, logo, eax
          codigo[8] = 0x89; // movl %edx,%edx 
          codigo[9] = 0xd2; // 
          i+=2;
       } else{ // PTR_ PAR pede 64 bits
          codigo[8] = 0x48; // movq %rdx, %rdx
          codigo[9] = 0x89; 
          codigo[10]= 0xd2;
          i+=3;
      }
      
    } else { // 
        
        
    }
    
  }  */
    
    
    /* CALL F */
    codigo[i+1]= 0xff ;
    codigo[i+2]= 0xd0;
    
    /* Finalizacao */
    codigo[i+3] = 0xc9;
    codigo[i+4] = 0xc3;
}
