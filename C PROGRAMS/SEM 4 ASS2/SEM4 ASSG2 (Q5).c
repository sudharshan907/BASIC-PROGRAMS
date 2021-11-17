#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prc(char *s,int i);
int printinorder(char *s,int i,int * inor);
int sea(int inorder[],int n,int k);

void main(){
 int i=0,d=0,j=0,l,n,k,f;
    char s[3000],in[1000];
    int inorder[1000];
    scanf("%[^\n]",in);
    l=strlen(in);
   while(i<l){
     if((in[i]==')')||(in[i]=='(')){
            s[j]=in[i];
            j++;             }

       else if((in[i]>='0')&&(in[i]<='9')){
            d=(in[i]-'0');
           while((in[i+1]>='0')&&(in[i+1]<='9')){
                   d=d*10 +(in[i+1]-'0');i++;
            }
        s[j]=d;j++;
        }
        i++;}
s[j]='\0';
n=printinorder(s,0,inorder);
char c;
while(1){
    scanf("%c",&c);
    if(c=='r'){
scanf("%d",&k);
f=sea(inorder,n,k);
if((f==-1)||(f==0))
    printf("-1\n");
else
        printf("%d\n",inorder[f-1]); }
else if(c=='u'){
scanf("%d",&k);
f=sea(inorder,n,k);
if((f==-1)||(f==n-1))
    printf("-1\n");
else
        printf("%d\n",inorder[f+1]);
}
     else if (c=='i'){
      for(i=0;i<n;i++)
    printf("%d ",inorder[i]);
      printf("\n");
}
    else if(c=='l'){
             scanf("%d",&k);
       if((k>n)||(k<1))
            printf("-1\n");
else{
printf("%d\n",inorder[n-k]);}}
    else if(c=='s'){
      scanf("%d",&k);
     if((k>n)||(k<1)    )      {
        printf("-1\n");
     }
    else{
    printf("%d\n",inorder[k-1]);  }
}
      else if(c=='e')
            break;
}
}

int printinorder(char *s,int i,int * inor){
    static int k=0;
 int m;
 if(s[i+1]==')')
    return 0;
 m=prc(s,i+2);
 printinorder(s,i+2,inor);
   inor[k]=s[i+1];k++;
 printinorder(s,m+1,inor);
 return  k;
}

int prc(char *s,int i){
   int c=0;
   while(1){
    if(s[i]=='(')
        c++;
    if(s[i]==')')
        c--;
    if(c==0)
        return(i);
    i++;  }}

int sea(int inorder[],int n,int k){
    int i=0;
    for(i=0;i<n;i++){
        if(k==inorder[i]){
            return i;
        }}return -1;
}
