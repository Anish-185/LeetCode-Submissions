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
    bool isPalindrome(ListNode* head) {
        if (!head){
            return false;
        }
        vector<int> heat;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            heat.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast !=nullptr){
            slow=slow->next;
        }
        int i=heat.size()-1;
        while(slow){
            if(slow->val != heat[i]){
                return false;
            }
            slow=slow->next;
            i--;
            
        }
        
        return true;
    }
};