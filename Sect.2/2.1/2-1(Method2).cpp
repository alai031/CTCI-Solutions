#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteDups(ListNode* n){
    ListNode* current = n;
    while (current != nullptr){
        ListNode* runner = current;
        while (runner->next != nullptr){
            if (runner->next->val == current->val){
                runner->next = runner->next->next;
            }
            else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* a = new ListNode(4);
    ListNode* b = new ListNode(6);
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(8);
    ListNode* f = new ListNode(7);
    ListNode* g = new ListNode(3);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    
    deleteDups(head);
    ListNode* curr = head;
    while (curr != nullptr){
        cout << curr->val << endl;
        curr = curr->next;
    }

    return 0;
}
