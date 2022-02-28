#include<stdio.h>
#include<stdlib.h>

struct Edge{	int s,d,c;     };

struct Graph{   int V,E;  struct Edge *edges;   };

typedef struct routetable {    int totalcost[50];	int prev[50];   }rt;  //supports only upto V=50

struct Graph* create(int v,int e);

void bellmanford(struct Graph *g,int s);

void printnext(int s,int v);

rt *table;
int flag=1;

int main()
{
	int v,e,s;
	scanf("%d %d",&v,&e);
	struct Graph *g = create(v,e);
	int x,y,z;
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		g->edges[i].s = x-1;
		g->edges[i].d= y-1;
		g->edges[i].c = z;
		//input format:enter indices(1-based) for x,y and cost values as it is.
	}
	table = (rt *)malloc(v*sizeof(rt));
	for(int i=0;i<v;i++)
	bellmanford(g,i);

	printf("\nFor DVR,\n");
	for(int i=0;i<v;i++)
	{
		printf("\nRouting table at node %d\n",i+1);
		printf("    dest    next    totalcost\n");
		for(int j=0;j<v;j++)
		{
			printf("    %d       ",j+1);
			if(i==j){   printf("%d   ",i+1);    }
			else{    printnext(i,j);    flag=1;     }
			printf("    %d\n",table[i].totalcost[j]);
		}
	}
}


struct Graph* create(int v,int e)
{
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = v;
	g->E = e;
	g->edges = malloc(e*sizeof(struct Edge));
	return g;
}

//fills values of routing table(table[s]) for node s as src
void bellmanford(struct Graph *g,int s)
{
	int V=g->V,e = g->E;

	for(int i=0;i<V;i++)
	{
		table[s].totalcost[i] = 100000;
		table[s].prev[i] = s;
	}
	table[s].totalcost[s] = 0;

	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u = g->edges[j].s;
			int v = g->edges[j].d;
			int w = g->edges[j].c;
			if(table[s].totalcost[v] > w + table[s].totalcost[u] && table[s].totalcost[u] != 10000)
			{
				table[s].totalcost[v] = w + table[s].totalcost[u];
				table[s].prev[v] = u;
			}

			if(table[s].totalcost[u] > w + table[s].totalcost[v] && table[s].totalcost[v] != 10000)
			{
				table[s].totalcost[u] = w + table[s].totalcost[v];
				table[s].prev[u] = v;
			}
		}
	}
}


//return vertex which is having s as prevnode in the path from s to v.
//return next vertex to s in the path from s to v.
void printnext(int s,int v)
{
    if(v==s){  return ;  }
    printnext(s, table[s].prev[v]);
    if(flag==1){   printf("%d   ", v+1);  flag=0;    }
    //capturing the last but one pred of v (s is last pred) and making flag=0 to not print other pred's.
    //notice printf() after rec call,so it will print last but one pred only and not the v itself.
}

