//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

long long int count(long long int n)
{
	//long long int table[n+1],i;
	
	vector<int> arr(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(10);
	
	
	vector<long long int> prev(n+1, 0);
	//memset(table, 0, sizeof(table));
	prev[0]=1;                 // If 0 sum is required number of ways is 1.
	
	for(int i=3; i<=n; i++){
	    prev[i] += prev[i-3];
	}
	
	for(int i=5; i<=n; i++){
	    prev[i] += prev[i-5];
	}
	
	for(int i=10; i<=n; i++){
	    prev[i] += prev[i-10];
	}
	return prev[n];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
