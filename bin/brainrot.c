#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
int a = 1;
int b = 2;
int c = 5;
int d = 20;
int j = 99;

int x = ( ( b - a + d ) * c + j ) % 30;
printf("%d\n", x);


return 0;
}