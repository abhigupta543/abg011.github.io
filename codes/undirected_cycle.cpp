bool dfs(int x, int parent, vector<int> adj[], bool visited[], int V){
    visited[x] = true;
    for(auto y: adj[x]){
        if(!visited[y]){
            if(dfs(y, x, adj, visited, V))
                return true;
        }
        else if(y != parent) return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool visited[V] = {0};
   for(int i=0; i<V; i++){
       if(!visited[i]){
           if(dfs(i, -1, adj, visited, V))
                return true;
       }
   }
   return false;
}
