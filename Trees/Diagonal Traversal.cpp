
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   // your code here
   
   queue<Node*> q;
   
   q.push(root);
   
   vector<int> ans;
   
   while(!q.empty()){
       
       Node* cur = q.front();
       q.pop();
       
       while(cur){
           
           ans.push_back(cur->data);
           
           // if there is a left node, add it to the queue
           if(cur->left) q.push(cur->left);
           
           // keep on going right;
           cur = cur->right;
       }
   }
   
   return ans;
}
