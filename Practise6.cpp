#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

double evaluatePostfix(const string& exp)
{
    stack<double> stack;
    int count = 0;

    for (char c : exp)
    {
        if(isdigit(c))
        {
            stack.push(c - '0');
            count++;
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if(stack.size() < 2)
            {
                cout << "ERROR!!!";
                exit(1);
            }

            double operand2 = stack.top(); // Second operand
            stack.pop();
            double operand1 = stack.top(); // First operand
            stack.pop();

            double result = 0;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        cout << "Error: Division by zero" << endl;
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            // Push the result back onto the stack
            stack.push(result);
        } else {
            cout << "Error: Invalid character in expression" << endl;
            exit(1);
        }
    }
    
    if (stack.size() != 1)
    {
        cout << "Error" << endl;
        exit(1);
    }

    return stack.top();
}

int main()
{
    string exp;
    cin >> exp;
    double result = evaluatePostfix(exp);
    cout << result;
    return 0;
}