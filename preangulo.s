.data 
Sf2: .string "testandostring\n"
.text
.globl main
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $32, %rsp /*afinal calle saved podem ser 3 ponteiros(24 bytes)*/
 
  movl $5, %edi
  
  
  movq $Sf2, %rdi /* fist param */
  movl $0, %eax
  call printf

  leave  /* finalizacao*/
  ret
