#include <iostream>
using namespace std;

class Node
{
    public : 
        Node* next;
        int data;
        Node(){next = NULL;}
};

class SLL
{
    Node* front;
    Node* rear;

    public:
        SLL() {front = NULL; rear = NULL;}

        bool isEmpty()
        {
            return front == NULL;
        }

        void enqueue(int value)
        {
            Node* newNode = new Node();
            newNode->data = value;

            if(isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue()
        {
            if(isEmpty())
            {
                cout << "already empty\n";
                return;
            }

            Node* temp = front;
            front = front->next;
            delete temp;
        }

        void display()
        {
            if(isEmpty())
            {
                cout << "nothing to show\n";
                return;
            }
            Node* current = front;
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main()
{
    SLL queue;
    int value;

    if(queue.isEmpty())
    {
        cout << "lol\n";
    }
    queue.display();
    cin >> value;
    queue.enqueue(value);
    queue.dequeue();
    queue.display();
}