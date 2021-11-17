#include<stdio.h>
long long int factorial(long long int n){
if((n==0)||(n==1))
    return 1;
    return (n*factorial(n-1)); }

void main(){
long long int n;
scanf("%lld",&n);
printf("%lld",factorial(n));  }
