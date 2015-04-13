#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include<string.h>

       struct tipo_produtos {

		int 	codigo;
		char 	descr[50];   
		int 	quantidade;
		char 	fabricante[50];

	}reg  ;
	
	FILE *arq;
	int teste;
	char resp;

         
  // Aqui definir variáveis, ponteiros e estruturas utilizadas no programa
         
                  
         void Menu() {
              printf("                MENU:\n\n");
              printf("     1 - Incluir produto\n");
              printf("     2 - Excluir produto\n");
              printf("     3 - Exportar para arquivo texto\n");
              printf("     4 - Exportar para arquivo binário\n");
              printf("     5 - Listar arquivo texto\n");
              printf("     6 - Listar arquivo binário\n");
              printf("     7 - Soma\n");
              printf("     8 - Sair\n");
              printf("Opcao: "); scanf("%s", &resp);
         }
         
//*******************************************************************
         void Incluir (){
              int a,b;
			  resp='S';
              
			arq=fopen("cad_produto.txt","ab"); //Abre ou cria o arquivo caso ele não exista
			
			if(arq){						//Caso ele abra ele entrara no laço "IF"
				while(resp == 's' || resp == 'S'){
					clrscr();
					gotoxy(10,3); printf("Cadastro de Produto:");
					gotoxy(10,5); printf("=====================");
					gotoxy(10,7); printf("Codigo...: "); scanf("%i", &reg.codigo); 
					gotoxy(10,8); printf("Descricao.....: ");fflush(stdin); fgets(reg.descr,30,stdin);
					gotoxy(10,9); printf("Quantidade...: ");scanf("%i",&reg.quantidade);
					gotoxy(10,10);printf("Fabricante...: ");scanf("%s",&reg.fabricante);
					
					
					teste=fwrite(&reg,sizeof(struct tipo_produtos),1,arq); //Se ocorrer algum erro a função retorna nulo
					
					if(teste){
						gotoxy(10,14);printf("Dados Gravados com sucesso!");
					}
					gotoxy(10,20);printf("Deseja continuar S/N?");
					resp=getche();
				}
				fclose(arq);		//Fecha o arquivo
			}
		}
		              
//*******************************************************************         
  void Excluir(int codigo){
     
     char nomepesq[30];
     int achei,apontador;
     resp='S';
     
     arq = fopen("cad_produto.txt","rb+");
     
     if(arq){
             while(resp == 's' || resp == 'S'){
                        achei=0;
                        clrscr();
                        gotoxy(10,3);  printf("Excluir produto");
                        gotoxy(10,5);  printf("====================================");
                        gotoxy(10,7);  printf("Nome do produto a ser excluido: ");
                                       fflush(stdin);
                                       fgets(nomepesq,30,stdin);
                                       
                        rewind(arq);
                        apontador=0;
                        while(!feof(arq) && achei==0){
                                         teste=fread(&reg,sizeof(struct tipo_produtos),1,arq);
                                         apontador++;
                                         if(teste){
                                                   if(strcmp(reg.descr,nomepesq)==0){
                                                   gotoxy(10,8); printf("Pesquisa realizada com sucesso");
                                                   gotoxy(10,10); printf("===============================");
                                                   gotoxy(10,12); printf("Codigo...: %i", &reg.codigo); 
                                                   gotoxy(10,13); printf("Descricao....: %s", &reg.descr);
                                                   gotoxy(10,14); printf("Quantidade ..: %i", &reg.quantidade);
                                                   gotoxy(10,15); printf("fabricante..:  %s", &reg.fabricante);
                                                   achei=1;
                                                 
                                                   gotoxy(10,19); printf("Confirmar exclusão? S/N");
                                                   gotoxy(35,19); resp=getche();
                                                   
                                                   if(resp=='s' || resp== 'S'){
                                                                apontador--;
                                                                fseek(arq,apontador*sizeof(struct tipo_produtos),SEEK_SET);
                                                                teste=fwrite(&reg,sizeof(struct tipo_produtos),1,arq);
                                                                if(teste){
                                                                          gotoxy(10,19);
                                                                          printf("Registro excluido com sucesso");                                                        
                                            }
                                           }
                                          }
                                         }
                                        }
                                        if(achei=0){
                                           gotoxy(10,12);
                                           printf("Registro não encontrado :/");
                                        }             
                                        gotoxy(10,22);
                                        printf("Deseja continuar? S/N");
                                        resp=getche();
             }
             fclose(arq);
     }else{
           clrscr();
           gotoxy(10,8); printf("Arquivo vazio :/");
           gotoxy(10,10); printf("Tecle algo para voltar ao menu....");
           getch();
           }
     
}
         
//*******************************************************************
  		void Exportar_texto(){
     
         }

//*******************************************************************
		void Exportar_binario(){
             
	int linha=7;
	resp='S';

	arq=fopen("cad_produto.txt","rb");  //Abre o arquivo para leitura

	if(arq){   //Se o arquivo foi aberto corretamente, lista os dados
		system("cls");
		gotoxy(10,2); printf("\n\t========= Listar Produtos ==================================\n");
		gotoxy(10,5); printf("Codigo      Descricao        Quantidade      Fabricante");

		while(!feof(arq)){  

			teste= fread(&reg,sizeof(struct tipo_produtos),1,arq);

			if(teste==1){    // Mostra a lista na tela
				gotoxy(10, linha); printf("%i",reg.codigo);
				gotoxy(22, linha); puts(reg.descr);
				gotoxy(40, linha); printf("%i",reg.quantidade);
				gotoxy(55, linha); puts(reg.fabricante);
				linha++;
				
			}
		}
		getch();
		fclose(arq);
	}
}
     
         
//*******************************************************************
         void Listar_texto(){
        
         }     
//*******************************************************************         
        void Listar_binario(){
        
         }   
//*******************************************************************
 		void Soma(){
        
         }  
//*******************************************************************
         int main(){
	// Declarar as variáveis necessárias e alocações de memória
             int resp;
             int codigo = 0;
             do{
                system("cls");
                Menu();
                resp = getche();
                switch (resp){
                       case '1':
                            Incluir();
                            break;
                       case '2': 
			    			
			    			// Ler código de produto para passar à função exluir
                            Excluir(codigo);
                            break;
                       case '3': 
                            Exportar_texto();
                            break;
   						case '4': 
                            Exportar_binario();
                            break;
   						case '5': 
                            Listar_texto();
                            break;
   						case '6': 
                            Listar_binario();
                            break;
   						case '7': 
                            Soma();
                            break;
                }
             }	while(resp != '8');

             return 0;
         
         }
         
         
             
