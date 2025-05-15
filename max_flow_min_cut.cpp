#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 6

bool bfs(int res_graph[V][V], int source, int sink, int parent[])
{
  bool visited[V];
  for (int i = 0; i < V; i++)
  {
    visited[i] = false;
  }

  queue<int> q;
  q.push(source);
  visited[source] = true;
  parent[source] = -1;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++)
    {
      if (!visited[v] && res_graph[u][v] > 0)
      {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
        if (v == sink)
        {
          return true; // found a path to sink
        }
      }
    }
  }

  return false; // no path found
}


void dfs(int res_graph[V][V], int source, bool visited[])
{
  visited[source] = true;
  for (int v = 0; v < V; v++)
  {
    if (res_graph[source][v] > 0 && !visited[v])
    {
      dfs(res_graph, v, visited);
    }
  }
}

void min_cut(int graph[V][V], int source, int sink)
{
  int u, v;

  // copy the original graph to residual graph
  int res_graph[V][V];
  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      res_graph[u][v] = graph[u][v];

  int parent[V]; // filled by BFS to store the path
  int max_flow = 0;

  while (bfs(res_graph, source, sink, parent))
  {
    int path_flow = INT_MAX;
    // move from sink to source
    for (v = sink; v != source; v = parent[v])
    {
      u = parent[v];
      path_flow = min(path_flow, res_graph[u][v]); // min between the path flow and the flow between u and v
    }

    // update the residual graph
    for (v = sink; v != source; v = parent[v])
    {
      u = parent[v];
      res_graph[u][v] -= path_flow; // reduce the flow in the forward direction
      res_graph[v][u] += path_flow; // add the flow in the reverse direction
    }

    max_flow += path_flow;
  }

  cout << "The maximum possible flow is " << max_flow << endl;
  // fint the min cur edges
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  dfs(res_graph, source, visited); // looks for vertices reachable from source in residual graph
  cout << "The edges in the min cut are: " << endl;
  for (u = 0; u < V; u++)
  {
    for (v = 0; v < V; v++)
    {
      if (visited[u] && !visited[v] && graph[u][v] > 0) // edges from reachable vertices to non-reachable vertices
      {
        cout << u << " - " << v << endl;
      }
    }
  }
}

int main()
{
  int graph[V][V] = {
      {0, 16, 13, 0, 0, 0},
      {0, 0, 10, 12, 0, 0},
      {0, 4, 0, 0, 14, 0},
      {0, 0, 9, 0, 0, 20},
      {0, 0, 3, 7, 0, 4},
      {0, 0, 0, 0, 0, 0}};

  int source = 0;
  int sink = 5;
  min_cut(graph, source, sink);
  return 0;
}
