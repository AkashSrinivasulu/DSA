//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int dropEggs(int n, int k, vector<vector<int>> &dp){
        
        if(k == 0 or k == 1){
            return k;
        }
        
        if(n == 1){
            return k;
        }
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int res = 0, ans = INT_MAX;
        
        // try from all floors
        for(int x=1; x<=k; x++){
            
            // if the egg breaks in xth floor, we have n-1 eggs and x-1 floors below x
            // else egg wont break from any of the floors below x, we have n eggs and k-x floors above x
            res = max(dropEggs(n-1, x-1, dp), dropEggs(n, k-x, dp));
            
            ans = min(ans, res);
        }
        
        return dp[n][k] = ans+1;
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return dropEggs(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
