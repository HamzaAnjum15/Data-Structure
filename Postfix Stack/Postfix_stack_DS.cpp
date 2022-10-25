#include <iostream>
#include <stack>
using namespace std;
int Precedence(char C)
{
    if (C == '^')
    {
        return 3;
    }
    else if (C == '*' || C == '/')
    {
        return 2;
    }
    else if (C == '+' || C == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
bool Operator(char _op)
{
    if (_op == '+' || _op == '-' || _op == '/' || _op == '*' || _op == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
string InfixToPostfix(stack<char> _stack, string _infix)
{
    string PostFix;
    for (int i = 0; i < _infix.length(); i++)
    {
        if ((_infix[i] >= 'a' && _infix[i] <= 'z') || (_infix[i] >= 'A' && _infix[i] <= 'Z'))
        {
            PostFix += _infix[i];
        }
        else if (_infix[i] = '(')
        {
            _stack.push(_infix[i]);
        }
        else if (_infix[i] = ')')
        {
            while ((_stack.top() != ')') && (!_stack.empty()))
            {
                char Temp = _stack.top();
                PostFix += Temp;
                _stack.pop();
            }
        }
        else if (Operator(_infix[i]))
        {
            if (_stack.empty())
            {
                _stack.push(_infix[i]);
            }
            else
            {
                if (Precedence(_infix[i]) > Precedence(_stack.top()))
                {
                    _stack.push(_infix[i]);
                }
                else if ((Precedence(_infix[i]) == Precedence(_stack.top())) && (_infix[i] == '^'))
                {
                    _stack.push(_infix[i]);
                }
                else
                {
                    while (!_stack.empty() && Precedence(_infix[i]) <= Precedence(_stack.top()))
                    {
                        // char Temp = _stack.top();
                        PostFix += _stack.top();
                        _stack.pop();
                    }
                    _stack.push(_infix[i]);
                }
            }
        }
    }
    while (!_stack.empty())
    {
        PostFix += _stack.top();
        _stack.pop();
    }
    return PostFix;
}
int main()
{
    string InfixExp, PostFixExp;
    cout << "enter an infix expression: " << endl;
    cin >> InfixExp;
    stack<char> stack;
    cout << "Infix expression " << InfixExp << endl;
    PostFixExp = InfixToPostfix(stack, InfixExp);
    cout <<endl <<"Postfix expression " << PostFixExp << endl;

    return 0;
}