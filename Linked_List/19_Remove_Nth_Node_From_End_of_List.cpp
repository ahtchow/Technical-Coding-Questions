/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    
    
    /* 
    
    n = 9
       1->2->3->4->5->6->7->8->9 
       P1
                               P2
    
    */
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /* Edge Case */
        if(!head) return head;
        
        ListNode * p1 = head;
        ListNode * p2 = head;
        int count = 0;
        while(count < n){
            p2 = p2->next;
            count++;
        }
        
        /* Case where p2 is null - removing the first node */
        if(!p2){
            head = p1->next;
            p1 = NULL;
            return head;
        } 
            
        
        
        /* Move to desired location */
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        /* Case: Node to Remove is first Node */
        
        
        
        /* General Case */
        ListNode * temp = p1->next->next;
        p1->next = temp;
        return head;
             
        
        
    }
};