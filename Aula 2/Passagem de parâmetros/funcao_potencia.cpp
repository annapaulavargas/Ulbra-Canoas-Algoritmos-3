#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,numero,expo,resultado=1;
printf("\n\t\t############### Calculo de potencias ######################\n");
printf("\nEntre com o numero a ser calculado:");
scanf("%d",&numero);
printf("Agora informe a que expoente o numero %d sera elevado.", numero);
scanf("%d",&expo);
for(i=0; i<expo; i++) 
{
resultado*=numero;  //resultado=resultado*numero;
}

printf("\n\n\nO resultado e: %d\n\n\n", resultado);
system("pause");
}
