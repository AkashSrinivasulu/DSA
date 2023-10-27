/*
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/



// Building table from bottom up
// whenever health points are >0, take 0, else take the -ve value
// finally, add +1 to abs value at top left box

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {

        int n = d.size();
        int m = d[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[n-1][m-1] = min(0, d[n-1][m-1]);

        // last row
        for(int j = m-2; j>=0; j--){

            dp[n-1][j] = min(0, dp[n-1][j+1] + d[n-1][j]); 
        }

        // last col

        for(int j = n-2; j >= 0; j--){
            dp[j][m-1] = min(0, dp[j+1][m-1] + d[j][m-1]);
        }

        for(int i = n-2; i>=0; i--){
            for(int j = m-2; j>=0; j--){

                dp[i][j] = min(0, d[i][j] + max(dp[i+1][j] , dp[i][j+1]));
            }
        }

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return abs(dp[0][0])+1;
    }
};
