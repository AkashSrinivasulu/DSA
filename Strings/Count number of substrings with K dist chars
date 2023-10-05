//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  
    long long int ksubstr(string s, int k){
        
        long long int n = s.size();
        if(n == 0) return 0;

// use array instead of using map to reduce time complexity
        //unordered_map<char, long long int> m;
        int freq[26] = {0};
        
        long long int left = 0, cnt = 0;
        int dist = 0;
        
        for(int i = 0; i<n; i++){
            
            //m[s[i]]++;
            freq[s[i]-'a']++;
            
            if(freq[s[i]-'a'] == 1) dist++;
            
            /*while(m.size() > k){
                m[s[left]]--;
                if(m[s[left]] == 0) m.erase(s[left]);
                left++;
            }*/
            
            while(dist > k){
                
                freq[s[left]-'a']--;
                if(freq[s[left]-'a'] == 0) dist--;
                left++;
            }
            
            cnt += i - left + 1;
        }
        
        return cnt;
    }
    
    
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	return ksubstr(s, k) - ksubstr(s, k-1);
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
