#include<stdio.h>
#include<math.h>
long int convert(long int n){
int i,j=0,f=0;
while(n){
    i=n%10;
    f=f+i*pow(2,j);
    n=n/10;
    j++;}
    return f; }
void main(){
long int n;
scanf("%ld",&n);
printf("%ld",convert(n)); }
