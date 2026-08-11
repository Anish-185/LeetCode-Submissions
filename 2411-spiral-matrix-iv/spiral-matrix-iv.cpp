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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int top=0,bottom=m-1;
        int left=0,right=n-1;

        ListNode* curr=head;
        while(curr != nullptr && top<=bottom && left<=right){
            for(int col=left;col<=right && curr !=nullptr; col++){
                matrix[top][col]=curr->val;
                curr=curr->next;
            }

            top++;

            for(int row=top;row<=bottom && curr !=nullptr;row++){
                matrix[row][right]=curr->val;
                curr=curr->next;
            }
            right--;

            for (int col = right; col >= left && curr != nullptr; col--) {
                matrix[bottom][col] = curr->val;
                curr = curr->next;
            }
            bottom--;

            for (int row = bottom; row >= top && curr != nullptr; row--) {
                matrix[row][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        
        return matrix;

    }
};