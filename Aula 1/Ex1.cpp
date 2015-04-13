#include <stdio.h>
#include <conio.h>


 main(){
        float nota, maior;
        int cont;
        char resp='S';
        
        maior=0;
        
        for(nota=0;resp!='N'&&resp!='n';cont++){
        printf("\n Informe sua nota: \n");
        scanf("%f", &nota);
        if(nota>maior)
           maior = nota;
        printf("\n\nDeseja continuar? S/N\n\n");
        resp=getche();
        };
        printf("\nA maior nota informada: %f\n", maior);
        
       getch();
 }              
        
