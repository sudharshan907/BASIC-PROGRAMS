#include<stdio.h>

void minheapify(int *a,int i,int heapsize);
void heapmin(int *a,int heapsize);
int extractmin(int *a,int heapsize);
void decreasekey(int *a,int i,int k);
int heapinsert(int *a,int k,int heapsize);
void display(int *a,int heapsize);

//elements are there from index 1 not from 0 index,works for duplicate values in queue also
void main(){
int a[100],k,b,heapsize=0;
char c;
while(1){
    scanf("%c",&c);
    if(c=='i'){
        scanf("%d",&k);
    b=heapinsert(a,k,heapsize);
      if(b)
        heapsize++;}
        else if(c=='e'){
       b= extractmin(a,heapsize);
       printf("\n");
       if(b)
        heapsize--;
    }
    else if(c=='m'){
        heapmin(a,heapsize);
    }
    else if(c=='c'){
            scanf("%d %d",&k,&b);
        decreasekey(a,k+1,b);
    }
    else if(c=='d'){
        display(a,heapsize);
        printf("\n");
    }
    else if(c=='s')
    break;
}
}

//left child value is exchanged with parent value if both childs are equal(convention bcz duplicate values may be possible)
void minheapify(int *a,int i,int heapsize){
int l=2*i,r=2*i+1,min,temp;
if((l<=heapsize)&&(a[l]<a[i])){     min=l;  }
else                          {    min=i;  }
if((r<=heapsize)&&(a[r]<a[min])){   min=r;  }
if(a[l]==a[r]){
    min=l;  }
if(min!=i){
    temp=a[i];   a[i]=a[min];   a[min]=temp;
    minheapify(a,min,heapsize);
}
}

void heapmin(int *a,int heapsize){
if(heapsize==0)
    printf("-1\n");
else
    printf("%d\n",a[1]);
}


int extractmin(int *a,int heapsize){
    int t;
if(heapsize==0){
    printf("-1 ");
    return 0;
}
else{
    printf("%d ",a[1]);
    a[1]=a[heapsize];
    heapsize--;
    minheapify(a,1,heapsize);
    return 1;
}
}

//works only if i is from 1 to n,call with i+1,k is less than a[i]t
void decreasekey(int *a,int i,int k){
    int t;
    a[i]=k;
    while((i>1)&&(a[i/2]>a[i])){
        t=a[i];
        a[i]=a[i/2];
        a[i/2]=t;
        i=i/2;  }
}

//array size is max 100 elements only(max 99 values),if max value is 10000
int heapinsert(int *a,int k,int heapsize){
if(heapsize==99){
    return 0; }
heapsize++;
a[heapsize]=10000;
decreasekey(a,heapsize,k);
return 1;
}

void display(int *a,int heapsize){
int i,b[100],n=heapsize,d=0;
if(heapsize==0)
    printf("-1\n");
for(i=1;i<=heapsize;i++){
    b[i]=a[i];
}
for(i=1;i<=n;i++){
    d=extractmin(b,heapsize);
    if(d)
        heapsize--;
}}
