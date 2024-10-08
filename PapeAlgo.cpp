// C++ implementation for
// D'Esopo-Pape algorithm
#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
 
vector<int> desopo(vector<vector<int>> &graph) 
{
   
  // Number of vertices in graph
  int v = graph.size();
 
  // Adjacency list of graph
  map<int, vector<pair<int, int>>> adj;
  for(int i = 0; i < v; i++) {
    for(int j = i + 1; j < v; j++)
    {
      if (graph[i][j] != 0) 
      {
        adj[i].push_back({graph[i][j], j});
        adj[j].push_back({graph[i][j], i});
      }
    }
  }
 
  // Queue to store unoperated vertices
  deque<int> q;
 
  // Distance from source vertex
  // distance =[float('inf')]*v
  vector<int> distance(v, inf);
 
  // Status of vertex
  vector<bool> is_in_queue(v, false);
 
  // let 0 be the source vertex
  int source = 0;
  distance = 0;
  q.push_back(source);
  is_in_queue = true;
 
  while (!q.empty())
  {
     
    // Pop from front of the queue
    int u = q.front();
    q.pop_front();
    is_in_queue[u] = false;
 
    // Scan adjacent vertices of u
    for(auto e : adj[u]) 
    {
       
      // e <- [weight, vertex]
      if (distance[e.second] > 
          distance[u] + e.first)
      {
        distance[e.second] = distance[u] + e.first;
        if (!is_in_queue[e.second])
        {
           
          // if e.second is entering
          // first time in the queue
          if (distance[e.second] == inf)
             
            // Append at back of queue
            q.push_back(e.second);
          else
             
            // Append at front of queue
            q.push_front(e.second);
           
          is_in_queue[e.second] = true;
        }
      }
    }
  }
  return distance;
}
 
// Driver Code
int main(int argc, char const *argv[])
{
   
  // Adjacency matrix of graph
  vector<vector<int>> graph = { { 0, 4, 0, 0, 8 },
                                { 0, 0, 8, 0, 11 },
                                { 0, 8, 0, 2, 0 },
                                { 0, 0, 2, 0, 1 },
                                { 8, 11, 0, 1, 0 } };
  for(auto i : desopo(graph))
  {
    cout << i << " ";
  }
  return 0;
}
 
