#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <math.h> 
#include <string.h>

struct tipo_produtos {

    int codigo;
    char descr[50];
    int quantidade;
    char fabricante[50];

}
reg;

FILE * arq;
int a;
char resp;

//*******************************************************************                  
void Menu() {
    printf("\n\n MENU:\n\n");
    printf("     1 - Incluir produto\n");
    printf("     2 - Excluir produto\n");
    printf("     3 - Exportar para arquivo texto\n");
    printf("     4 - Exportar para arquivo binário\n");
    printf("     5 - Listar arquivo texto\n");
    printf("     6 - Listar arquivo binário\n");
    printf("     7 - Soma\n");
    printf("     8 - Sair\n");
    printf("\n\n Opcao: "); //scanf("%s", &resp);
}

//*******************************************************************
void incluir() {
    resp = 'S';

    arq = fopen("cad_produto.txt", "ab"); //Abre ou cria o arquivo caso ele não exista
    if (arq) { //Caso ele abra ele entrara no laço "IF"
        while (resp == 's' || resp == 'S') {
            clrscr();
            gotoxy(10, 3);
            printf("Cadastro de Produto:");
            gotoxy(10, 5);
            printf("=====================");
            gotoxy(10, 7);
            printf("Codigo...: ");
            scanf("%i", & reg.codigo);
            gotoxy(10, 8);
            printf("Descricao.....: ");
            fflush(stdin);
            fgets(reg.descr, 30, stdin);
            gotoxy(10, 9);
            printf("Quantidade...: ");
            scanf("%i", & reg.quantidade);
            gotoxy(10, 10);
            printf("Fabricante...: ");
            scanf("%s", & reg.fabricante);


            a = fwrite( & reg, sizeof(struct tipo_produtos), 1, arq); //Se ocorrer algum erro a função retorna nulo
            if (a) {
                gotoxy(10, 14);
                printf("Dados Gravados com sucesso!");
            }
            gotoxy(10, 20);
            printf("Deseja continuar S/N?");
            resp = getch();
        }
        fclose(arq); //Fecha o arquivo
    }
}

//*******************************************************************         
void Excluir(int codigo) {

    char nomepesq[30];
    int achei, apontador;
    resp = 'S';

    arq = fopen("cad_produto.txt", "rb+");

    if (arq) {
        while (resp == 's' || resp == 'S') {
            achei = 0;
            clrscr();
            gotoxy(10, 3);
            printf("Excluir produto");
            gotoxy(10, 5);
            printf("====================================");
            gotoxy(10, 7);
            printf("Nome do produto a ser excluido: ");
            fflush(stdin);
            fgets(nomepesq, 30, stdin);

            rewind(arq);
            apontador = 0;
            while (!feof(arq) && achei == 0) {
                a = fread( & reg, sizeof(struct tipo_produtos), 1, arq);
                apontador++;
                if (a) {
                    if (strcmp(reg.descr, nomepesq) == 0) {
                        gotoxy(10, 8);
                        printf("Pesquisa realizada com sucesso");
                        gotoxy(10, 10);
                        printf("===============================");
                        gotoxy(10, 12);
                        printf("Codigo...: %i", & reg.codigo);
                        gotoxy(10, 13);
                        printf("Descricao....: %s", & reg.descr);
                        gotoxy(10, 14);
                        printf("Quantidade ..: %i", & reg.quantidade);
                        gotoxy(10, 15);
                        printf("fabricante..:  %s", & reg.fabricante);
                        achei = 1;

                        gotoxy(10, 19);
                        printf("Confirmar exclusão? S/N");
                        gotoxy(35, 19);
                        resp = getche();

                        if (resp == 's' || resp == 'S') {
                            apontador--;
                            fseek(arq, apontador * sizeof(struct tipo_produtos), SEEK_SET);
                            a = fwrite( & reg, sizeof(struct tipo_produtos), 1, arq);
                            if (a) {
                                gotoxy(10, 19);
                                printf("Registro excluido com sucesso");
                            }
                        }
                    }
                }
            }
            if (achei = 0) {
                gotoxy(10, 12);
                printf("Registro não encontrado :/");
            }
            gotoxy(10, 22);
            printf("Deseja continuar? S/N");
            resp = getche();
        }
        fclose(arq);
    } else {
        clrscr();
        gotoxy(10, 8);
        printf("Arquivo vazio :/");
        gotoxy(10, 10);
        printf("Tecle algo para voltar ao menu....");
        getch();
    }

}

