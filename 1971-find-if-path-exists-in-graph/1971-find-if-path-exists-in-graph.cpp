class Solution {
public:
    bool dfs(int cur, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[cur] = true;
        if (cur == destination)
            return true;
        int v = graph[cur].size();
        for (int i = 0; i < v; i++) {
            if (visited[graph[cur][i]])
                continue;
            if (dfs(graph[cur][i], destination, graph, visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int e = edges.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < e; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        if (dfs(source, destination, graph, visited))
            return true;
        else
            return false;
    }
};