#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precidence(char oper)
{
    if(oper == '+' || oper == '-')
        return 1;
    if(oper == '*' || oper == '/')
        return 2;
    if(oper == '^')
        return 3;

    return 0;
}

string convertToPrefix(string infix)
{
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    int i = 0;
    string prefix = "";
    stack<char> s;

    while(infix[i] != '\0')
    {
        if(isalpha(infix[i]))
        {
            prefix = infix[i] + prefix;
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
                prefix = s.top() + prefix;
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while(!s.empty() && precidence(infix[i]) <= precidence(s.top()) && s.top() != '(')
            {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        prefix = s.top() + prefix;
        s.pop();
    }
    return prefix;
}

int main()
{
    string prefix;
    string infix;

    cin >> infix;
    prefix = convertToPrefix(infix);
    cout << prefix << endl;
}
