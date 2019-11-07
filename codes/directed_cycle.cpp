bool dfs(int x, bool visited[], vector<int> adj[], unordered_set<int> uset){
    visited[x] = true;
    uset.insert(x);
    for(auto y: adj[x]){
        if(visited[y]){
            if(uset.find(y) != uset.end()) return true;
        }
        else if(dfs(y, visited, adj, uset)) return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V] = {0};
    for(int i=0; i<V; i++){
        if(!visited[i]){
            unordered_set<int> uset;
            if(dfs(i, visited, adj, uset)) return true;
        }
    }
    return false;
}
