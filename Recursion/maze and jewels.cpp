/*

  There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
*/

#include<iostream>
using namespace std;

int arr[100][100];
int vis[100][100];
int path[100][100];

int ans;
int n;

void printPath(){
    
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int x, int y, int val){
    
    if(x == n-1 and y == n-1){
        
        if(val > ans){
            ans = val;
        
            for(int i=0; i<n; i++){
                
                for(int j=0; j<n; j++){
                    
                    if(vis[i][j]){
                        path[i][j] = 5;
                    }
                    else{
                        path[i][j] = arr[i][j];
                    }
                }
            }
            
            return;
        }
    }
    
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    
    for(int k=0; k<4; k++){
        
        int nx = x+dx[k];
        int ny = y+dy[k];
        
        if(nx >= 0 and nx < n and ny >=0 and ny < n and !vis[nx][ny] and arr[nx][ny] != 1){
            
            if(arr[nx][ny] == 0){
                vis[nx][ny] = 1;
                solve(nx, ny, val);
                vis[nx][ny] = 0;
            }
            
            else{
                vis[nx][ny] = 1;
                solve(nx, ny, val+1);
                vis[nx][ny] = 0;
            }
        }
    }
    
    
}

int main(){
    
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        
        cin >> n;
        ans = 0;
        
        for(int i = 0; i<n; i++){
            
            for(int j = 0; j<n; j++){
                
                cin >> arr[i][j];
                vis[i][j] = 0;
                path[i][j] = 0;
            }
        }
        
        if(arr[0][0] == 0){
            
            solve(0, 0, 0);
        }
        
        else if(arr[0][0] == 2){
            
            solve(0,0,1);
        }
        
        cout<<ans<<endl;
        printPath();
    }
}
