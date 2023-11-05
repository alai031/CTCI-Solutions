#include <iostream>

using namespace std;

struct Node{
    Node(char a) : data(a), next(nullptr){}
    char data;
    Node* next;
};

bool deleteNode(Node* n){
    if (n == nullptr || n->next == nullptr)
        return false;
    Node* next = n->next;
    n->data = next->data;
    n->next = next->next;
    return true;
}

int main()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    
    if (deleteNode(c))
        cout << "Successfully deleted the node" << endl;
    else
        cout << "Node not deleted" << endl;
    
    Node* curr = a;
    while (curr != nullptr){
        cout << curr->data << endl;
        curr = curr->next;
    }

    return 0;
}