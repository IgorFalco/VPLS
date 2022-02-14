#include<iostream>

int main()
{
  int a = 10; // 1) Declare uma variável do tipo inteiro e atribua o valor '10'

  int *ptr = NULL; // 2) Declare um ponteiro para inteiros e inicialize com valor nulo

  int v[10] = {9,8,7,6,5,4,3,2,1,0}; // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    
  std::cout << &a << std::endl; // 4) Imprima o ENDEREÇO da variável declarada em (1)
    
  std::cout << a  << std::endl; // 5) Imprima o VALOR da variável declarada em (1)
    
  std::cout << &ptr << std::endl; // 6) Imprima o ENDEREÇO da variável declarada em (2)
    
  std::cout << ptr << std::endl; // 7) Imprima o VALOR da variável declarada em (2)

  std::cout << &v << std::endl;// 8) Imprima o ENDEREÇO da variável declarada em (3)
    
  std::cout << &v[0] << std::endl;// 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    
  std::cout << v[0] << std::endl;// 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    
  ptr = &a;// 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    
  std::cout << ptr << std::endl;// 12) Imprima o VALOR da variável declarada em (2)
    
  std::cout << *ptr << std::endl;// 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
  std::cout << (&a == ptr) << std::endl; // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    
  *ptr = 5; // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    
  std::cout << a << std::endl;// 16) Imprima o VALOR da variável declarada em (1)
    
  ptr = v; // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    
  std::cout << ptr << std::endl; // 18) Imprima o VALOR da variável declarada em (2)
    
  std::cout << *ptr << std::endl;// 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
  ptr = v;// 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    
  std::cout << ptr << std::endl;// 21) Imprima o VALOR da variável declarada em (2)
    
  std::cout << *ptr << std::endl; // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
  *ptr = 10*(*ptr); // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);
  ptr++;
  *ptr = 10*(*ptr);

  for (int i = 0; i < 10; i++)  // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
  {
    std::cout << v[i];
      if(i < 9) 
      std::cout << " ";
  }
  std::cout << std::endl;
    
  for (int i = 0; i < 10; i++) // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
  {
    *v = *(v + i );
    std::cout << *v;
    if(i < 9) 
      std::cout << " ";
  }
  *v = 90;
  std::cout << std::endl;    
                        
                              
  ptr = v;                      // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
  for (int i = 0; i < 10; i++)
  {
    std::cout << *ptr;
    if(i < 9) 
      std::cout << " ";
    ptr++;
  }
  std::cout << std::endl;
    
    
      

  ptr = (v + 4);// 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    

  std::cout << ptr << std::endl; // 28) Imprima o VALOR da variável declarada em (2)
    

  std::cout << *ptr << std::endl; // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    

  std::cout << *(ptr - 4) << std::endl;// 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
    

  int **pptr = &ptr; // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    

  std::cout << pptr << std::endl; // 32) Imprima o VALOR da variável declarada em (31)
    

  std::cout << &pptr << std::endl; // 33) Imprima o ENDEREÇO da variável declarada em (31)
    

  std::cout << *pptr << std::endl; // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    

  std::cout << **pptr << std::endl; // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    
    
    return 0;
}