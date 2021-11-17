#include<stdio.h>
#include<stdlib.h>
int d[10000];
int G[10000][10000],b[]={1,2,3,4,5,6};
void graphcoloring(int w,int z,int y);
int main(){
  int p,q,r,s,t,u;
  scanf("%d %d",&p,&q);
  for(r=0;r<p;r++){
    for(s=0;s<p;s++){
      G[r][s]=0;  }}
  for(r=0;r<q;r++){
    scanf("%d %d",&t,&u);
    G[u][t]=1;
    G[t][u]=1;}
   graphcoloring(q,p,1);
  for(r=0;r<p;r++)
    printf(" %c\n",d[r]+96);
  return 0;
}
void graphcoloring(int w,int z,int y){
   int q[6],e,g,h;
   if(y==z)
   	d[y-1]=1;
   else{
   	graphcoloring(w,z,y+1);
   	for(e=0;e<6;e++)
   		q[e]=1;
   	for(g=0;g<z;g++){
   		if(G[g][y-1]==1){
   			for(h=0;h<6;h++){
   				if(d[g]==b[h]){
   					q[h]=0;
				   }   }  }  }
       }
   for(g=0;g<6;g++){
   	if(q[g]==1){
   	    d[y-1]=b[g];
   		break; }
	}
                                  }
