#include <iostream>
using namespace std;

class Node
{
    public : 
        int data;
        Node* next;
        Node(){next = NULL;}
};

class SLL
{
    Node* head;

    public:
        SLL() {head = NULL;}

        bool isempty()
        {
            return head == NULL;
        }

        void push(int value)
        {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        void pop()
        {
            if(isempty())
            {
                cout << "stack is empty\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void display()
        {
            if(isempty())
            {
                cout << "nothing to show\n";
                return;
            }
            Node* current = head;
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main()
{
    SLL stack;
    int value;

    cin >> value;
    stack.push(value);
    cin >> value;
    stack.push(value);
    stack.display();
    stack.pop();
    stack.display();
}