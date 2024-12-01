#include <iostream>
using namespace std;

#define MAX_SIZE 20

class CircularQueue
{
    int arr[MAX_SIZE];
    int front, rear;
    int size;

    public :
        CircularQueue() : front(-1), rear(-1), size(0) {}

        bool isempty()
        {
            return size == 0;
        }

        bool isfull()
        {
            return  size == MAX_SIZE;
        }

        void enqueue(int num)
        {
            if(isfull())
            {
                cout << "already full\n";
                return;
            }

            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = num;
            size++; 
        }

        void dequeue()
        {
            if (isempty())
            {
                cout << "already empty\n";
            }

            front = (front+1) % MAX_SIZE;
            size--;
        }

        void display()
        {
            if(isempty())
            {
                cout << "nothing to show\n";
                return;
            }
            
            int i = front;
            int count = size;
            while(count--)
            {
                cout << arr[i] << " ";
                i = (i+1) % MAX_SIZE;
            }
        }
};

int main()
{
    CircularQueue queue;
    int value;

    cin >> value;
    queue.enqueue(value);
    cin >> value;
    queue.enqueue(value);
    queue.display();
    queue.dequeue();
    queue.display();
}