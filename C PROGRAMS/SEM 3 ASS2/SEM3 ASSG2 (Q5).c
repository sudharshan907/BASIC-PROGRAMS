#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int reverse(int n){
  if(n==0)
    return 0;
  else{
        int p=log10(n);
    return ((n%10)*pow(10,p)+reverse(n/10));
  }
}

void main(){
 int n;
 scanf("%d",&n);
 printf("%d",reverse(n));  }
