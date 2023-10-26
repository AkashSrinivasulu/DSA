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
