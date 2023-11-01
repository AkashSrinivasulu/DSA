/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/

http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn

*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One

Similr Problem - https://ide.codingblocks.com/s/95965


You’ll be given a grid as below:

    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x

In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get 
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone 
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:

    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x

  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the 
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. 
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x

   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/
#include <iostream>

using namespace std;

int arr[100][5];
int n;
int ans = -1000;

void bombMat(int row){
    
    if(row < 0) return;
    
    for(int i = row; i>= (row -4) and i >= 0; i--){
        
        for(int j=0; j<5; j++){
            
            if(arr[i][j] == 2) arr[i][j] = 10;
        }
    }
}

void unBomb(int row){
    
    if(row < 0) return;
    
    for(int i = row; i>= (row -4) and i >= 0; i--){
        
        for(int j=0; j<5; j++){
            
            if(arr[i][j] == 10) arr[i][j] = 2;
        }
    }
}



void solve(int row, int col, int b, int score){
    
    if(col < 0 or col >= 5 or row >= n){
        
        return;
    }
    
    if(row < 0){
        ans = max(ans, score);
        return;
    }
    
    // if met with enemy and bomb is used already
    if(arr[row][col] == 2 and b){
        ans = max(ans, score);
        return;
    }
    
    else if(arr[row][col] == 1){
        
        solve(row-1, col, b, score+1);
        solve(row-1, col-1, b, score+1);
        solve(row-1, col+1, b, score+1);
        
    }
    
    else if(arr[row][col] == 0){
        
        solve(row-1, col, b, score);
        solve(row-1, col-1, b, score);
        solve(row-1, col+1, b, score);
        
    }
    
    else{
        
        bombMat(row);
        b = 1;
        solve(row-1, col, b, score);
        solve(row-1, col-1, b, score);
        solve(row-1, col+1, b, score);
        unBomb(row);
        b = 0;
        
    }
    
    
}

int main()
{
    int t; 
    
    cin >> t;
    
    for(int k=0; k<t; k++){
        cin >> n;
        //int arr[n+2][5];
        for(int i = 0; i<n; i++){
            
            for(int j=0; j<5; j++){
                
                cin >> arr[i][j];
            }
        }
    
        solve(n-1, 3, 0, 0);
        solve(n-1, 2, 0, 0);
        solve(n-1, 1, 0, 0);
        cout<<ans<<endl;
    }

    return 0;
}
