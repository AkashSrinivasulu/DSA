class Solution
{
  public:
  
  
    long long int ksubstr(string s, int k){
        
        long long int n = s.size();
        if(n == 0) return 0;
        
        unordered_map<char, long long int> m;
        
        long long int left = 0, cnt = 0;
        
        for(int i = 0; i<n; i++){
            
            m[s[i]]++;
            
            while(m.size() > k){
                m[s[left]]--;
                if(m[s[left]] == 0) m.erase(s[left]);
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
