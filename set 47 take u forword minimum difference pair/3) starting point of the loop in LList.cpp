// https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628
Node *firstNode(Node *head)
{
	//    Write your code here.
   if(head == NULL||head->next == NULL) return NULL;
        
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;
        
    while(fast->next != NULL&&fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}