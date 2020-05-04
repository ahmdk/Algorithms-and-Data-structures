#include <iostream>

struct Node
{
    int key;
    Node *next;
    Node(int _key) : key(_key), next(nullptr){}
    Node(int _key, Node * _next) : key(_key), next(_next){}
};

void insert(Node *& head, int key)
{
    Node * node = new Node{key, head};
    head = node;    
}

void reverse(Node *& head)
{
    Node * prev = nullptr;
    Node * cur = head;
    Node * next;    
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;   
    } 
    head = prev;
}

Node * mergeLists(Node *& l1, Node *& l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    Node * result = nullptr;
    if(l1->key < l2->key)
    {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else
    {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    return result;
}

void printList(Node *head)
{
    while(head)
    {
        std::cout << head->key << " ";
        head = head->next;
    }
    std::cout << '\n';
}

int main()
{
    Node *l1 = new Node{1};
    Node *l2 = new Node{2};
    
    insert(l1, 3);
    insert(l1, 5);
    insert(l1, 7);
    insert(l1, 9);
    
    insert(l2, 4);
    insert(l2, 6);
    insert(l2, 8);
    insert(l2, 10);
    
    reverse(l1);
    reverse(l2);
    
    printList(l1);
    printList(l2);
    Node * l3 = mergeLists(l1,l2);
    printList(l3);
}


