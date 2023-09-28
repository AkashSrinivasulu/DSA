//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int interleave(int i, int j, string A, string B, string C, vector<vector<int>> &dp){
        
        int n = A.size();
        int m = B.size();
        if(i == n and j == m) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i < n and  A[i] == C[i+j] and j < m and B[j] == C[i+j]){
            
            return dp[i][j] = interleave(i+1, j, A, B, C, dp) or interleave(i, j+1, A, B, C, dp);
        }
        
        if(i < n and A[i] == C[i+j]){
            
            return dp[i][j] = interleave(i+1, j, A, B, C, dp);
        }
        
        if(j < m and B[j] == C[i+j]){
            
            return dp[i][j] = interleave(i, j+1, A, B, C, dp);
        }
        
        return dp[i][j] = 0;
    }
    
    
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        if(A.size() + B.size() != C.size()) return false;
        
        vector<vector<int>> dp(A.size()+1, vector<int> (B.size()+1, -1));
        if(interleave(0, 0, A, B, C,dp)) return true;
        return false;
        
    }

};
