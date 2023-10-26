/*Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.*/


class Solution {
public:


    /*
    
    find factors of every num. A num will have 2 factors

    n = n1 * n2

    current ways =  1 always coz every leaf node can be a tree

    ways[n] = ways[n1] * ways[n2] ----> store these nums in a map, kind of dp

    observe, parent node > children nodes ----> sort the array

    for every num in sorted array, check if any factor is there bofore that num

    if a factor is there, we can find other factor easily by divinding that num with factor.

    now multiply the no of ways to form both factors and add it to current ans
    
    store this ans for current node

    
    */
    int mod = 1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        long long cur_ans = 1;
        long long ans = 0;

        unordered_map<long long, long long> dp;
        for(int i = 0; i<n; i++){

            cur_ans = 1; // single node is leaf node and it also counts

            for(int j = 0; j<i; j++){

                if(arr[i] % arr[j]) continue;

                int num1 = arr[j];
                int num2 = arr[i]/arr[j];

                cur_ans = (cur_ans + (dp[num1] * dp[num2])%mod)%mod;
            }

            dp[arr[i]] = cur_ans;
            ans = (ans + cur_ans)%mod;
        }

        return (int)ans;
        
    }
};
