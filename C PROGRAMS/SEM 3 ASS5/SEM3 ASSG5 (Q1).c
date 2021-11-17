#include<stdio.h>

int count;

void maxheapify(int *a,int i,int heapsize);
void buildmaxheap(int *a,int heapsize);
void heapsort(int *a,int heapsize);

//elements are there from index 1 not from 0 index
void main(){
    int n,a[201],i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    heapsort(a,n);
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
        printf("\n%d",count);
}

void maxheapify(int *a,int i,int heapsize){
int l=2*i,r=2*i+1,lar,t;
if(l<=heapsize)
    count++;
if((l<=heapsize)&&(a[l]>a[i])){     lar=l;  }
else                          {    lar=i;  }
if(r<=heapsize)
count++;
if((r<=heapsize)&&(a[r]>a[lar])){   lar=r;  }
if(lar!=i){
    t=a[i];   a[i]=a[lar];   a[lar]=t;
    maxheapify(a,lar,heapsize);
}
}

void buildmaxheap(int *a,int heapsize){
int i;
for(i=(heapsize/2);i>=1;i--){
    maxheapify(a,i,heapsize); }}

void heapsort(int *a,int heapsize){
int i,t;
buildmaxheap(a,heapsize);
for(i=heapsize;i>=2;i--){
         t=a[1];    a[1]=a[i];   a[i]=t;
  heapsize--;
  maxheapify(a,1,heapsize);
}}

