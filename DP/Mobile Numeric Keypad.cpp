//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	long long count(int i, int j, int n, vector<vector<char>> &keypad, int dr[], int dc[],
	                vector<vector<long long>> &dp){
	    
	    if(n<=0) return 0;
	    if(n==1) return 1;
	    
	    int num = keypad[i][j] - '0';
	    
	    if(dp[num][n] != -1) return dp[num][n];
	    long long totalCnt = 0;
	    int nr, nc;
	    
	    for(int k=0; k<5; k++){
	        
	        nr = i + dr[k];
	        nc = j + dc[k];
	        
	        if(nr >= 0 and nr < 4 and nc >= 0 and nc < 3 and keypad[nr][nc] != '*' and keypad[nr][nc] != '#'){
	            
	            totalCnt += count(nr, nc, n-1, keypad, dr, dc, dp);
	        }
	    }
	    
	    return dp[num][n] = totalCnt;
	}
	
	long long getCount(int N)
	{
		// Your code goes here
		if(N==1) return 10;
		
		vector<vector<char>> keypad = {
		    {'1','2','3'},
		    {'4','5','6'},
		    {'7','8','9'},
		    {'*','0','#'}
		};
		
		int dr[] = {0, -1, 0, 1, 0};
		int dc[] = {0, 0, 1, 0, -1};
		
		vector<vector<long long>> dp(10, vector<long long>(N+1, -1));
		long long totalCnt = 0;
		
		for(int i=0; i<4; i++){
		    
		    for(int j=0; j<3; j++){
		        
		        if(keypad[i][j] != '*' and keypad[i][j] != '#'){
		            
		            totalCnt += count(i, j, N, keypad, dr, dc, dp);
		        }
		    }
		}
		
		return totalCnt;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
