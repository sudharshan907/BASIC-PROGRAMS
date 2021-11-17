#include<stdio.h>
void main(){
int n,a[100],i,j,ct;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
for(i=0;i<n;i++){
    ct=0;
for(j=0;j<n;j++){
    if(a[i]==a[j]){
        ct++;
    } }
if(ct>=(n/2+1)){
    printf("%d",a[i]);
return; }
}
printf("-1");}
