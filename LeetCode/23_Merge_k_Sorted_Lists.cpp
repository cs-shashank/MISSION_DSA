#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct iot {
        bool operator()(ListNode* a, ListNode* b) {
            return (a->val > b->val);  // Min-Heap, returns true if b is greater than a
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, iot> mh;
        
        // Push all the heads of the lists into the priority queue
        for (ListNode* i : lists) {
            if (i) {
                mh.push(i);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Merge the lists
        while (!mh.empty()) {
            ListNode* mheap = mh.top();
            mh.pop();
            temp->next = mheap;
            temp = temp->next;

            if (mheap->next) {
                mh.push(mheap->next);
            }
        }

        return dummy->next;
    }
};

// Function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Enter number of linked lists: ";
    cin >> k;
    vector<ListNode*> lists;

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter number of elements in list " << i + 1 << ": ";
        cin >> n;

        vector<int> values(n);
        cout << "Enter elements of list " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> values[j];
        }

        lists.push_back(createList(values));  // Create list and add to the lists vector
    }

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}