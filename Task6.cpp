//Name: Simrah Ahmad
//CMS-ID: 544211
//Section: BSCS 15E

#include <iostream>
using namespace std;

class LinkedStack
{
private:

    struct Node
    {
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* top;

public:

    // Constructor
    LinkedStack()
    {
        top = nullptr;
    }

    // Check if stack is empty
    bool IsEmpty()
    {
        return top == nullptr;
    }

    // Push a value onto the stack
    void Push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

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

        Node* temp = top;

        cout << "Removed: " << top->data << endl;

        top = top->next;

        delete temp;
    }

    // View the top value
    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow. Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    // Display stack from top to bottom
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;

        cout << "Stack (top to bottom): ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << endl;
    }

    // Delete all remaining nodes
    void ClearStack()
    {
        while (top != nullptr)
        {
            Node* temp = top;

            top = top->next;

            delete temp;
        }
    }

    // Destructor
    ~LinkedStack()
    {
        ClearStack();
    }
};


int main()
{
    LinkedStack stack;

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << "========== STACK MENU ==========" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                stack.Push(value);

                break;


            case 2:

                stack.Pop();

                break;


            case 3:

                stack.Peek();

                break;


            case 4:

                stack.Display();

                break;


            case 5:

                cout << "Exiting program..." << endl;

                break;


            default:

                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);


    // Release any remaining nodes
    stack.ClearStack();

    return 0;
}