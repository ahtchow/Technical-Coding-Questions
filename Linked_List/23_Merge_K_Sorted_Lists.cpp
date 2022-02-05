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
    ListNode* mergeKListsBruteForce(vector<ListNode*>& lists) {
        
        /* Brute Force 
        
        O(Nlog(N)) - time
        O(N)- space
        
        */
        
        /* O(N) to traverse each node */
        vector<int> nums;
        for(ListNode* ll: lists){
            while(ll){
                nums.push_back(ll->val);
                ll = ll->next;
            }
        }
        /* O(NLogN) to sort */
        sort(nums.begin(), nums.end());
        
        if(nums.size() == 0) return NULL;

        /* O(N) to create new list */
        ListNode* ans = new ListNode(nums[0]);
        ListNode* head_ans = ans;
        for(int i = 1; i < nums.size(); i++){
            ListNode* nxt = new ListNode(nums[i]);
            ans->next = nxt;
            ans = ans->next;
        }
        return head_ans;
        
    }
        

    ListNode* mergeKListsComparison(vector<ListNode*>& lists) {
        
        /* Comparison
        
        O(N*K) - time
        O(N)- space
        
        */
        
        if(lists.size() == 0) return NULL;
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        int min_idx = 0;
        
        while(true){
            int min = INT_MAX;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i]){
                    if(lists[i]->val < min){
                        min_idx = i;
                        min = lists[i]->val;
                    }
                }
            }

            if(min == INT_MAX){
                break;
            }
            ListNode *nxt = new ListNode(lists[min_idx]->val);
            ans->next = nxt;
            ans = ans->next;
            lists[min_idx] = lists[min_idx]->next;

        }
        
        return head->next;        
        
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        /* Priority Queue
        O(n) - Time and space
        
        */
        
        /* Comparator Class - Compare(LL1, LL2) -> return boolean */
        struct Compare {
            bool operator() (ListNode* lhs, ListNode* rhs) {return lhs->val > rhs->val;}
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        /* O(n) Insert */
        for(ListNode* ll: lists){
            while(ll){
                pq.push(ll);
                ll = ll->next;
            }
        }
        
        ListNode* ans = new ListNode(0);
        ListNode*head = ans;
        
        while(!pq.empty()){
            ListNode* nxt = new ListNode(pq.top()->val);
            pq.pop();
            ans->next = nxt;
            ans = ans->next;
        }
        

        return head->next;

    }
};