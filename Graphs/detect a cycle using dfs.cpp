class Solution {
  public:
    void addEdges(vector<vector<int>>&adj,vector<vector<int>>&edges)
    {
        int N=edges.size();
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
    }
    bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
    {
        // If the node is already in the recursion stack, a cycle is detected
        if (recStack[u]==true)
            return true;
        
        // If the node is already visited and not in recursion stack(no cycle), no need to check again 
        if (visited[u]==true)
            return false;
        
        // Mark the current node as visited and add it to the recursion stack
        visited[u] = true;
        recStack[u] = true;
        
        // Recur for all neighbors
        for (int x : adj[u])
        {
            if (isCyclicUtil(adj, x, visited, recStack))
                return true;
        }
        
        // Remove the node from the recursion stack
        recStack[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        addEdges(adj,edges);
        vector<bool>vis(V,false);
        vector<bool>stk(V,false);
         // Check for cycles starting from every unvisited node
        for (int node = 0; node < V; node++)
        {
            if (vis[node]==false && isCyclicUtil(adj, node, vis, stk))
                return true; // Cycle found
        }

        return false; // No cycles detected
    }
};
