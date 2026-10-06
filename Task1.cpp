//Name: Simrah Ahmad
//CMS-ID: 544211
//Section: BSCS 15E

#include <iostream>
using namespace std;

class List
{
private:

    // Node of the doubly linked list
    struct node
    {
        int data;
        node* next;   // Points to the next node
        node* prev;   // Points to the previous node
    };

    node* head;       // Points to the first node
    node* tail;       // Points to the last node

public:

    // Constructor
    List();

    // Function declarations
    void AddNode(int value);
    void PrintForward();
    void PrintReverse();
    void ClearList();
};

// Constructor
List::List()
{
    // Initially, the list is empty
    head = NULL;
    tail = NULL;
}

// Adds a new node at the end of the list
void List::AddNode(int value)
{
    // Create a new node dynamically
    node* n = new node;

    // Store the value in the new node
    n->data = value;

    // New node is initially not connected to anything
    n->next = NULL;
    n->prev = NULL;

    // If the list is empty
    if (head == NULL)
    {
        // New node becomes both head and tail
        head = n;
        tail = n;
    }
    else
    {
        // Connect new node with the current last node
        n->prev = tail;

        // Current tail points forward to the new node
        tail->next = n;

        // Update tail to the new last node
        tail = n;
    }
}

// Prints the list from head to tail
void List::PrintForward()
{
    // Check if the list is empty
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Start traversal from the first node
    node* temp = head;

    // Continue until the end of the list
    while (temp != NULL)
    {
        // Print current node's data
        cout << temp->data << "  ";

        // Move to the next node
        temp = temp->next;
    }

    cout << endl;
}

// Prints the list from tail to head
void List::PrintReverse()
{
    // Check if the list is empty
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Start traversal from the last node
    node* temp = tail;

    // Move backwards until there are no more nodes
    while (temp != NULL)
    {
        // Print current node's data
        cout << temp->data << "  ";

        // Move to the previous node
        temp = temp->prev;
    }

    cout << endl;
}

// Deletes all nodes from the list
void List::ClearList()
{
    // Start from the first node
    node* temp = head;

    // Continue until all nodes are deleted
    while (temp != NULL)
    {
        // Move head to the next node
        head = head->next;

        // Delete the current node
        delete temp;

        // Move temp to the new head
        temp = head;
    }

    // After deleting all nodes, tail should also be NULL
    tail = NULL;
}

// Main function
int main()
{
    List l;

    // Test empty list
    l.PrintForward();

    // Add nodes to the list
    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    // Print list from beginning to end
    l.PrintForward();

    // Print list from end to beginning
    l.PrintReverse();

    // Delete all nodes
    l.ClearList();

    // Check the list after clearing
    l.PrintForward();

    return 0;
}