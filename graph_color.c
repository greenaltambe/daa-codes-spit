#include <stdio.h>

#define V 4

int m_color_util(int graph[V][V], int m, int color[], int v)
{
  if (v == V)
  {
    return 1; // all vertices are colored
  }

  for (int c = 1; c <= m; c++)
  {
    int safe = 1;
    for (int i = 0; i < V; i++)
    {
      if (graph[v][i] && color[i] == c)
      {
        safe = 0;
        break;
      }
    }

    if (safe)
    {
      color[v] = c;
      if (m_color_util(graph, m, color, v + 1))
      {
        return 1;
      }

      color[v] = 0; // backtrack
    }
  }
  return 0;
}

void m_color(int graph[V][V], int m)
{
  int color[V]; // all vertices are uncolored
  for (int i = 0; i < V; i++)
  {
    color[i] = 0;
  }

  // here 0 is passed to keep track of in which recursion we are
  if (m_color_util(graph, m, color, 0) == 0)
  {
    printf("Coloring not possible\n");
  }
  else
  {
    printf("Coloring possible with colors: ");
    for (int i = 0; i < V; i++)
    {
      printf("%d ", color[i]);
    }
    printf("\n");
  }
}

int main()
{
  int graph[V][V] = {
      {0, 1, 1, 0},
      {1, 0, 1, 1},
      {1, 1, 0, 0},
      {0, 1, 0, 0}};

  m_color(graph, 3);
  return 0;
}