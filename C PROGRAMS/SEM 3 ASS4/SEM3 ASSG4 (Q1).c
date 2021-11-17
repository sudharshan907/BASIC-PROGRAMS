#include<stdio.h>
#include<stdlib.h>
int ct;
int partition(int *a,int p,int r);
void quicksort(int *a,int p,int r);

void main(){
int n,i;
scanf("%d",&n);
int *a=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
    scanf("%d",(a+i));
quicksort(a,0,n-1);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n%d",ct);
}

int partition(int *a,int p,int r){
int x=a[r],i=p-1,j,t;
for(j=p;j<r;j++){
    if((++ct)&&(a[j]<x)){
        i++;
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }}
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return(i+1);
}

void quicksort(int *a,int p,int r){
    int q;
if(p<r){
    q=partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r); }
}
