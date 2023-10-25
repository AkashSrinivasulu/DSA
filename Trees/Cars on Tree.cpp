//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int dfs(vector<int> adj[], int node, int par, int d[]){
        
        // if node is leaf, return 0
        if(adj[node].size() == 1 and adj[node][0] == par)
            return 0;
            
        int dist = INT_MAX;
        
        for(auto it : adj[node]){
            
            if(it != par){
                
                int d1 = dfs(adj, it, node, d);
                dist = min(dist, d1);
            }
        }
        
        return d[node] = 1 + dist;
    }
    
    long long dfs2(vector<int> adj[], int node, int par, int cur, int d[], int tim, int k){
        if(adj[node].size() == 1 and adj[node][0] == par)
            return tim;
            
        if(cur == 0){
            
            tim += d[node];
            cur = k;
        }
        
        long long ans = 0;
        
        for(auto it : adj[node]){
            
            if(it != par){
                long long t = dfs2(adj, it, node, cur-1, d, tim+1, k);
                ans = max(t, ans);
            }
        }
        
        return ans;
        
    }
    
    long long solve(int n, int k, vector<int> &p)
    {
        // add your code here
        // build a graph out of the array
        
        vector<int> adj[n+1];
        
        for(int i=1; i<n; i++){
            
            int u = p[i];
            int v = i+1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        // find distace from each node to its nearest leaf
        
        int d[n+1];
        
        dfs(adj, 1, -1, d);
        
        // do one more dfs to find the min time for all the 
        
        return dfs2(adj, 1, -1, k, d, 0, k);
    }
};
