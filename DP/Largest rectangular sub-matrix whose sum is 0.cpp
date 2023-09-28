//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  bool sumZero(int *a, int *up, int *down, int n){
      
      unordered_map<int, int> preSum;
      
      int sum = 0, maxLen = 0;
      
      for(int i=0; i<n; i++){
          
          sum += a[i];
          
          if(a[i] == 0 and maxLen == 0){
              *up = i;
              *down =i;
              maxLen = 1;
          }
          
          if(sum == 0){
              if(maxLen < i+1){
                  *up = 0;
                  *down = i;
              }
              maxLen = i+1;
          }
          
          if(preSum.find(sum) != preSum.end()){
              
              int oldLen = maxLen;
              
              maxLen = max(maxLen, i-preSum[sum]);
              
              if(oldLen < maxLen){
                  *down = i;
                  *up = preSum[sum]+1;
              }
          }
          
          else{
              preSum[sum] = i;
          }
      }
      
      return (maxLen != 0);
  }
  
  
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n = a.size();
      int m = a[0].size();
      
      int fup = 0, fdown = 0, fleft = 0, fright = 0;
      int maxi = INT_MIN;
      
      int temp[n];
      
      int up, down;
      
      for(int left = 0; left<m; left++){
          
          memset(temp, 0, sizeof(temp));
          
          for(int right = left; right<m; right++){
              
              for(int i=0; i<n; i++){
                  temp[i] += a[i][right];
              }
              
              bool sum = sumZero(temp, &up, &down, n);
              
              int elems = (down - up + 1)*(right - left + 1);
              
              if(sum && elems > maxi){
                  
                  fup = up;
                  fdown = down;
                  fleft = left;
                  fright = right;
                  maxi = elems;
              }
          }
      }
      
      if(fup == 0 and fdown == 0 and fleft == 0 and fright == 0 and a[0][0] != 0){
          vector<vector<int>> ans;
          return ans;
      }
      
      //cout<<fdown<<" "<<fup<<" "<<fleft<<" "<<fright;
      
      vector<vector<int>> ans(fdown - fup + 1, vector<int> (fright - fleft + 1, 0));
      for(int i = fup; i<=fdown; i++){
          for(int j = fleft; j<=fright; j++){
              
              ans[i-fup][j-fleft] = a[i][j];
          }
      }
      
      return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
