#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Edge{	int s,d,c;     };

struct Graph{   int V,E;  struct Edge *edges;   };

typedef struct routetable {    int totalcost[50];	int prev[50];   }rt;  //supports only upto V=50

struct Graph* create(int v,int e);

int nearestnode(int dist[],bool set[],int V);

int dijkstra(struct Graph *g,int s);

void printpath(int s, int v);

rt *table;

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
	dijkstra(g,i);

	printf("\nFor LSR,\n");
	for(int i=0;i<v;i++)
	{
		printf("\nat node %d\n",i+1);
		printf("    dest    totalcost    path\n");
		for(int j=0;j<v;j++)
		{
			printf("    %d       %d            ",j+1, table[i].totalcost[j]    );
			if(i!=j){
            printpath(i,j);
            printf("\n");}
            else{
                printf("%d->%d\n",i+1,j+1);
            }
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

void printpath(int s, int v)
{
    if(v==s){   printf("%d", v+1);   return ;   }
    printpath(s, table[s].prev[v]);
    printf("->%d", v+1);
}

int dijkstra(struct Graph *g,int s)
{
	int V=g->V, e=g->E;
	bool set[V]; //to mark already considered nodes/routers

	for(int i=0;i<V;i++)
	{
		set[i] = false;
		table[s].totalcost[i] = INT_MAX;
		table[s].prev[i] = s;
	}
	table[s].totalcost[s] = 0;

	for(int i=0;i<V-1;i++)
	{
		int nearestnodenow = nearestnode(table[s].totalcost,set,V);
		 //greedy step,choosing nearest node to src and relaxing all edges of it in 2 ways.
		set[nearestnodenow] = true;
		for(int j=0;j<e;j++)
		{
			int u = g->edges[j].s;
			int v = g->edges[j].d;
			int w = g->edges[j].c;

			if(u == nearestnodenow)
			{
				if(set[v]==false && table[s].totalcost[v] > w + table[s].totalcost[u])
				{
					table[s].totalcost[v] = w + table[s].totalcost[u];
					table[s].prev[v] = u;
				}
			}
			else if(v == nearestnodenow)
			{
				if(set[u]==false && table[s].totalcost[u] > w + table[s].totalcost[v])
				{
					table[s].totalcost[u] = w + table[s].totalcost[v];
					table[s].prev[u] = v;
				}
			}
		}
	}
}


int nearestnode(int dist[],bool set[],int V)
{
	int min = INT_MAX,index;
	for(int v=0;v<V;v++)
	{
		if(set[v]==false&&dist[v]<min)
		{
			min = dist[v];
			index = v;
		}
	}
	return index;
}

