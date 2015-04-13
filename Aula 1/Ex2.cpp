#include <stdio.h>
#include <conio.h>


 main(){
        
    int idade, soma, cont;     
    float media;
    
    soma=0;
    
    for(cont=0;idade>0;cont++){
         printf("\n Informe a idade: ");
         scanf("%i", &idade);
         soma = soma + idade;
    }
    if (soma==0)
        media=0;
    else
        media=soma/cont-1;
        printf("\n Media das idades digitadas: %f", media);   
        getch();
}
