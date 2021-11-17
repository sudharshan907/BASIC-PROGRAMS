#include<stdio.h>
#include<string.h>

int check(char *a,char *b);

void main(){
 char a[100],b[100];
 scanf("%[^\n]",a);
 scanf(" %[^\n]",b);
 printf("%d",check(a,b));
}

int check(char *a,char *b){
int la=strlen(a),lb=strlen(b);
int i,j,k;
for(i=0;i<la-lb+1;i++){
j=i;k=0;
while(k<lb){
    if(a[j]!=b[k])
            break;
    j++;k++;
}
if(k==lb)
    return i;
}
return -1;
}

