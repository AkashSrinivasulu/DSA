#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	
	int func(int ind, int W, int cost[], vector<vector<int>> &dp){
	    
	    if(W == 0) return 0;
	    
	    if(W < 0 or ind < 0) return (int)1e8;
	    
	    if(dp[ind][W] != -1) return dp[ind][W];
	    // -1 case
	    if(cost[ind] < 0){
	        
	        return dp[ind][W] = min((int)1e8, func(ind-1, W, cost, dp));
	    }
	    
	    // if weight is less than W, we can take it or not
	    int take, notTake;
	    //notTake = func(ind-1, W, cost, dp);
	    if(ind + 1 <= W){
	        
	        notTake = func(ind-1, W, cost, dp);
	        
	        take = cost[ind] + func(ind, W - (ind+1), cost, dp);
	        
	        return dp[ind][W] = min(take, notTake);
	    }
	    
	    //return dp[ind][W] = min(take, notTake);
	    return dp[ind][W] = func(ind-1, W, cost, dp);
	}
	
	
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        
        //int ans = INT_MAX;
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
        int res = func(N-1, W, cost, dp);
        
        if(res == (int)1e8) return -1;
        return res;
	} 
};
