#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int precidence(int oper)
{
    if (oper == '+' || oper == '-')
        return 1;
    if (oper == '*' || oper == '/')
        return 2;
    if (oper == '^')
        return 3;
    
    return 0;
}

string infixToPostfix(string infix)
{
    int i = 0;
    string postfix = "";
    stack<char> s;

    while(infix[i] != '\0')
    {
        if(isalpha(infix[i]))
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        else if(infix[i] == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while(!s.empty() && precidence(infix[i]) <= precidence(s.top()) && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string postfix;
    string infix;

    cin >> infix;
    postfix = infixToPostfix(infix);
    cout << postfix << endl;
}