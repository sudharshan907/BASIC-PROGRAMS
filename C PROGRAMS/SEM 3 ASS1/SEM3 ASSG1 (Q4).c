#include<stdio.h>
//n is[1,100],k is [0,infinity)
void circularshiftltor(int *a,int n,int k){
if(k>=n)
    k=k%n;
int i,j,t;
for(i=0;i<k;i++){
        t=a[n-1];
    for(j=n-1;j>0;j--){
       a[j]=a[j-1];
    }
  a[0]=t;   }}
void main(){
int n,k,a[100],i;
scanf("%d %d",&n,&k);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
circularshiftltor(a,n,k);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
