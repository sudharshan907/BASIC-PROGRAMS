#include<stdio.h>
void printmergedarray(int *a,int n1,int *b,int n2){
int i,j,k;
for(i=0;i<n1;i++)
    printf("%d ",a[i]);
    for(j=0;j<n2;j++){
               for(i=0;i<n1;i++){  if(a[i]==b[j]);      break; }
              for(k=0;k<j;k++)  {  if(b[j]==b[k]);      break; }
             if((i==n1)&&(k==j))
                printf("%d ",b[j]);
    }
}
void main(){
int n1,a[100],n2,b[100],i;
scanf("%d",&n1);
for(i=0;i<n1;i++)
    scanf("%d",&a[i]);
scanf("%d",&n2);
for(i=0;i<n2;i++)
    scanf("%d",&b[i]);
    printmergedarray(a,n1,b,n2);
}

