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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete;
        for (int num : nums) {
            toDelete.insert(num);
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* ptr = dummy;

        while (ptr->next != nullptr) {
            if (toDelete.find(ptr->next->val) != toDelete.end()) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};