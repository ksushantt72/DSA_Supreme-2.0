#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLL(Node*&head,Node *&prev, Node *&curr)
{
    // Base case
    if (curr == NULL)
    {
        
        //curr agar NULL hai to previous wala hmara new head hoga
        head=prev;
        return;
    }
    //ek Case khul solve krna hai
    // after changing pointer, we will lose track so initially create nextnode ptr
    Node *nextNode = curr->next;
    //curr-Next ko prev se point krwana hai 
    curr->next=prev;
    prev=curr;
    curr=nextNode;
    reverseLL(head,prev,curr);
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;

    printLL(head);

    Node *prev = NULL;
    Node *curr = head;
    reverseLL(head,prev, curr);
    printLL(head);
}
