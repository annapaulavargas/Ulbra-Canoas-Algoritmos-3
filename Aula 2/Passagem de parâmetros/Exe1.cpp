#include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

#include <stdio.h>
#include<stdlib.h>
int swap(int *a, int *b){
 int aux;
 aux = *a;
 *a = *b;
 *b = aux;

 }
int main(){
 int a,b;

 printf ("Digite o primeiro valor: ");
 scanf("%d", &a);
 printf ("Digite o segundo valor: ");
 scanf("%d", &b);
 swap (&a, &b);
 printf ("A ^ B é: %f\n", pow(b,a));
 system("PAUSE");
 return 0;
} 
