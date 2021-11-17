#include<stdio.h>
int binarysearch(int *a,int p,int r,int k){
if(p<=r){
    int q=(p+r)/2;
    if(a[q]==k)
        return q;
        if(k<a[q])
   return binarysearch(a,p,q-1,k);
   else
   return binarysearch(a,q+1,r,k);
}
return -1;
}

int binarysearchm(int *a,int p,int r,int k){
    int q=(p+r)/2;
if(p<=r){
    if(a[q]==k)
        return q;
        if(k>a[q])
   return binarysearchm(a,p,q-1,k);
   else
   return binarysearchm(a,q+1,r,k);
}
return -1;
}

void main(){
int n,i,a[100],k,f;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
scanf("%d",&k);
for(i=0;i<n;i++){
    if(a[i]>a[i+1]){
        f=i;
        break;  }}
i=binarysearch(a,0,f,k);
if(i==-1)
    i=binarysearchm(a,f+1,n-1,k);
if(i==-1)
    printf("%d",i);
   else{
        for(n=0;n<=i;n++){
                if(a[n]==k){
            printf("%d",n);
            break; }
        }
    }
}
