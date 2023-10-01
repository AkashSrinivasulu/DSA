

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1 == NULL || head2 == NULL) return -1;
    int count1 = 0, count2 = 0;
    Node *max, *min;
    
    //find len of list1, list2
    Node *cur1 = head1, *cur2 = head2;
    while(cur1 != NULL){
        cur1 = cur1->next;
        count1++;
    }
    
    while(cur2 != NULL){
        cur2 = cur2->next;
        count2++;
    }
    
    if(count1 > count2){ max = head1; min = head2;}
    else{ max = head2; min = head1;}
    
    int diff = abs(count1 - count2);
    
    //Move the bigger list till diff no of nodes
    while(diff > 0){
        max = max -> next;
        diff--;
    }
    
    //iteratge nodes parallelly
    while(max != NULL && min != NULL){
        
        if(max == min) return min->data;
        
        max = max->next;
        min = min->next;
    }
    
    return -1;
}
