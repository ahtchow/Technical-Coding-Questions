/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/**

 Floyd Algorithm:
    Time Complexity : O(n)
    Space Complexity : O(1)

**/

class Solution {
public:
    
    ListNode *detectCycleSet(ListNode *head){
        
        if(!head || !head->next){
            return NULL;
        }
        
        unordered_set<ListNode *> set;
        set.insert(head);
        ListNode *p = head;
        
        while(p != NULL){
            
            p = p->next;
            
            if(set.find(p) != set.end()){
                return p;
            }
            
            set.insert(p);
            
        }
        
        return NULL;
        
        
    }
    
    
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next){
            return NULL;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        /* Floyds Algorithm 
        
        can't call next on NULL, so make sure fast->next is not NULL
        dont worry about slow will never reach NULL before fast
        
        */
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break;
            }
            
        }
        
        /* Where the collide will give us intuition 
        about where the cycle point is */
        
        if(slow != fast){
            return NULL;
        }
        
        /* Set slow to head and go at same speed,
           where they collide will be the cycle begins
           
           why? https://bohenan.gitbooks.io/leetcode/content/linkedlist/linked-list-cycle-ii.html
           
        */
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;        
        
        
    }
};