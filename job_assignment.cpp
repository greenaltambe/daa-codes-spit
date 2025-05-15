#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
  vector<int> assigned;   // workers assigned to jobs
  vector<bool> available; // available workers
  int job;                // current job
  int cost;               // cost so far
  int lower_bound;

  // this is for the priority queue
  bool operator>(const Node &other) const
  {
    return lower_bound > other.lower_bound;
  }
};

int calculate_lower_bound(vector<vector<int>> &cost_matrix, int job, vector<bool> &available, int current_cost)
{
  int n = cost_matrix.size();
  int lower_bound = current_cost;

  for (int i = job + 1; i < n; i++)
  {
    int min_cost = INT_MAX;
    for (int j = 0; j < n; j++)
    {
      if (available[j])
      {
        min_cost = min(min_cost, cost_matrix[i][j]);
      }
    }

    lower_bound += min_cost;
  }

  cout << "Lower bound for job " << job << ": " << lower_bound << endl;

  return lower_bound;
}

int find_min_cost(vector<vector<int>> &cost_matrix)
{
  int n = cost_matrix.size();

  priority_queue<Node, vector<Node>, greater<Node>> pq;

  Node root;
  root.assigned = vector<int>(n, -1);
  root.available = vector<bool>(n, true);
  root.job = -1;
  root.cost = 0;
  root.lower_bound = calculate_lower_bound(cost_matrix, -1, root.available, 0);

  pq.push(root);
  int min_cost = INT_MAX;
  while (!pq.empty())
  {
    Node node = pq.top();
    pq.pop();

    int next_job = node.job + 1;
    if (next_job == n)
    {
      min_cost = min(min_cost, node.cost);
      continue;
    }
    cout << "Node cost: " << node.cost << endl;

    for (int w = 0; w < n; w++)
    {
      if (node.available[w])
      {
        Node child = node;
        child.assigned[next_job] = w;
        child.available[w] = false;
        child.job = next_job;
        child.cost = node.cost + cost_matrix[next_job][w];
        cout << "Child cost: " << child.cost << endl;
        child.lower_bound = calculate_lower_bound(cost_matrix, next_job, child.available, child.cost);

        if (child.lower_bound < min_cost)
        {
          pq.push(child);
        }
      }
    }
  }

  return min_cost;
}

int main()
{
  vector<vector<int>> cost_matrix = {
      {9, 2, 7, 8},
      {6, 4, 3, 7},
      {5, 8, 1, 8},
      {7, 6, 9, 4}};

  cout << "Min cost: " << find_min_cost(cost_matrix) << endl;
  return 0;
}