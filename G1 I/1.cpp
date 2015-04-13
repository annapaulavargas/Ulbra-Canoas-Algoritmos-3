#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void incluir();
void imprimir();
void tudo();
void tamanho();

struct endereco{
	char rua[50];
	char nro[10];
	char cep[12];
	char bairro[50];
	char cidade[50];
};

struct agenda{
	char nome[50]; 
	char email[50];
	char obs[50];
	char telefone[15];
	struct endereco end;
};

struct agenda *registro;
int contador=0, i=0, indice=0;

int main(){
     int opcao;
          
     registro = (agenda *) malloc(contador*sizeof(agenda)*100);
	
	do{
    system("cls");
    printf("-------------------- M E N U ----------------------\n\n");         
    printf("1-Informe a quantidades de registros da agenda:\n\n");               
    printf("2-Inserir um novo contato\n\n"); 
    printf("3-Mostrar Nome/Telefone/Email)\n\n");
    printf("4-Mostrar todos os dados\n\n");
    printf("5-Sair\n\n");
    printf("---------------------------------------------------\n\n");
    printf ("Entre com uma das opcoes acima: ");
	opcao=getche();         
       
       switch(opcao){                           
           case '1': tamanho();
                     break; 
           case '2': incluir();       
                     break;
           case '3': imprimir();
                     break; 
           case '4': tudo();
                     break; 
           case '5': getch(); 
                      break;                            
           }
       }while(opcao!='5');
}

void incluir(){
          
          for(i=0;i<contador;i++){
          
            printf("\nNome:");
			fflush(stdin);                    
            scanf("%s",&registro[indice].nome);  
            fflush(stdin);
            printf("E-mail :");
            fflush(stdin);
            scanf("%s",&registro[indice].email);
            fflush(stdin);
            printf("Telefone :");
            fflush(stdin);
            scanf("%s", &registro[indice].telefone);
            fflush(stdin);
            printf("Obs :");
            fflush(stdin);
    		scanf("%s", &registro[indice].obs);
            printf("Rua : ");
            fflush(stdin);
            scanf("%s", &registro[indice].end.rua);
			fflush(stdin);
            printf("Nro da Rua: ");     
            scanf("%s",&registro[indice].end.nro);
			fflush(stdin);
            printf("Cep: ");     
            scanf("%s",&registro[indice].end.cep);
			fflush(stdin);
			printf("Bairro: ");     
            scanf("%s",&registro[indice].end.bairro);
            printf("Cidade: ");
            fflush(stdin);
            scanf("%s",&registro[indice].end.cidade);
            
            indice++;
        
         } 
           system("pause");
    }
  
     void imprimir(){
        printf("Relatorio parcial Nome/E-mail/Telefone: \n");
        for(i=0;i<contador;i++){
			printf("\nNome: %s\n", registro[i].nome);
            printf("E-mail: %s\n", registro[i].email);
            printf("Telefone: %s\n", registro[i].telefone);
            
			indice++; 	
       }
       printf("---------------------------------------------------\n");
       system("pause");    
     }
     
     void tudo(){
		printf("Relatorio completo: \n");
	    for(i=0;i<contador;i++){
     	printf("\nNome: %s",registro[i].nome);
     	printf("\nE-mail: %s",registro[i].email);
     	printf("\nObs: %s",registro[i].obs);
     	printf("\nTelefone: %s",registro[i].telefone);
     	printf("\nRua: %s",registro[i].end.rua);
     	printf("\nNro: %s",registro[i].end.nro);
     	printf("\nCEP: %s",registro[i].end.cep);
     	printf("\nBairro: %s",registro[i].end.bairro);
     	printf("\nCidade: %s",registro[i].end.cidade);
     	
    	indice++;
     }
     printf("---------------------------------------------------\n");
     system("pause");
     }
     
    void tamanho(){
          printf("\n1-Informe a quantidades de registros da agenda: ");         
          scanf("%i",&contador);
     }

     


