//Name: Simrah Ahmad
//CMS-ID: 544211
//Section: BSCS 15E


#include <iostream>
using namespace std;

class ArrayStack
{
private:

    int items[5];
    int top;

public:

    // Constructor
    ArrayStack()
    {
        top = -1;
    }

    // Check if stack is empty
    bool IsEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool IsFull()
    {
        return top == 4;
    }

    // Push a value into the stack
    void Push(int value)
    {
        if (IsFull())
        {
            cout << "Stack Overflow. Cannot push "
                 << value << "." << endl;

            return;
        }

        top++;

        items[top] = value;

        cout << value << " pushed into the stack." << endl;
    }

    // Pop the top value
    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow. Stack is empty." << endl;

            return;
        }

        cout << "Removed: " << items[top] << endl;

        top--;
    }

    // Display the top value without removing it
    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow. Stack is empty." << endl;

            return;
        }

        cout << "Top element: " << items[top] << endl;
    }

    // Display from top to bottom
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty." << endl;

            return;
        }

        cout << "Stack (top to bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << items[i];

            if (i != 0)
            {
                cout << " -> ";
            }
        }

        cout << endl;
    }
};


int main()
{
    ArrayStack stack;

    // Push 10, 20, 30, 40, 50
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    cout << endl;

    // Display stack
    stack.Display();

    cout << endl;

    // Try sixth push
    stack.Push(60);

    cout << endl;

    // Pop 50
    stack.Pop();

    cout << endl;

    // Peek should show 40
    stack.Peek();

    cout << endl;

    // Display stack
    stack.Display();

    cout << endl;

    // Empty the stack
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    cout << endl;

    // Display empty stack
    stack.Display();

    cout << endl;

    // Try one more pop
    stack.Pop();

    return 0;
}