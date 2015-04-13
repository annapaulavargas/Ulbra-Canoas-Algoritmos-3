#include<conio.c>
#include<stdlib.h>
#include<stdio.h>
#include <math.h>

int main()
{
    int num;
    
    gotoxy(10,2);printf("\n\t******** Exercicio 3 *******\n");
    gotoxy(10,5);printf("Informe o valor inteiro: ");
    scanf("%i", &num);
    valorbin(num);
    gotoxy(10,14);system("PAUSE");
}

void valorbin(int num)
{ 
       int bin;
       
       if (num <= 0)
       {
          gotoxy(10,8); printf("\n\t*** Resposta **** \n");
          gotoxy(10,11);printf("Qual o valor em Binario: ");
          return; 
       }
       bin = num % 2;
       valorbin(num / 2);
       printf("%i",bin);
}


 



