#include <stdio.h>


int hanoi(int, char, char, char);

main (){

int ndiscos, movimientos;

printf("N de discos: ");scanf("%d",&ndiscos);
movimientos = hanoi(ndiscos,'A','B','C');



}


int hanoi(int ndiscos, char a, char b, char c)
{
    if(ndiscos > 0)
    {
        hanoi(ndiscos-1, a, c, b);

        printf("mover disco de %c a %c \n",a ,c);

        hanoi(ndiscos-1,b, a, c);
    }
}
