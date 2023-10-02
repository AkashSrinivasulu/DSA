//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
      vector<int> topoOrder(vector<pair<int, int>> adj[], int v){
          
          int indegree[v] = {0};
          
          //find indegree
          vector<int> ans;
          
          for(int i=0; i<v; i++){
              for(auto adjNode : adj[i]){
                  
                  indegree[adjNode.first]++;
              }
          }
          
          queue<int> q;
          for(int i=0; i<v; i++){
              if(indegree[i] == 0)
                q.push(i);
          }
          
          while(!q.empty()){
              
              int u = q.front();
              q.pop();
              
              ans.push_back(u);
              for(auto adjNode : adj[u]){
                  
                  int v = adjNode.first;
                  indegree[v]--;
                  if(indegree[v] == 0){
                      q.push(v);
                  }
              }
          }
          
          return ans;
      }
      
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            
            vector<int> dist(v, INT_MIN);
            
            
            vector<int> topo;
            
            // form adjlist from edges
            vector<pair<int, int>> adj[v];
            for(auto edge : edges){
                
                adj[edge[0]].push_back({edge[1], edge[2]});
            }
            
            topo = topoOrder(adj, v);
            
            //find distamce
            dist[src] = 0;
            
            for(int i=0; i<v; i++){
                
                int node = topo[i];
                
                if(dist[node] != INT_MIN){
                    for(auto adjNode : adj[node]){
                        
                        int v = adjNode.first;
                        int wt = adjNode.second;
                        
                        if(dist[v] < dist[node] + wt){
                            dist[v] = dist[node]+wt;
                        }
                    }
                }
            }
            return dist;
            
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends
