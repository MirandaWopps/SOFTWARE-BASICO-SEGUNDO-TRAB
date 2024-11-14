#include "cria_func.h"
#include <stdio.h>
/** Cria_func
* 
*
* @authors Eu
* @param f tem endereço da func original
* @param params descricao dos params para chamar essa func. Variam entre PARAM(o parametro nao amarrado, ou seja, deve ser recebido pela nova func e repassado a func orgin), FIX(o parametro deve ser amarrado a um valor constante fornecido no campo valor) e IND(o parametro deve ser amarrado a uma variavel cujo endereco esta no campo valor, ou seja, passado a func original o valor corrente dessa var.
* @param n numero de parametros descritos por params e codigo
* @param codigo vetor onde code gerado sera gravado
* @return nothing.
*/
void cria_func(void* f, DescParam params[], int n, unsigned char codigo[]) {
	// Aloque espaco para funcao na memoria
	unsigned char* funcao;
	funcao = &f; // aponta para o endereco desejado, assim, construimos o codigo la.
	funcao = (unsigned char*)malloc(sizeof(codigo) );// lembre de alocar 

	// preciso ler o vetor todo em "codigo" e por na funcao "funcao"
	//for (int i = 0; i < n; i++) { /*estamos varrendo o vetor fazendo alteracoes dos registers por seus valores*/
	for (int j = 0;   j < sizeof(codigo);     j++) {
		/*if (codigo[j] == 1) {//rdi
			funcao[j] = ;
		}
		else if (codigo[j] == 2) {//rsi
			funcao[j] = ;
		}
		else if (codigo[j] == 3) {// rdx
			funcao[j] = ;
		}
		else if (codigo[j] == 4) {// edi
			funcao[j] = ;
		}
		else if (codigo[j] == 5) {//esi
			funcao[j] = ;
		}
		else if (codigo[j] == 6) { // edx
			funcao[j] = ;
		}
		else {
			funcao[j] = codigo[j];
			printf("%c ", codigo[j]);// so uma linha de debug
		}*/
		funcao[j] = codigo[j];
	}
	//}
	//

	//



	//   preciso substituir os valoers que equivalem a %rdi, %rsi, %rdx  e %edi, %esi e %edx. Eles variam
	// if sizeof(valor) == sizeof(int) ou ponteiro.
	//     anexa os valores dos parametros aos seus respectivos registradores de 4 bytes 	
	// else /*sabemos que e 8 bytes*/
	//		anexa valores dos parametros de 8 bytes em seus respectivos codigos(identificadores)
	//
	//
	//
	//
	for (unsigned char *p=f; p != NULL; p++) { // linha para debug
		int i = 0;
		printf("(%c) " , p);
		
	}
}
