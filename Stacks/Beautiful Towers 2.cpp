class Solution {
public:

    // We wiil try to make every elem as peak element
    // so, we will find prev small and next small indexes using stack
    // using these prev small and next small, we will find left sums and right sums
    // add these two sums and subtract the final sum with maxHeights as we are adding maxHeights
    // two times when we add leftsum and rightsum
    // return the max
    long long maximumSumOfHeights(vector<int>& maxHeights) {

        int n = maxHeights.size();
        vector<long long> leftSum(n, 0), rightSum(n,0);

        vector<long long> prevSmall(n, -1), nextSmall(n, n);

        stack<int> s;

        s.push(0);
        for(int i = 1; i<n; i++){

            while(!s.empty() and maxHeights[s.top()] >= maxHeights[i])
                s.pop();

            if(!s.empty()) prevSmall[i] = s.top();

            s.push(i);
        }
        
        while(!s.empty()) s.pop();

        // find next small
        s.push(n-1);
        for(int i = n-1; i>=0; i--){

            while(!s.empty() and maxHeights[s.top()] >= maxHeights[i])
                s.pop();

            if(!s.empty()) nextSmall[i] = s.top();
            s.push(i);
        }

        // find left sum and right sum

        leftSum[0] = maxHeights[0];
        for(int i=1; i<n; i++){

            int prev = prevSmall[i];
            int len = i - prev;

            leftSum[i] += (long long) len * maxHeights[i];

            if(prev != -1) leftSum[i] += leftSum[prev];
        }

        rightSum[n-1] = maxHeights[n-1];
        for(int i=n-2; i>=0; i--){

            int next = nextSmall[i];
            int len = next - i;

            rightSum[i] += (long long) len * maxHeights[i];

            if(next != n) rightSum[i] += rightSum[next];
        }

        long long ans = INT_MIN;

        for(int i = 0; i<n; i++){
            ans = max(ans, leftSum[i]+rightSum[i] - maxHeights[i]*1LL);
        }

        return ans;
    }
};
