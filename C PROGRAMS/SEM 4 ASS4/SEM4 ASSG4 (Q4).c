#include<stdio.h>
#include<stdlib.h>
struct node{
int v;
struct node *n;
};
int G[100][100];
int vis[100];
struct node *f,*r;

void bfs(int v,int n);
void dfs(int v,int n);
struct node * createnode(int k);
void enqueue(int k);
struct node* dequeue();

void main(){

int n,e,i,a,b,v,j;
scanf("%d %d",&n,&e);
for(i=0;i<e;i++){
    scanf("%d %d",&a,&b);
    G[a][b]=1;
}
scanf("%d",&v);
bfs(v,n);
printf("\n");
for(i=0;i<n;i++){
    vis[i]=0;
}
dfs(v,n);
}


void bfs(int v,int n){
int u=v,i;
vis[v]=1;
printf("%d ",v);
while(1){
for(i=0;i<n;i++){
    if(G[v][i]==1){
        if(vis[i]==0){
            enqueue(i);
            vis[i]=1;
            printf("%d ",i);
        } }}
if(f==NULL)
    break;
v=dequeue()->v;
}
}

struct node * createnode(int k){
struct node* new=(struct node*)malloc(sizeof(struct node));
new->v=k;
new->n=NULL;
return new;
}

void enqueue(int k){
struct node*new=createnode(k);

if(f==NULL){f=new;    r=new; }

else{ r->n=new;  r=new; }

}

struct node* dequeue(){
    struct node *new=NULL;
if(f==NULL)
    return NULL;
    else{
        new=f;
        f=f->n;
    }
return new;
}

void dfs(int v,int n){
    int w;
vis[v]=1;
printf("%d ",v);
for(w=0;w<n;w++){
    if(G[v][w]==1){
        if(vis[w]==0){
            dfs(w,n);
        }
    }
}
}

