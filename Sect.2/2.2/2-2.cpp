#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* nthToLast(ListNode* head, int k){
    ListNode* p1 = head;
    ListNode* p2 = head;
    for (int i = 0; i < k; ++i){
        if (p1 == nullptr)
            return nullptr;
        p1 = p1->next;
    }
    
    while (p1 != nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2;
}

int main(){
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
    
    cout << "The 3rd to last value is " << nthToLast(head, 3)->val << endl;
    ListNode* curr = head;
    while (curr != nullptr){
        cout << curr->val << endl;
        curr = curr->next;
    }

    return 0;
}
