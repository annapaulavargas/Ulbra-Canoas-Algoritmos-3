#include <conio.c>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float resrecursiva(float num);
float resiterativa(float num);

float resrecursiva(float num)      

{    
    if (num < 2)
    {
        return(0);
    }
    else
    {
        return(1 / num + resrecursiva(num - 2));
    }
}

float resiterativa(float num)   

{
    float auxiliar = 0;
    float n = num * 2;
    
    while (n >= 2)
    {
        auxiliar = auxiliar + (1 / n);
        n = n - 2;        
    }
    
    return auxiliar;
}

main()
{
    float s;
       
    system ("CLS");
    gotoxy(10,2); printf("\n\t******** Pergunta *******\n");
    gotoxy(10,5); printf("Informe o valor inteiro: ");
    gotoxy(35,5);scanf("%f", &s);
    fflush(stdin);
    system("CLS");
    
    gotoxy(10,2); printf("\n\t******** Resposta ******* \n");
    gotoxy(10,5); printf("  recursiva: %f\n\n", resrecursiva(s * 2));  
    gotoxy(10,7); printf("  iterativa: %f\n",   resiterativa(s));    
    gotoxy(10,9); 
	system("PAUSE");
}
