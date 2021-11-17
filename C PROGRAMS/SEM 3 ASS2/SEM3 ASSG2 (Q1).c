#include<stdio.h>
int gcd(int a,int b){
    int i=b%a;
    if(b%a)
    return (gcd(i,a));
    return a; }

void main(){
int a,b;
scanf("%d %d",&a,&b);
if((a==0)&&(b==0)){
printf("-1");return; }
if(a==0){
    printf("%d",b);
return; }
if(b==0){
printf("%d",a);
return; }
printf("%d",gcd(a,b));
}
