//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void generatePara(vector<string> &ans, string s, int open, int close, int n){
        
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        
        if(open < n){
            generatePara(ans, s+'(', open+1, close, n);
        }
        
        if(close < open){
            generatePara(ans, s+')', open, close+1, n);
        }
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        
        vector<string> ans;
        generatePara(ans, "", 0, 0, n);
        return ans;
    }
};
