#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "time.h"

 struct agenda *ag;
         int i = 0;   

         struct endereco {
                char rua[50], bairro[50], cidade[50];
                int num, cep;
         };                       
         
         struct agenda {
                 char nome[50], email[30], telefone[10];
				 endereco end;        
         };
                                    	              
			  
         
         void inserir (){
         	  ag = (struct agenda*) malloc(sizeof(struct agenda));
         	  
              gotoxy(5,2);printf("Nome:");
              gotoxy(11,2);scanf("%s",&ag[i].nome);
              gotoxy(5,4);printf("Telefone:");
              gotoxy(15,4);scanf("%s",&ag[i].telefone);
       		  gotoxy(5,6);printf("E-mail:");
              gotoxy(13,6);scanf("%s",&ag[i].email);
			  gotoxy(5,8);printf("Rua:");
              gotoxy(10,8);scanf("%s",&ag[i].end.rua);
              gotoxy(5,10);printf("Numero:");
              gotoxy(13,10);scanf("%i",&ag[i].end.num);
       		  gotoxy(5,12);printf("Bairro:");
              gotoxy(13,12);scanf("%s",&ag[i].end.bairro);
			  gotoxy(5,14);printf("Cidade:");
              gotoxy(13,14);scanf("%s",&ag[i].end.cidade); 
              gotoxy(5,16);printf("CEP:");
              gotoxy(10,16);scanf("%i",&ag[i].end.cep); 
          }
         
         void mostrar( ){
           gotoxy(5,2);printf("Nome: %s\n",ag[i].nome);
           gotoxy(5,4);printf("Telefone: %s\n",ag[i].telefone);
           gotoxy(5,6);printf("E-mail: %s\n",ag[i].email);
         }
         
  void mostrartudo() {
    gotoxy(5,2);printf("Nome: %s",ag[i].nome);
    gotoxy(5,4);printf("Telefone: %s",ag[i].telefone);
    gotoxy(5,6);printf("E-mail: %s",ag[i].email);
    gotoxy(5,8);printf("Rua: %s",ag[i].end.rua);
    gotoxy(5,10);printf("Número: %i",ag[i].end.num);
    gotoxy(5,12);printf("Cidade: %s",ag[i].end.cidade);
    gotoxy(5,14);printf("Bairro: %s",ag[i].end.bairro);
    gotoxy(5,16);printf("CEP:    %i",ag[i].end.cep);        
  }     
         
         int main(){
           ag = (agenda*) malloc (50 * sizeof(agenda));
           char op;
           int in = 0;
			   
		       do { 
		       	  clrscr();
		       	  gotoxy(5,2);
		          printf("Agenda 2015 :\n\n");
		          gotoxy(5,4);
				  printf("1 - Inserir um novo contato\n");
		          gotoxy(5,6);
				  printf("2 - Mostrar nome, telefone e e-mail\n");
		          gotoxy(5,8);
				  printf("3 - Mostrar todos os dados\n");
		          gotoxy(5,10);
				  printf("4 - Sair\n");
		          
		              op=getche();
		              
				  clrscr();

		              switch(op){
		                case '1': 
						  if (in < 2) {
						    in = in + 1;
							inserir();
						  } else {
						    printf(" Voce so pode inserir 2 contatos!");
						  }
						break;
		                case '2':		   
						  mostrar();
						  getch();    
						break;
		                case '3': 
						  mostrartudo();
						  getch();   
						break;
		                case '4': clrscr();
		                         printf("O programa foi encerrado.");
		                         printf("Tecle algo para sair...");
		                         getch();  
		                         break;
		                default:  printf("Opcao invalida.");
		                          printf("Tecle algo para continuar...");
		                          getch();
		                }
		            }while(op!='4');
		       }   
         
         
         
         
             
