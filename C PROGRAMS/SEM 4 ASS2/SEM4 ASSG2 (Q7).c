#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int key;
    struct node *l,*r,*p;
};

void prtpar(struct node *h);
struct node * createnode(int k);
struct node * search(struct node *h,int k);
struct node * insert(struct node *h,struct node *new);
void order(int *a,int *c,int f,int l);
int level(struct node *h,int k);

void main(){
    struct node *h=NULL,*new=NULL;
 int n,*a,*c,*lev,i,maxlev=1,*levsumarr,j;
 scanf("%d",&n);
 a=(int *)malloc(n*sizeof(int));
 lev=(int *)malloc(n*sizeof(int));
 c=(int *)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  order(a,c,0,(n-1));

  for(i=0;i<n;i++){
       new=createnode(c[i]);
    h=insert(h,new);
  }

  prtpar(h);
  printf("\n");

  for(i=0;i<n;i++){
    lev[i]=level(h,a[i]);
    if(maxlev<lev[i]){
        maxlev=lev[i]; }
  }

levsumarr=(int *)malloc(maxlev*sizeof(int));
for(i=0;i<maxlev;i++){
    for(j=0;j<n;j++){
        if(lev[j]==i+1)
            levsumarr[i]+=a[j];
    }
}

for(i=0;i<maxlev;i++)
    printf("%d ",levsumarr[i]);

}

void order(int *a,int *c,int f,int l){
    static int cin=0;
    int i;
    float n;
if(l<f)
return ;

if(l==f){
    c[cin]=a[f];
    cin++;    }
if(l>f){
    n=(l-f+1)/2.0;
    i=ceil(n)-1+f;
   c[cin]=a[i];
     cin++;
     order(a,c,f,(i-1));
     order(a,c,i+1,l);
}   }

struct node * createnode(int k){
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->l=new->r=new->p=NULL;
return new;
}

struct node * insert(struct node *h,struct node *new){
struct node *m=h,*n=NULL;
while(m){
    n=m;
    if(new->key<m->key)
        m=m->l;
    else
        m=m->r;
}
new->p=n;
if(!n)
    h=new;
else if (new->key<n->key)
    n->l=new;
else
    n->r=new;
return h;
}

void prtpar(struct node *h){
     if(h==NULL){
        printf("( )");
     return ;   }
     printf("( %d ",h->key);
     prtpar(h->l);
     printf(" ");
     prtpar(h->r);
     printf(" )");
}

int level(struct node *h,int k){

int lev=1;
struct node *temp=NULL;

temp=search(h,k);


if(temp==NULL){
    return (-1);  }

    else{
while(  (h!=NULL)&&(h->key!=k)){
    if(k<h->key){
        h=h->l;
        lev=lev+1;}
    else{
        h=h->r;
        lev=lev+1;
    }
}
    }
return (lev);

}

struct node * search(struct node *h,int k){


   while((h!=NULL)&&(h->key!=k)){
    if(k<h->key)
        h=h->l;
    else
        h=h->r;
   }
    return h;
}
