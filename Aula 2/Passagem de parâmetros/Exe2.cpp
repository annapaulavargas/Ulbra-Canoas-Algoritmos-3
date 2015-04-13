#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>

float soma(float valor, float reajuste ){    //funcao para soma do reajuste da mercadoria
     float valor_atual;
     valor_atual = valor + reajuste * valor/100;
     printf ("O valor da mercadoria apos o reajuste e: %f\n", valor_atual);
}
int main(){
float valor,reajuste;
    printf ("Digite o valor da mercadoria: ");
    scanf("%f", &valor);
    printf ("Digite o percentual de reajuste: ");
    scanf("%f", &reajuste);
 
    
    soma (valor, reajuste); //chamando funcao soma lá de cima
 
    system("PAUSE");
    return 0;
}
