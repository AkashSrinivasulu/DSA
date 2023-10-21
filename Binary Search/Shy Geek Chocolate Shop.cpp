//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in non-decreasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
public:
    Shop shop;
    unordered_map<int, long> store; 
    Solution(Shop shop){
        // Constructor
        this->shop = shop;
        store.clear();
    }
    
    int getPrice(int i){
        
        i--;
        if(store.find(i) != store.end()) return store[i];
        
        return store[i] = shop.get(i);
    }
    
    
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        
        int low = 0, high = n;
        
        int ans = 0;
        ans += k/getPrice(high);
        k %= getPrice(high);
        
        while(k > 0){
            
            low = 0;
            
            // binary search
            while(low < high-1){
                
                int mid = (low+high)/2;
                
                if(getPrice(mid) <= k) low = mid;
                else high = mid;
            }
            
            if(low == 0) break;
            
            ans += k/getPrice(low);
            k %= getPrice(low);
        }
        
        return ans;
    }

};
