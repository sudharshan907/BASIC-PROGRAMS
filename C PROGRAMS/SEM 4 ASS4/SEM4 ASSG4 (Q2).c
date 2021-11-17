#include<stdio.h>
#include<stdlib.h>
struct node {
int key;
struct node *p;
};
struct table{
struct node *t;
};
int prim(int n);
int krus(int n);
int check(int e[100],int n);
struct node* makeset(int k);
struct node* find(struct node *x);
struct node* add(struct table T[100],int k);
struct node* un(struct node *x,struct node *y);

int G[100][100];

void main(){
int n,i,d=0,j=0;
char c,m;
scanf("%c",&m);
scanf("%d\n",&n);
for(i=0;i<n;i++){
        while(1){
            scanf("%c",&c);
            if(c=='\n'){
                if(d!=i){
                    G[i][d]=1;
                }
                d=0;
                break;
            }
            if((c>='0')&&(c<='9')){
                d=d*10+(c-'0');
            }
            if(c==32){
               if(d!=i){
                G[i][d]=1;

               }
                  d=0;  }} }

for(i=0;i<n;i++){
        j=0;
        while(1){
            scanf("%c",&c);
            if(c=='\n'){
              while((G[i][j]!=1)&&(j<n-1)){
                  j++;
              }
              if(i!=d){
              G[i][j]=d; }
                d=0;
                break;
            }
            if((c>='0')&&(c<='9')){
                d=d*10+(c-'0');
            }
            if(c==32){
              while((G[i][j]!=1)&&(j<n-1  )){
                  j++;
              }
                   if(i!=d){
              G[i][j]=d; }
                  d=0;  }} }


for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(G[i][j]==0)
                G[i][j]=10000;
        }  }


    if(m=='b')
printf("%d",prim(n));
if(m=='a')
printf("%d",krus(n));}


int prim(int n){
int min=10000,i,j,mincost=0,k=0,l=0;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
           if(min>G[i][j]){
            min=G[i][j];
            k=i;
            l=j;
           } }}
mincost=min;
int near[100];
for(i=0;i<n;i++){
  if(G[i][l]>G[i][k]){
        near[i]=k;
    }
    else{
        near[i]=l;
    }
}
int jfinal;
near[k]=near[l]=-1;
for(i=0;i<n-2;i++){
    min=10000;
    for(j=0;j<n;j++){
        if(near[j]==-1)
            continue;
        if(min>G[j][near[j]]){
                min=G[j][near[j]];
                jfinal=j;
    } }
    j=jfinal;
    mincost=mincost+G[j][near[j]];
    near[j]=-1;
    for(k=0;k<n;k++){
        if(near[k]==-1)
            continue;
        if(G[k][near[k]]>G[k][j]){
            near[k]=j;
        }
    }
}
return mincost;
}


int krus(int n){
int e[100],i,j,in=0,sw,u,v,ect=0,mincost=0;
for(i=0;i<100;i++){
    e[i]=0;
}
struct table T[100];
for(i=0;i<100;i++){
    T[i].t=NULL;
}
for(i=0;i<n;i++){
    T[i].t=makeset(i);
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if((G[i][j]!=10000)&&(check(e,G[i][j]))){
            e[in]=G[i][j];
            in++;
        } }}
for(i=0;i<in;i++){
    for(j=i+1;j<in;j++){
        if(e[i]>e[j]){
            sw=e[i];
            e[i]=e[j];
            e[j]=sw;

        } }
}
//e[],in,all vertices in data structure,n
for(ect=0;ect<in;ect++){
        u=0;v=0;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(G[i][j]==e[ect])
        {
            u=i;
            v=j;
        }
    }
}
if(find(add(T,u))->key!=find(add(T,v))->key){
    un(add(T,u),add(T,v));
    mincost=mincost+G[u][v];
}
}
return mincost;
}


int check(int e[100],int n){
    int i;
for(i=0;i<100;i++){
    if(e[i]==n){
        return 0;
    }
}
return 1;
}

struct node* makeset(int k){
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->key=k;
temp->p=temp;
return temp;
}

struct node* add(struct table T[100],int k){
int i=0;
for(i=0;i<100;i++){

    if((T[i].t)&&T[i].t->key==k)
        return (T[i].t);
}
return NULL;
}

struct node* find(struct node *x){
while(1){
    if(x->p==x)
        return x;
    x=x->p;
}
}

struct node* un(struct node *x,struct node *y){
x=find(x);
y=find(y);
y->p=x;
return x;
}

