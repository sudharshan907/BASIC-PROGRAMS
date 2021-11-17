#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prc(char *s,int i);
int plc(char *s,int i);
int findindexforkey(char *s,char c);
int parentindex(char *s,int i);
int siblingindex(char *s,int i);
void printchilds(char *s,int i);

void main(){
    int i=0,d=0,j=0,l,k,n;
    char s[5000],in[5000];

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

    i=findindexforkey(s,k);

    int f=i,g;
    if((f==1)||(f==3)){
        printf("-1");
        return ;
    }
    g=2+prc(s,2);
    if(g==f){
       printf("-1");
        return ;
    }
    i=parentindex(s,i);
    i=siblingindex(s,i);
    printchilds(s,i);
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
    i=i+1;
   }
}

int plc(char *s,int i){
   int c=0;
   while(1){
    if(s[i]==')')
        c++;
    if(s[i]=='(')
        c--;
    if(c==0)
        return(i);
    i=i-1;
   }   }

int findindexforkey(char *s,char c){
     int i;
     for(i=0;s[i]!='\0';i=i+1){
            if(s[i]==c )
            return i;
     }
     return -1;
}

int parentindex(char *s,int i){
if(s[i-2]!=')')
    return (i-2);
else{
    i=plc(s,i-2);
    return (i-1);
}}

int siblingindex(char *s,int i){
int j;
if(s[i-2]!=')'){
        i=prc(s,i-1);
        return(i+2);}

else{
        i=plc(s,i-2);
       return(i+1);
}
}

void printchilds(char *s,int i){
int chi=0;
if(   (s[i+2]!='(')&&(s[i+2]!=')') ){
   chi++;
   printf("%d ",s[i+2]);}

   i=prc(s,i+1);
   if(   (s[i+2]!='(')&&(s[i+2]!=')')){
   chi++;
   printf("%d",s[i+2]);}

   if(chi==0)
    printf("-1");
}








