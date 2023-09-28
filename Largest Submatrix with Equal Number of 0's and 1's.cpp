#include <bits/stdc++.h> 

bool count(int *temp, int &start, int &end, int n){

    int sum[n];
    memset(sum, 0, sizeof(sum));

    int maxLen = 0;

    sum[0] = temp[0];
    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + temp[i];
    }

    int cur = 0;
    unordered_map<int, int> preSum;

    for(int i = 0; i<n; i++){

        if(sum[i] == 0){

            start = 0;
            end = i;
            maxLen = i+1;
        }

        else if(preSum.find(sum[i]) == preSum.end()){

            preSum[sum[i]] = i;
        }

        else{

            if( maxLen < (i-preSum[sum[i]]) ){

                maxLen = i-preSum[sum[i]];
                start = preSum[sum[i]]+1;
                end = i;
            }
        }
    }

    //cout<<"maxLen = "<<maxLen<<" ";
    if(maxLen == 0) return false;
    return true;
}

int maximumArea(vector<vector<int>>& mat, int n, int m)
{
    // Write your code here.

    int r = mat.size();
    int c = mat[0].size();
    int maxArea = 0;
    
    bool cur = false;

    int startRow, endRow;
    int temp[n];
    for(int left = 0; left<c; left++){
        memset(temp, 0, sizeof(temp));
        for(int right = left; right<c; right++){

            for(int i=0; i<r; i++){

                temp[i] += mat[i][right] ? 1 : -1;   
            }

            cur = count(temp, startRow, endRow, r);
            
            if(cur){
                //cout<<(int)cur<<" ";
                int area = (endRow-startRow+1)*(right-left+1);
                maxArea = max(maxArea, area);
            }

        }
    }

    return maxArea;
}
