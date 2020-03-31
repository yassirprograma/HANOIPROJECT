#include <stdio.h>
#include <winbgim.h>

int hanoi(int, char, char, char);

int main (){

int ndiscos, movimientos;

printf("N de discos: ");scanf("%d",&ndiscos);
movimientos = hanoi(ndiscos,'A','B','C');

initwindow(1080,500);
    setbkcolor(RGB(102, 255, 102));
    cleardevice();
    settextstyle(3,HORIZ_DIR,4);
    setcolor(4);
    outtextxy(250,10,"Simulacion del juego de Torres de Hanoi");



    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(200,450,"Torre A");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(500,450,"Torre B");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(800,450,"Torre C");

    setcolor(0);
    line(250,150,250 ,420);
    line(550,150,550 ,420);
    line(850,150,850 ,420);


getch();
closegraph();



return 0;
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
