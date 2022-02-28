#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Edge{	int s,d,c;     };

struct Graph{   int V,E;  struct Edge *edges;   };

typedef struct routetable {    int totalcost[50];	int prev[50];   }rt;  //supports only upto V=50

struct Graph* create(int v,int e);

int nearestnode(int dist[],bool set[],int V);

int dijkstra(struct Graph *g,int s,bool active[]);

//removed path fn no need of it now

rt *table;

int main()
{
     int v,e,down;
	scanf("%d %d",&v,&e);
	struct Graph *g = create(v,e);
	int x,y,z;
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		g->edges[i].s = x;  // changed these to original bcz input is in indices form(not x-1)
		g->edges[i].d= y;  // this too(not y-1)
		g->edges[i].c = z;
		//input format:for input enter indices(0-based) for x and y and cost values as it is.
	}
	table = (rt *)malloc(v*sizeof(rt));
	//***********extra code apart from original q starts here and there in dijkstra funtion code also refer it
	scanf("%d",&down);
	if(down==0 || down==v-1){   printf("-1\n");   return 0;  }
	//if src or dest itself down then definitely no path so simply return
	bool active[v];
	for(int i=0;i<v;i++)
    active[i]=true;
    active[down]=false;
    //extra code end
	//here no need to call for all vertex as src just call for 0 as src that's it
	dijkstra(g,0,active);
//now just print totalcost from 0 to v-1h
	if(   table[0].totalcost[v-1]  !=INT_MAX ) 	printf("%d\n",table[0].totalcost[v-1]);
	else    printf("-1\n");
	// i forgot this case that still distance can be INF(no path) even though src and dest are not down.realised this from
	//subbu anna code and testcases given in modification pdf(if the router in middle which connects is down the dist
    //will become infinity
}

struct Graph* create(int v,int e)
{
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = v;
	g->E = e;
	g->edges = malloc(e*sizeof(struct Edge));
	return g;
}

int dijkstra(struct Graph *g,int s,bool active[])
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
    //****extra code apart from original code
            if(active[u]==false || active[v]==false){
                continue;
            }
            //1.might get a doubt that even though we are terminating this iteration here,next iteration
            //fn call will also return same vertex bcz it is minimum still and lead to an infinite loop
            //this will happen if not marked this returned vertex as marked once returned.if marked no problem
            //2.might get a doubt that we can put this stopping outside this for loop also immediately after
            //returning nearesttnode value and after marking.but that doesnot work bcz if we do that we only consider
            //down vertex as not working but will consider all edges attached to it.if put here only we can avoid both
            //down vertex and all edges attached to it.
    //*****************************************extra code ends here
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
}=


int nearestnode(int dist[],bool set[],int V)
{
    //no need to check whether active here also bcz we are eliminating edges which start or end with down  vertex
    //after this anyway
    //might think we should not consider down edges here and we should not return that vertex but that is also ok bcz
    //that iteration will be stopped and will call another fn call for this fn again after marking down vertex as visited.
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

