/*
Name: Brianna Barrentine
Compiler Used: GNU GCC Complier
Program Description: A RPN calculator that uses a stack class
*/

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

class Node
{
public:
    float operand;
    Node* below;

    Node()
    {
        operand = 0;
        below = nullptr; //create null
    }
    Node(float v, Node* b)
    {
        operand = v;
        below = b;
    }
};

class Stack
{
private:
    Node* top; //create var top
    int size;
    static const int emptyStackException;

public:
    Stack()
    {
        top = nullptr; // set top to null for now
        size = 0;
        emptyStackException;
    }
    void push(float op)
    {
        if (this->size == 0)
        {
            top = new Node(op, nullptr); //create space for new node
            size++; //increase size
        }
        else
        {
            Node* temp= new Node(op, this->top); //make var for new node space
            top = temp; // set var to top
            size++; // increase size by 1
        }
    }
    float peek()
    {
        return top->operand; // show top value
    }

    float pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            float temp_op = top->operand; //save top operand
            Node* temp_node = top; // point temp top to current top
            top = top->below; // point top to node below
            size--;
            delete temp_node; //delete node
            return temp_op; // return operand from last top
        }
    }

    void clear()
    {
        size = 0; //take all out by making size = 0
        top = nullptr; //delete top node
    }
    bool isEmpty()
    {
        return !size; //size == 0
    }
};

bool oper(const string& userInput);
void useOperator(const string& userInput, Stack& stack);

int main()
{
    cout << "RPN Calculator: Input the necessary numbers and operators, when done type 'q'"<< endl;

    Stack stack;
    string userInput;
    while(true)
    {
        cout << ">";
        cin >> userInput;
        float num;


        if(istringstream(userInput) >> num)
        {
            stack.push(num);
        }

        else if(oper(userInput))
        {
            useOperator(userInput, stack);
        }
        else if(userInput == "c")
        {
            stack.clear();
        }
        else if(userInput == "q")
        {
            return 0;
        }
        else
        {
            cout << "Invalid input, enter a number or operator" << endl;


        }
    }
}

bool oper(const string& userInput)
{
    string operators[] = {"-", "+", "*", "/"};

    for(int i = 0; i < 4; i++)
    {
        if(userInput == operators[i])
        {
            return true;
        }
    }
    return false;
}

void useOperator(const string& userInput, Stack& stack)
{
    float operand_2, operand_1, solution;

    operand_2 = stack.peek();
    stack.pop();

    operand_1 = stack.peek();
    stack.pop();

    if(userInput == "-")
    {
        solution = operand_1 - operand_2;
    }
    else if(userInput == "+")
    {
        solution = operand_1 + operand_2;
    }
    else if(userInput == "*")
    {
        solution = operand_1 * operand_2;
    }
    else if(userInput == "/")
    {
        solution = operand_1 / operand_2;
    }

    cout << solution << endl;
    stack.push(solution);
}
