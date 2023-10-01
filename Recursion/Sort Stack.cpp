

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void sortStack(stack<int> &s, int x){
    
    if(s.empty() || x > s.top()){
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    sortStack(s, x);
    
    s.push(temp);
    
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(! s.empty()){
       int temp = s.top();
       s.pop();
       sort();
       sortStack(s, temp);
   }
   
}
