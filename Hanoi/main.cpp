#include <stdio.h>
#include <winbgim.h>
#include <bits/stdc++.h>

using namespace std;

int hanoi(int, int, int,int);
int ndiscos, movimientos;
struct pieza{
    int xi;
    int xf;
    int yi;
    int yf;
    int tam;
    int torre;
};

void dibujadisco(int iddisco){


}
void muevegrafico(){

}
int main (){
printf("N de discos: ");scanf("%d",&ndiscos);
hanoi(ndiscos,1,2,3);
printf("%d\n",movimientos);

initwindow(1080,500);
    setbkcolor(RGB(102, 255, 102));
    cleardevice();
    settextstyle(3,HORIZ_DIR,4);
    setcolor(4);
    outtextxy(250,10,"Simulacion del juego de Torres de Hanoi");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(200,450,"Torre 1");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(500,450,"Torre 2");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(800,450,"Torre 3");

    setcolor(0);
    line(250,150,250 ,420);
    line(550,150,550 ,420);
    line(850,150,850 ,420);




getch();
closegraph();


return 0;
}


int hanoi(int ndiscos, int a, int b, int c)
{
    if(ndiscos > 0)
    {
        hanoi(ndiscos-1, a, c, b);
        movimientos++;
        printf("mover disco de Torre %d a Torre %d \n",a ,c);
        hanoi(ndiscos-1,b, a, c);
    }
}
