class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        // from every index, find farthest index that can be jumped to
        
        // we can reaach all the points between that poiint and farthest
        
        // like this we can see levels, in BFS fashion
        
        // so, our ans becomes no of levels to reach the last ind
        if(arr[0] == 0) return -1;
        
       int farthest = 0, current = 0, jumps = 0;
       
       for(int i=0; i<n-1; i++){
           
           farthest = max(farthest, i+arr[i]);
           
           if(i == current){
               
               jumps++;
               current = farthest;
           }
       }
        
        if(current >= n-1) return jumps;
        return -1;
    }
};
