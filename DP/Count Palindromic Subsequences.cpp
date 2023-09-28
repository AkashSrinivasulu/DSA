//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    /*You are required to complete below method */
    
    long long countPals(int l, int r, string str, vector<vector<long long>> &dp){
        
        if(l > r) return 0LL;
        
        if(l == r) return 1LL;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        if(str[l] == str[r]){
            
            return dp[l][r] = 1LL + countPals(l+1, r, str, dp) + countPals(l, r-1, str, dp);
        }
        
        else{
            
            return dp[l][r] = countPals(l+1, r, str, dp) + countPals(l, r-1, str, dp) - countPals(l+1, r-1, str, dp);
        }
    }
    
    long long int  countPS(string str)
    {
       //Your code here
       
       int n = str.size();
       vector<vector<long long>> dp(n, vector<long long>(n, 0));
       //return countPals(0, n-1, str, dp);
       
       int mod = 1e9+7;
       
       // Tabulation
       
       for(int i=0; i<n; i++){
           dp[i][i] = 1LL;
       }
       
       for(int l = 2; l<=n; l++){
           for(int r=0; r<=n-l; r++){
               
               int k = l + r - 1;
               if(str[r] == str[k]){
            
                    dp[r][k] = (1LL + dp[r+1][k] + dp[r][k-1]) % mod;
                }
                
                else{
                    
                    dp[r][k] = (dp[r+1][k] + dp[r][k-1] - dp[r+1][k-1]) % mod;
                }
            }
       }
       
       return dp[0][n-1] % mod;
       
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
