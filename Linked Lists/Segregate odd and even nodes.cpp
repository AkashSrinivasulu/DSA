//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        Node *evens = NULL, *evene = NULL;
        Node *odds = NULL, *odde = NULL;
        Node *cur = head;
        
        while(cur != NULL){
            
            if(cur->data % 2 == 0){
                
                if(evens == NULL){
                    evens = cur;
                    evene = evens;
                }
                else{
                    evene->next = cur;
                    evene = evene->next;
                }
            }
            
            
            else{
                if(odds == NULL){
                    odds = cur;
                    odde = odds;
                }
                else{
                    odde->next = cur;
                    odde = odde->next;
                }
            }
            
            cur = cur->next;
        }
        
        if(odds == NULL || evens == NULL) return head;
        
        evene->next = odds;
        odde->next = NULL;
        return evens;
    }
};
