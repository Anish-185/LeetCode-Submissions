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
    int pairSum(ListNode* head) {
        vector<int> heat;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next ){
            heat.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }

        int sum=0;
        int i=heat.size()-1;
        while(slow){
            sum=max(sum,heat[i--]+slow->val);
            slow=slow->next;
        }
        return sum;
    }
};