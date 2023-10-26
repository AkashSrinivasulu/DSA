/*
Group integers to gether. Let's call integers intergers in the range [2^i, 2^(i+1)-1] belong to same group.
Given an array, in one operation we can select any even size subarray in which all elements belong to same group
and delete the subarray. Find the min size of array after doing some operations.

*/



// Use stacks when the question is to delete sub arays or array elements and continue operations on remining array elements

class Solution{
	public:
	
	int evenGrouping(int n,int a[])
	{
		//code here
		
		stack<int> s;
		for(int i = 0; i<n; i++){
		    
		    if(s.empty()){
		        s.push(a[i]);
		    }
		    
		    else if( (int)log2(s.top()) != (int)log2(a[i]) ){
		        s.push(a[i]);
		    }
		    
		    else{
		        s.pop();
		    }
		}
		
		return s.size();
	}
};
