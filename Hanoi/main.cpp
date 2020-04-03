#include <stdio.h>
#include <winbgim.h>
#include <conio.h>

int ndiscos, movimientos;
int matriz[4][20];

void hanoi(int, int, int,int);
void dibujadisco(int,int,int);
void borradisco(int, int,int);
void dibujatorre1(void);
void muevegrafico(int,int);

int main (){
printf("N de discos: ");scanf("%d",&ndiscos);


initwindow(1080,500);
    setbkcolor(RGB(0, 0, 0));
    cleardevice();
    settextstyle(3,HORIZ_DIR,4);
    setcolor(4);
    outtextxy(250,10,"Simulacion del juego de Torres de Hanoi");

    settextstyle(3,HORIZ_DIR,4);
    setcolor(2);
    outtextxy(200,450,"Torre 1");
    outtextxy(500,450,"Torre 2");
    outtextxy(800,450,"Torre 3");

    setcolor(15);
    line(250,150,250 ,420);
    line(550,150,550 ,420);
    line(850,150,850 ,420);

    dibujatorre1();
    delay(1000);
    hanoi(ndiscos,1,2,3);
    printf("%d\n",movimientos);

getch();
closegraph();

return 0;
}
void dibujadisco(int torre,int altura, int tamano){
    int altpx,tampx,inipalox,inipaloy=400;
    if(torre==1) inipalox=250;
    if(torre==2) inipalox=550;
    if(torre==3) inipalox=850;
    altpx=inipaloy-(22*(altura-1));
    tampx=(tamano*20)+50;
    setcolor(tamano);
    rectangle(inipalox-(tampx/2),altpx,inipalox+(tampx/2),altpx+20);
}
void hanoi(int ndiscos, int a, int b, int c)
{
    if(ndiscos > 0)
    {
        hanoi(ndiscos-1, a, c, b);
        movimientos++;
        muevegrafico(a,c);
        delay(700/ndiscos);
        printf("mover disco de Torre %d a Torre %d \n",a ,c);
        hanoi(ndiscos-1,b, a, c);
    }
}
void borradisco(int torre,int altura, int tamano){
    int altpx,tampx,inipalox,inipaloy=400;
    if(torre==1) inipalox=250;
    if(torre==2) inipalox=550;
    if(torre==3) inipalox=850;
    altpx=inipaloy-(22*(altura-1));
    tampx=(tamano*20)+50;
    setcolor(0);
    rectangle(inipalox-(tampx/2),altpx,inipalox+(tampx/2),altpx+20);
}
void dibujatorre1(){
    int valor=ndiscos;
    matriz[1][0]=ndiscos;
    for(int j=1;j<=ndiscos;j++){
        dibujadisco(1,j,valor);
        matriz[1][j]=valor;
        valor--;
    }
}
void muevegrafico(int salida, int destino){
    int aux1,aux2;
    matriz[destino][0]+=1;
    aux1=matriz[destino][0];
    aux2=matriz[salida][0];
    matriz[destino][aux1]=matriz[salida][aux2];
    borradisco(salida,matriz[salida][0],matriz[salida][aux2]);
    dibujadisco(destino,matriz[destino][0],matriz[destino][aux1]);
    matriz[salida][aux2]=0;
    matriz[salida][0]-=1;

}
