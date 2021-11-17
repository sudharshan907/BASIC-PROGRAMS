#include<stdio.h>
void search(int *a,int n,int k){
int i,ct=0;
for(i=0;i<n;i++){
    if(a[i]==k){
            ct++;
        printf("%d ",i); }
}
if(ct==0)
    printf("-1");
}
void main(){
int n,a[100],i,k;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&k);
    search(a,n,k); }
