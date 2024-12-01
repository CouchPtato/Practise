#include <iostream>
#define Max_size 100

using namespace std;

class ArrayStack
{
    int arr[Max_size];
    int top;

public : 
    ArrayStack() : top(-1){} 

    bool isempty()
    {
        return top == -1;
    }

    bool isfull()
    {
        return top == Max_size - 1;
    }

    void push(int num)
    {
        if (isfull())
        {
            cout << "Already full\n";
            return;
        }
        arr[++top] = num;
    }

    void pop()
    {
        if (isempty())
        {
            cout << "ALready empty\n";
            return;
        }
        arr[top--];
    }

    void peek()
    {
        if (isempty())
        {
            cout << "\nEmpty\n";
        }
        else
        {
            cout << arr[top];
        }
    }
};

int main()
{
    ArrayStack stack;
    int num;

    cin >> num;
    stack.push(num);
    cin >> num;
    stack.push(num);
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
}