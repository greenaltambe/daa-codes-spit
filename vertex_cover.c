#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int vertex;
  struct Node *next;
} Node;

typedef struct Graph
{
  int V;
  Node **adj; // adjacency list of nodes
} Graph;

// create a new node with v
Node *create_node(int v)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

// create a graph with V vertices
Graph *create_graph(int V)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->adj = (Node **)malloc(V * sizeof(Node *));
  for (int i = 0; i < V; i++)
  {
    graph->adj[i] = NULL;
  }

  return graph;
}

void add_edge(Graph *graph, int u, int v)
{
  Node *new_node_u = create_node(u);
  if (graph->adj[v] == NULL)
  {
    graph->adj[v] = new_node_u;
  }
  else
  {
    Node *temp = graph->adj[v];
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = new_node_u;
  }

  Node *new_node_v = create_node(v);
  if (graph->adj[u] == NULL)
  {
    graph->adj[u] = new_node_v;
  }
  else
  {
    Node *temp = graph->adj[u];
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = new_node_v;
  }
}

void get_vertex_cover(Graph *graph)
{
  int V = graph->V;
  int *visited = (int *)calloc(V, sizeof(int));

  for (int u = 0; u < V; u++)
  {
    if (!visited[u])
    {
      Node *temp = graph->adj[u];
      while (temp)
      {
        int v = temp->vertex;
        if (!visited[v])
        {
          visited[u] = 1;
          visited[v] = 1;
          break;
        }
        temp = temp->next;
      }
    }
  }

  for (int i = 0; i < V; i++)
  {
    if (visited[i])
    {
      printf("%d ", i);
    }
  }

  printf("\n");
  free(visited);
}

int main()
{
  int V, E;
  printf("Enter number of vertices and edges: ");
  scanf("%d %d", &V, &E);

  Graph *g = create_graph(V);

  printf("Enter edges (u v):\n");
  for (int i = 0; i < E; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    add_edge(g, u, v);
  }

  printf("Vertex cover of the graph:\n");
  get_vertex_cover(g);

  // Free the graph memory
  for (int i = 0; i < V; i++)
  {
    Node *temp = g->adj[i];
    while (temp)
    {
      Node *node = temp;
      temp = temp->next;
      free(node);
    }
  }
  free(g->adj);
  free(g);
  return 0;
}