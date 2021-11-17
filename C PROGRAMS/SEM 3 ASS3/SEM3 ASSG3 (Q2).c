#include<stdio.h>

int ct;
void mergesort(int *a,int p,int r);
void merge(int *a,int p,int q,int r);

void main(){
int n,a[100],i;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
mergesort(a,0,n-1);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n%d",ct);
}

void mergesort(int *a,int p,int r){
    if(p<r){
int q=(p+r)/2;
mergesort(a,p,q);
mergesort(a,q+1,r);
merge(a,p,q,r);
    }
}

//works only upto 100 elements in subarray,and max element is 9999
void merge(int *a,int p,int q,int r){
int n1=q-p+1,n2=r-q,l[100],ri[100],i,j,k;
i=0;j=p;
while(i<n1){
    l[i]=a[j];
    i++;j++;
}
i=0;j=q+1;
while(i<n2){
    ri[i]=a[j];
i++;j++;
}
l[n1]=ri[n2]=10000;
i=0;j=0;
for(k=p;k<=r;k++){
    ct++;
    if(l[i]<=ri[j]){
        a[k]=l[i];
        i++;
    }
    else{
        a[k]=ri[j];
        j++;
    }
}
}
