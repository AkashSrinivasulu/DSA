//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool func(int ind, int n, string A, unordered_map<string, int> dict, vector<int> &dp){
        
        if(ind == n) return true;
        
        if(dp[ind] != -1) return dp[ind];
        
        for(int j=ind; j<n; j++){
            
            string temp = A.substr(ind, j-ind+1);
            if(dict.find(temp) != dict.end() and func(j+1, n, A, dict, dp)){
               return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        // save dict into map
        unordered_map<string, int> dict;
        
        for(auto word : B){
            
            dict[word] = 1;
        }
        vector<int> dp(A.size(), -1);
        if(func(0, A.size(), A, dict, dp)) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
