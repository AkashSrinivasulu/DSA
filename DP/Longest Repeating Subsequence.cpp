//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



// Longest common subsequence between same string but indixes should not be same

class Solution {
	public:
	
	    int lcs(string str1, string str2, int ind1, int ind2, vector<vector<int>> &dp){
	        
	        if(ind1<0 or ind2<0) return 0;
	        
	        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	        
	        if(str1[ind1] == str2[ind2] and ind1 != ind2){
	            
	            return dp[ind1][ind2] = 1 + lcs(str1, str2, ind1-1, ind2-1, dp);
	        }
	        
	        else {
	            return dp[ind1][ind2] = max(lcs(str1, str2, ind1, ind2-1, dp), lcs(str1, str2, ind1-1, ind2, dp));
	        }
	    }
	    
	    
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int n = str.size();
		    
		    string str1 = str;
		    string str2 = str;
		    //vector<vector<int>> dp(n, vector<int> (n, -1));
		    //return lcs(str, str, n-1, n-1, dp);
		    
		    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
		    
		    for(int ind1=1; ind1<=n; ind1++){
		        for(int ind2=1; ind2<=n; ind2++){
		            
		            if(str1[ind1-1] == str2[ind2-1] and ind1-1 != ind2-1){
		                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
	                }
	        
	                else {
	                    dp[ind1][ind2] = max(dp[ind1][ind2-1], dp[ind1-1][ind2]);
	                }
		            
		        }
		    }
		    
		    return dp[n][n];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
