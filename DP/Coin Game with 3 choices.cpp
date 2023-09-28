//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int func(int n, int x, int y, vector<int> &dp){
	    if(n == 0) return false;
	    if(n == x or n == y or n == 1) return true;
	    if(n<0) return true;
	    if(n < x and n < y) return n%2;
	    
	    if(dp[n] != -1) return dp[n];
	    
	    int ans = 0;
	    
	    if(n > x){
	        
	        ans |= (func(n-x-x, x, y, dp) and func(n-x-y, x, y, dp) and func(n-x-1, x, y, dp));
	    }
	    
	    if(n > y){
	        ans |= (func(n-y-x, x, y, dp) and func(n-y-y, x, y, dp) and func(n-y-1, x, y, dp));
	    }
	    
	    ans |= (func(n-1-x, x, y, dp) and func(n-1-y, x, y, dp) and func(n-2, x, y, dp));
	    
	    return dp[n] = ans;
	}
	
	int findWinner(int N, int x, int y)
	{
		// Your code goes here
		
		//vector<int> dp(N+1, -1);
		//return func(N, X, Y, dp) ? 1 : 0;
		
		// tabulation
		
		// if A lose n-x the game, it will will nth game
		
		vector<bool> dp(N+1, false);
		
		dp[0] = false;
		dp[1] = true;
		
		for(int i=2; i<=N; i++){
		    
		    if(i-1 >= 0 and !dp[i-1]) dp[i] = true;
		    else if(i-x >= 0 and !dp[i-x]) dp[i] = true;
		    else if(i-y >= 0 and !dp[i-y]) dp[i] = true;
		    else dp[i] = false;
		}
		
		return (int)dp[N];
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
