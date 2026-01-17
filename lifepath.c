#include <stdio.h>
#include <stdlib.h>
    int reduce(int a);
    int sumardigitos(int n);
    int main(){
    
    // d=day, m=month, y=year
    // dd= day in decimal, md=month in decimal, yd=yearindecimal
    // d1,d2,m1,m2,y1,y2,y3,y4 are all variables used to calculate lifepath. Smaller Number means
    // is to the left, and if is bigger then it its to the right. Ex: 2004, y1=2; y4=4
    char d[3],m[3],y[5];
    int dd, md, yd,d1,d2,m1,m2,y1,y2,y3,y4,lifepath;
    
    printf("Bienvenido a la calculadora de numerología\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||\n");
    
    printf("Inserta tu fecha de nacimiento, el formato es DD/MM/AAAA\n");
    scanf("%2s/%2s/%4s", d, m, y);
    
    printf("Tu fecha de nacimiento es: %s/%s/%s ", d,m,y);
    dd= atoi(d);
    md=atoi(m);
    yd=atoi(y);
    lifepath = reduce(sumardigitos(dd)+sumardigitos(md)+sumardigitos(yd));
    printf("Tu lifepath es %d", lifepath);
}

void separar2(int a, int *a1, int *a2){
    *a1= a/10;
    *a2= a%10;
}

void separar4(int a, int *a1, int *a2, int *a3, int *a4){
    *a1 = a /1000;
    *a2 = (a / 100) % 10;
    *a3 = (a/10) %10;
    *a4 = a%10;
}

int sumar8(int a, int b, int c, int d, int e, int f, int g, int h){
    return a+b+c+d+e+f+g+h;
}

int reduce(int n){
    while (n >= 10 && n != 11 && n != 22 && n != 33){
        n = sumardigitos(n);
    }
    return n;
}

int sumardigitos(int n){
    int suma=0;
    while (n>0){
        suma += n%10;
        n /= 10;
    }
    return suma;
}