#include <iostream>

struct Node
{
    int key;
    Node *next;
    Node() : key(0), next(nullptr){}
    Node(int _key) : key(_key), next(nullptr){}
    Node(int _key, Node * _next) : key(_key), next(_next){}
};

void insert(Node *& head, int key)
{
    Node * node = new Node{key, head};
    head = node;    
}

Node * remove(Node *& head, int key)
{
    if(!head) return head;
    if(head->key == key)
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    head->next = remove(head->next, key);
    return head;
}

Node * find(Node *head, int key)
{
    while(head && head->key != key)
    {
        head = head->next;
    }
    return head;   
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
    remove(l3, 8);
    printList(l3);
    Node *result = find(l3, 200);
    if(result)
    {
        std::cout << result->key << std::endl;
    } else{
        std::cout << "key was not found" << std::endl;
    }
}
