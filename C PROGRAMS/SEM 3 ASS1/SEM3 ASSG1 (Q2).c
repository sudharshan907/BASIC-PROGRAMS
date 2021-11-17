#include<stdio.h>
void bubblesort(int *a,int n){
int i,j,t;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            t=a[j];a[j]=a[j+1];a[j+1]=t; }
            }
            }
            }
void main(){
int n,a[100],i;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    bubblesort(a,n);
for(i=0;i<n;i++)
printf("%d ",a[i]); }
