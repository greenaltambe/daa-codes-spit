#include <stdio.h>
#include <limits.h>

#define V 6 // number of vertices in the graph

void min_cut(int graph[V][V], int source, int sink) {
  
}


int main(void) {
  int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 3, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}
  };

  int source = 0; // source vertex
  int sink = 5;   // sink vertex

  min_cut(graph, source, sink);

  return 0;
}