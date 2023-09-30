
void dfs(vector<int> adj[], int node, vector<bool> &vis){
    
    vis[node] = true;
    
    for(int adjNode : adj[node]){
        
        if(!vis[adjNode]){
            dfs(adj, adjNode, vis);
        }
    }
}

//last finished vertex in dfs is mother vertex

int Solution::motherVertex(int A, vector<vector<int> > &B) {
    
    vector<int> adj[A+1];
    
    int m = B.size();
    
    for(int i = 0; i<m; i++){
        
        adj[B[i][0]].push_back(B[i][1]);
    }
    
    
    int V;
    vector<bool> visited(A+1, false);
    for(int i = 1; i<=A; i++){
        
        if(!visited[i]){
            dfs(adj, i, visited);
            V = i;
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    dfs(adj, V, visited);
    for(int i = 1; i<A+1; i++){
        
        if(visited[i] == false)
            return 0;
    }
    return 1;
}
