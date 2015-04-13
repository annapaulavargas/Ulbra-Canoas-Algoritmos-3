// Ejemplo del uso de conio
#include <conio.c>
#include <string.h>

int main(int argc, char *argv[])
{
   char cad[80];
   char destin[4096];
   int i;
   
   clrscr();
   textbackground(BLUE);
   textcolor(YELLOW);
   clrscr();
   getch();
   window(2,2,77,22);
   textbackground(RED);
   textcolor(LIGHTBLUE);
   clrscr();
   gotoxy(1,3); cprintf("Prueba");
   getch();
   window(3,3,76,21);
   textbackground(LIGHTBLUE);
   textcolor(CYAN);
   clrscr();
   gotoxy(1,3); cputs("Otra prueba");
   for(i = 0; i < 100; i++) cputs("111");
   highvideo();
   for(i = 0; i < 100; i++) cputs("222");
   lowvideo();
   for(i = 0; i < 100; i++) cputs("333");
   highvideo();
   for(i = 0; i < 100; i++) cputs("444");
   lowvideo();
   for(i = 0; i < 100; i++) cputs("555");
   highvideo();
   for(i = 0; i < 100; i++) cputs("666");
   getch();
   gotoxy(10, 12); cputs("aqui");
   getch();
   delline();
   getch();
   gotoxy(10, 1); cputs("aqui");
   getch();
   delline();
   getch();
   gotoxy(10, 15); cputs("aqui");
   getch();
   delline();
   getch();
   normvideo();
   for(i = 0; i < 500; i++) putch('*');
   getch();
   gotoxy(10, 4); cputs("aqui");
   getch();
   insline();
   cputs("insertada");
   getch();
   gotoxy(1, 7);
   cputs("Leer una cadena: ");
   cad[0]=10;
   cgets(cad);
   gotoxy(1, 8);
   cprintf("caracteres leidos: %d, cadena %s #relleno relleno relleno "
	   "relleno###########################", (int)cad[1], &cad[2]);
   clreol();
   getch();
   strcpy(cad, getpass("clave: ")); 
   cprintf("clave leida: %s", cad);
   getch();
   gettext(2, 2, 74, 19, destin);
   clrscr();
   getch();
   puttext(1, 1, 73, 18, destin);  
   getch();
   textbackground(BLUE);
   textcolor(WHITE);
   window(10,10,15,15);
   getch();
   normvideo();
   textcolor(WHITE);
   textbackground(BLACK);
   window(1,1,80,25);
   gotoxy(1,1);
   return 0;
}
