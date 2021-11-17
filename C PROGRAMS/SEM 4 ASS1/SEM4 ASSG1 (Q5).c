#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prc(char *s,int i);
int printinorder(char *s,int i,int * inor);

void main(){
    int i=0,d=0,j=0,l,k,n;
    char s[5000],in[5000];
    int inor[5000];
    scanf("%[^\n]",in);
    l=strlen(in);
    scanf("%d",&k);
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
        i++;
    }
s[j]='\0';
   n=printinorder(s,0,inor);
    printf("%d",inor[k-1]);
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
    i++;
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

