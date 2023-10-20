//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int tsp(int mask, int pos, vector<vector<int>> &cost, int n, vector<vector<int>> &dp){
        
        if(mask == (1<<n)-1){
            
            return cost[pos][0];
        }
        
        if(dp[mask][pos] != -1) return dp[mask][pos];
        int ans = INT_MAX;
        
        for(int city = 0; city<n; city++){
            
            if((mask & (1 << city)) == 0){
                
                int dist = cost[pos][city] + tsp(mask | (1<<city), city, cost, n, dp);
                ans = min(ans, dist);
            }
        }
        
        return dp[mask][pos] = ans;
    }

    int total_cost(vector<vector<int>>cost){
        // Code here
        
        int n = cost.size();
        
        //int mask = 1;
        // using mask to mark visited nodes
        vector<vector<int>> dp((1<<n), vector<int>(n, -1));
        return tsp(1, 0, cost, n, dp);
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
