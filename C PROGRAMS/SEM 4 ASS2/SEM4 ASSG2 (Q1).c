#include<stdio.h>
#include<stdlib.h>

void insert(int *T,int k,char c,int c1,int c2,int m);
int search(int *T,int k,char c,int c1,int c2,int m);
void delete(int *T,int k,char c,int c1,int c2,int m);
void print(int *T,int m);
int qh(int k,int i,int c1,int c2,int m);
int dh(int k,int i,int m);

void main(){
char c,d;
int m,c1,c2,k,i,*T;
scanf("%c",&c);
scanf("%d",&m);
T=(int *)malloc(m*sizeof(int));
for(i=0;i<m;i++)
    T[i]=-10000;
if(c=='a'){  scanf("%d %d",&c1,&c2); }
    else{ c1=0;c2=0; }
while(1){
    scanf("%c",&d);
    if(d=='i'){
        scanf("%d",&k);
     insert(T,k,c,c1,c2,m); }
    else if(d=='s'){
        scanf("%d",&k);
        if(search(T,k,c,c1,c2,m))
            printf("1\n");
        else
            printf("-1\n"); }
    else if (d=='d'){
        scanf("%d",&k);
        delete(T,k,c,c1,c2,m); }
    else if(d=='p')
        print(T,m);
    else if(d=='t')
        break;
} }
int prime(int k){
int i;
for(i=2;(i<=k/2);i++){
    if(k%i==0)
        return 0;  }
return 1;
}
int qh(int k,int i,int c1,int c2,int m){
int r,r1,r2,r3;
r1=k%m;
r2=i*c1;
r3=i*i*c2;
r=(r1+r2+r3)%m;
return r;
}
int dh(int k,int i,int m){
int R,r1,r2,r,j;
j=m-1;
while(1){
    if(prime(j)){R=j; break; }
    j--; }
    r1=k%m;
r2=(R-(k%R))*i;
r=(r1+r2)%m;
return r;
}
void print(int *T,int m){
int i=0;
for(i=0;i<m;i++){
    printf("%d ",i);
    if(T[i]==-10000)
        printf("()\n");
    else
        printf("(%d)\n",T[i]);   } }
void insert(int *T,int k,char c,int c1,int c2,int m){
int h,i=0;
while(i<m){
    if(c=='a')
        h=qh(k,i,c1,c2,m);
    if(c=='b')
        h=dh(k,i,m);
    if(T[h]==-10000){
        T[h]=k;break;}
    i++;}
}
int search(int *T,int k,char c,int c1,int c2,int m){
int h,i=0;
while(i<m){
    if(c=='a')
        h=qh(k,i,c1,c2,m);
    if(c=='b')
        h=dh(k,i,m);
    if(T[h]==k)
        return 1;
    i++;}
    return 0;
}
void delete(int *T,int k,char c,int c1,int c2,int m){
int h,i=0;
while(i<m){
    if(c=='a')
        h=qh(k,i,c1,c2,m);
    if(c=='b')
        h=dh(k,i,m);
    if(T[h]==k){
       T[h]=-10000;
        return ;  }
    i++;}
    return ;   }











