#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
};


class Stack
{
    private:
        Node *top;
        int size=0;
    public:
        Stack()
    {
            top=NULL;
    }
    void Push(char x);
    char  Pop();
    char StackTop();
    bool isEmpty();
};

void Stack ::Push(char x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        size++;
        t->data=x;
        t->next=top;
        top=t;
    }
}

char Stack :: Pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return x;
    }
    else
    {
        size--;
        Node *p=top;
        top=top->next;
        x=p->data;
        free(p);
        return x;
    }
}

char Stack :: StackTop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"The stack is empty "<<endl;
    }
    else
    {
        x=top->data;
    }
    return x;
}

bool Stack :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

class Evaluation
{
private:
    Stack stk;
public:
    int Evaluate(char *str);
    bool isDigit(char x);
    int ChartoDigit(char x);
    char DigittoChar(int x);
};

int Evaluation:: Evaluate(char *str)
{
    int n1;
    int n2;
    int size=0;
    int result=0;
    while(str[size]!='\0')
    {
        size++;
    }
    for(int i=0;i<size;i++)
    {
        if(isDigit(str[i]))
        {
            stk.Push(str[i]);
        }
        else
        {
            n1=ChartoDigit(stk.Pop());
            n2=ChartoDigit(stk.Pop());
            switch(str[i])
            {
                case '+' :
                    result=n2+n1;
                    break;
                case '-':
                    result=n2-n1;
                    break;
                case '*':
                    result=n2*n1;
                    break;
                case '/':
                    result=n2/n1;
                    break;
            }
            stk.Push(DigittoChar(result));
        }
    }
    return ChartoDigit(stk.Pop());
}

bool Evaluation:: isDigit(char x)
{
    if((((int)x)>=48)&&(((int)x)<=57))
        return true;
    return false;
}

int Evaluation :: ChartoDigit(char x)
{
    return ((int)x)-48;
}

char Evaluation::DigittoChar(int x)
{
    return (char)(x+48);
}

int main()
{
    cout<<"Enter the postfix expression to be Evaluated : "<<endl;
    char str[50];
    cin>>str;
    Evaluation eval;
    int result=eval.Evaluate(str);
    cout<<"The result of the evaluation of the given postfix expression is : "<<result<<endl;
    return 0;
}

