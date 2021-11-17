#include<stdio.h>
void main(){
int n,i,j;
int a[100][100];
scanf("%d",&n);
for(i=0;i<100;i++){
    for(j=0;j<100;j++){
        a[i][j]=0;
    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
for(i=0;i<n;i++){
        printf("%d ",i);
    for(j=0;j<n;j++){
        if(a[i][j]==1){
            printf("%d ",j);
        }
    }
    printf("\n");
}
}








