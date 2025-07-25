#include<stdio.h>
#include<stdlib.h>
int count=0;
int cyclic=0;
int ordercount=0;
struct node{
        int info;
        struct node* next;
};
struct Graph
{
        int vertices;
        int *visited;
        struct node ** adjLists;
};
typedef struct node* Node;
Node create(int val)
{
        Node temp=(Node)malloc(sizeof(struct node));
        temp->info=val;
        temp->next=NULL;
        return temp;
};
struct Graph* creategraph(int vertices)
{
        struct Graph* graph=malloc(sizeof(struct Graph));
        graph->vertices=vertices;
        graph->adjLists=malloc(vertices * sizeof(struct node*));
        graph->visited=malloc(sizeof(int) * vertices);
        for(int i=0;i<vertices;i++)
        {
                graph->adjLists[i]=NULL;
                graph->visited[i]=0;
        }
        return graph;
};
void bfs(struct Graph* graph,int start)
{
        int rear=-1,front=-1,parentnode;
        graph->visited[start]=1;
        count++;
        int queue[15],parent[15];
        queue[++rear]=start;
        parent[rear]=-1;
        while(rear!=front)
        {
                start=queue[++front];
                parentnode=parent[front];
                printf("-->%c ",start+65);
		// print is for tester
                Node temp=graph->adjLists[start];
                while(temp)
                {
			ordercount++;
                        int connectedvertex=temp->info;
                        if(connectedvertex != parentnode && graph->visited[connectedvertex])
                                cyclic=1;
                        if(graph->visited[connectedvertex]==0)
                        {
                                queue[++rear]=connectedvertex;
                                parent[rear]=start;
                                graph->visited[connectedvertex]=1;
                                count++;
                        }
                        temp=temp->next;
                }


        }
};
void tester()
{
        int n;
        printf("Enter the number of vertices : \n");
        scanf("%d",&n);
        struct Graph* g=creategraph(n);
        Node temp;int key;
        printf("Enter the adjacenecy list :\n");
        for(int i=0;i<g->vertices;i++)
        {
                printf("Enter 1 for the vertices adjacent to %c : \n",i+65);
                for(int j=0;j<g->vertices;j++)
                {
                        printf("\n%c : ",j+65);
                        scanf("%d",&key);
                        if(key==1)
                        {
                                Node new=create(j);
                                new->next=g->adjLists[i];
                                g->adjLists[i]=new;
                        }
                }
		printf("\n");
        }
        for(int i=0;i<n;i++)
        {
                Node temp=g->adjLists[i];
                printf("The vertex adjacent to %c is : ", i+65);
                while(temp)
                {
                        printf("%c ",temp->info+65);
                        temp=temp->next;

                }
                printf("\n");
        }
        printf("BFS TRAVERSAL STARTING FROM NODE %C\n",65);
        bfs(g,0);
        if(cyclic)
                printf("\nThe graph is cyclic\n");
        else
                printf("\nThe graph is not cyclic\n");
	if(count==g->vertices)
         printf("\nThe graph is connected \n");
        else
        {
        printf("\nThe graph is not connected \n");
        int start=1;
        while(count!=g->vertices)
        {
                if(g->visited[start]!=1)
                        bfs(g,start);
                start++;
        }
        }
}
void plotter(int k) {
    FILE *f1 = fopen("bfsbest_list.txt", "a");
    FILE *f2 = fopen("bfsworst_list.txt", "a");
	
    for (int v = 1; v <= 10; v++) {
	    int n;
	    n=v;
	    Node temp;
        struct Graph* g = creategraph(n);

        if (k == 0) {
            for (int i = 0; i < g->vertices-1; i++) {
                
                        Node new = create(i+1);
                        new->next = g->adjLists[i];
                        g->adjLists[i] = new;
           
            }
        } 
	if(k==1)
	{
		
	   for(int i=0;i<g->vertices;i++)
	  {
	    for(int j=0;j<g->vertices;j++)
	    {
		 if(i!=g->vertices-j-1)
 		{
	 	Node nn=create(g->vertices-j-1);
		 nn->next = g->adjLists[i];
		 g->adjLists[i] = nn;
 		}
	    }
	  }
	}
	ordercount=0;
        bfs(g, 0);
        if (k == 0)
            fprintf(f1, "%d\t%d\n", n, ordercount);
        else
            fprintf(f2, "%d\t%d\n", n, ordercount);
}
fclose(f1);
fclose(f2);
}
void main()
{
	for(;;)
	{
		int key;
		printf("Enter your choice:\n1.To Test\n2.To Plot\nOther to exit\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1: tester();
				break;
			case 2: for(int i=0;i<2;i++)
					plotter(i);
				break;
			default: exit(1);
		}
	}
}
