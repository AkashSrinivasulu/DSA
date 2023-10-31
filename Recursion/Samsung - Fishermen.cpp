/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int arr[100];
int gates[4];
int men[4];

int ans = 999999;
int n;


void init(){
    
    for(int i=0; i<100; i++){
        
        arr[i] = 0;
    }
}

int findLeft(int ind){
    
    for(int i = ind-1; i > 0; i--){
        
        if(arr[i] == 0){
            return i;
        }
    }
    
    return 999999;
}

int findRight(int ind){
    
    for(int i = ind; i<=n; i++){
        if(arr[i] == 0){
            return i;
        }
    }
    
    return 999999;
}

void solve(int x, int y, int z, int cur, int val){
    
    if(val > ans) return;
    
    if(men[cur] == 0){
        
        if(cur == x){
            cur = y;
        }
        
        else if(cur == y){
            cur = z;
        }
        
        else {
            
            ans = min(ans, val);
            return;
        }
    }
    
    
    int l = findLeft(gates[cur]);
    int ldis = abs(gates[cur] - l + 1);
    
    int r = findRight(gates[cur]);
    int rdis = abs(r - gates[cur] + 1);
    
    int pos = (ldis > rdis)?r:l;
    int dist = min(ldis, rdis);
    
    if(men[cur] == 1 and (ldis == rdis)){
        
        arr[l] = 1;
        men[cur]--;
        solve(x, y, z, cur, val + ldis);
        arr[l] = 0;
        men[cur]++;
        
        arr[r] = 1;
        men[cur]--;
        solve(x, y, z, cur, val + rdis);
        arr[r] = 0;
        men[cur]++;
    }
    
    else{
        
        arr[pos] = 1;
        men[cur]--;
        solve(x, y, z, cur, val + dist);
        arr[pos] = 0;
        men[cur]++;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        
        cin >> n;
        
        for(int i=1; i<4; i++){
            
            cin >> gates[i] >> men[i];
        }
        
        solve(1, 2, 3, 1, 0); init();
        solve(1, 3, 2, 1, 0); init();
        solve(2, 1, 3, 2, 0); init();
        solve(2, 3, 1, 2, 0); init();
        solve(3, 1, 2, 3, 0); init();
        solve(3, 2, 1, 3, 0); init();
        
        cout<<ans<<endl;
        
        ans = 999999;
    }

    return 0;
}
