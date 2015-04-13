#include <stdio.h>
#include <stdlib.h>

int x ( int n, int m)
{
 if ((n==m) or (m==0))
   return 1;
 else 
   return ( x(n-1,m) + x(n-1,m+1)) ;
} 

 int main()
{
 int n;
 printf("Digite um n: ");
 scanf("%d", &n);
 printf("Digite um m: ");
 scanf("%d", &m);
 

 printf("X: %d\n", x(x));
 
system("PAUSE");
}
