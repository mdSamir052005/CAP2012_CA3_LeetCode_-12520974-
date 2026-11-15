#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (head != nullptr) {

            if (head->next != nullptr &&
                head->val == head->next->val) {

                while (head->next != nullptr &&
                       head->val == head->next->val) {
                    head = head->next;
                }

                prev->next = head->next;
            }
            else {
                prev = prev->next;
            }

            head = head->next;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    // 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}