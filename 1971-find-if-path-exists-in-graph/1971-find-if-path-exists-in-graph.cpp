class Solution {
private:
  bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int curr, int destination) {
    vis[curr] = 1;
    if (curr == destination) return 1;
    for (int v : graph[curr]) {
      if (vis[v]) continue;
      if (dfs(graph, vis, v, destination)) return 1;
    }
    return 0;
  }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> graph(n);
      for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
      }   
      vector<bool> vis(n);
      if (dfs(graph, vis, source, destination)) return 1;
      return 0;
    }
};