#include<stdio.h>
int ct;
void insertionsort(int *a,int n);

void main(){
int n,a[100],i;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
insertionsort(a,n);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n%d",ct);
}
//for counting no of swaps put ct++ after compaision in while condition
void insertionsort(int *a,int n){
int i,j,x;
for(j=1;j<n;j++){
    x=a[j];
    i=j-1;
    while((i>=0)&&(++ct)&&(a[i]>x)){
        a[i+1]=a[i];
      i--;
    }
   a[i+1]=x;
}
}