//*******************************************************************
void Exportar_texto() {
    //					FILE *p;
    //					int i=0, arquivo;
    //					p=fopen(nome_arquivo,"w+t");
    //					if(p==NULL){
    //						printf("Erro ao criar arquivo...");
    //						getch();
    //					}else{
    //						while(i!=contador){
    //						//	fprintf(p,"Codigo: %d\n - Descricao: %s - Fabricante: %s - Quantidade: %d \n\n", &reg[i].codigo,&reg[i].descr,&reg[i].fabricante,&reg[i].quantidade); 
    //							i++;
    //						}
    //						fclose(p);
    //						clrscr();		
    //					}
}



//*******************************************************************
void Exportar_binario() {

    //				int linha=7;
    //				resp='S';
    //			
    //				arq=fopen("cad_produto.txt","rb");  //Abre o arquivo para leitura
    //			
    //				if(arq){   //Se o arquivo foi aberto corretamente, lista os dados
    //					system("cls");
    //					gotoxy(10,2); printf("\n\t========= Exportar Binario ==================================\n");
    //					gotoxy(10,5); printf("Codigo      Descricao        Quantidade      Fabricante");
    //			
    //					while(!feof(arq)){  
    //			
    //						a= fread(&reg,sizeof(struct tipo_produtos),1,arq);
    //			
    //						if(a==1){    // Mostra a lista na tela
    //							gotoxy(10, linha); printf("%i",reg.codigo);
    //							gotoxy(22, linha); puts(reg.descr);
    //							gotoxy(40, linha); printf("%i",reg.quantidade);
    //							gotoxy(55, linha); puts(reg.fabricante);
    //							linha++;
    //							
    //						}
    //					}
    //					getch();
    //					fclose(arq);
    //				}
}


//*******************************************************************
void Listar_texto() {

    int linha = 7;
    resp = 'S';

    arq = fopen("cad_produto.txt", "rt");

    if (arq) {
        clrscr();
        gotoxy(10, 2);
        printf("\n\t========= Listar Produtos ==================================\n");
        gotoxy(10, 5);
        printf("Codigo      Descricao        Quantidade      Fabricante");

        while (!feof(arq)) {

            a = fread(&reg, sizeof(struct tipo_produtos), 1, arq);

            if (a == 1) {
                gotoxy(10, linha);
                printf("%i", & reg.codigo);
                gotoxy(22, linha);
                printf("%s", & reg.descr);
                gotoxy(40, linha);
                printf("%i", & reg.quantidade);
                gotoxy(55, linha);
                printf("%s", & reg.fabricante);
                linha++;
            }
        }
        getch();
        fclose(arq);
    }
}


//*******************************************************************         
void Listar_binario(){

	int linha = 7;
    resp = 'S';

    arq = fopen("cad_produto.txt", "rb");
    rewind(arq);

    if (arq) {
        clrscr();
        gotoxy(10, 2);
        printf("\n\t========= Listar Produtos Binarios ==================================\n");
        gotoxy(10, 5);
        printf("Codigo      Descricao        Quantidade      Fabricante");

        while (!feof(arq)) {

            a = fread(&reg, sizeof(struct tipo_produtos), 1, arq);

            if (a == 1) {
                gotoxy(10, linha);
                printf("%i", & reg.codigo);
                gotoxy(22, linha);
                printf("%s", & reg.descr);
                gotoxy(40, linha);
                printf("%i", & reg.quantidade);
                gotoxy(55, linha);
                printf("%s", & reg.fabricante);
                linha++;
            }
        }
        getch();
        fclose(arq);
    }
}
//*******************************************************************
void Soma() {
    int qtd = 0;

    qtd = qtd + reg.quantidade;

    printf("Soma quantidade total: %i", qtd);
    getch();
    clrscr();
}


//*******************************************************************
int main() {
    char resp;
    int codigo = 0;
    do {
        clrscr();
        Menu();
        resp = getche();
        switch (resp) {
        case '1':
        	
            incluir();
            break;
        case '2':
            Excluir(codigo);
            break;
        case '3':
            clrscr();
            printf("Digite o nome do arquivo que deseja exportar no formato TEXTO: ");
            Exportar_texto();
            break;
        case '4':
        	clrscr();
            Exportar_binario();
            break;
        case '5':
            clrscr();
            Listar_texto();
            break;
        case '6':
        	clrscr();
            Listar_binario();
            break;
        case '7':
            clrscr();
            Soma();
            break;
        }
        clrscr();
    } while (resp != '8');

    return 0;

}
