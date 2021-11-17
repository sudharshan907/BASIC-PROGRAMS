#include<stdio.h>
int fibonacci(int n){
if(n==0)
    return -1;
if(n<=2)
    return n-1;
return(fibonacci(n-1)+fibonacci(n-2));  }

void main(){
 int n,i;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    printf("%d ",fibonacci(i));  }
