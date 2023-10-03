int Solution::candy(vector<int> &A) {
    
    int n = A.size();
    vector<int> candies(n, 1);
    int ans = 0;
    //do forward pass and check for neighbours
    for(int i=0; i<A.size()-1; i++){
        
        if(A[i+1] > A[i]){
            candies[i+1] = candies[i]+1;
        }
    }
    
    //do backward pass and check for neighbours
    for(int i = n-2; i>=0; i--){
        
        if(A[i] > A[i+1] && candies[i] <= candies[i+1] ){
            candies[i] = candies[i+1]+1;
        }
        
        ans += candies[i];
    }
    
    ans += candies[n-1];
    
    return ans;
    
}
