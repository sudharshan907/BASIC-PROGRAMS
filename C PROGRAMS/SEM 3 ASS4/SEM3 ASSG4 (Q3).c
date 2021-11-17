#include<stdio.h>
#include<string.h>

struct employee{
    char s[20];
    int sal,w;
};

int ct;

//works only for max 10 employees,why dot operator??
void insert(struct employee *r,char *st,int sal,int w){
    if(w==8)
        sal=sal+50;
    if(w==10)
        sal=sal+100;
    if(w>10)
        sal=sal+150;
   strcpy(r[ct].s,st);
  r[ct].w=w;
   //(*(r+ct)).w=w;
   r[ct].sal=sal;
    ct++;
}

void printnonincrement(struct employee *r){
    int i;
for(i=0;i<ct;i++){
    if(!((r[i].w==8)||(r[i].w>=10)))
    printf("%s %d\n",r[i].s,r[i].sal);
} }

void printfinalsalary(struct employee *r){
int i;
for(i=0;i<ct;i++){
    printf("%s %d\n",r[i].s,r[i].sal);
}
}

void printworkperday(struct employee *r,int k){
int i;
for(i=0;i<ct;i++){
    if(r[i].w==k)
            printf("%s %d\n",r[i].s,r[i].sal);
}
}

void main(){
struct employee r[10];
int sal,w,k;
char s[20],c;
while(1){
    scanf("%c",&c);
    if(c=='r'){
        scanf(" %s %d %d ",s,&sal,&w);
         insert(r,s,sal,w);
        }
        else if(c=='i'){
             printnonincrement(r);
    }
    else if(c=='f'){
        printfinalsalary(r);
    }
    else if(c=='w'){
            scanf("%d",&k);
            printworkperday(r,k);
    }
    else if(c=='t')
    break;
}
}



