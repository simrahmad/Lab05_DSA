//Name: Simrah Ahmad
//CMS-ID: 544211
//Section: BSCS 15E


#include<iostream>
using namespace std;

class SinglyCircularList
{
private:

    // Node of the circular linked list
    struct node
    {
        int data;
        node* next;
    };

public:

    node* head;     // Points to the first node
    node* tail;     // Points to the last node
    node* temp;     // Temporary pointer for traversal

    SinglyCircularList();

    void AddNode(int value);
    void PrintList();
    void CountNodes();
    void ClearList();
};

// Constructor
SinglyCircularList::SinglyCircularList()
{
    // Initially, the list is empty
    head = NULL;
    tail = NULL;
    temp = NULL;
}

// Add a node at the end of the circular list
void SinglyCircularList::AddNode(int value)
{
    // Create a new node
    node* n = new node;

    n->data = value;
    n->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        // New node becomes both head and tail
        head = n;
        tail = n;

        // Point back to head to make the list circular
        n->next = head;

        return;
    }
    else
    {
        // Connect current tail to the new node
        tail->next = n;

        // Update tail
        tail = n;

        // Last node always points back to head
        n->next = head;

        return;
    }
}

// Print all nodes exactly once
void SinglyCircularList::PrintList()
{
    // Check if list is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // Start traversal from head
        temp = head;

        // do-while is used because the list has no NULL at the end
        do
        {
            cout << temp->data << "  ";

            // Move to the next node
            temp = temp->next;

        } while (temp != head); // Stop after coming back to head

        cout << endl;
        return;
    }
}

// Count the number of nodes
void SinglyCircularList::CountNodes()
{
    // Check if list is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        int count = 0;

        // Start from head
        temp = head;

        // Traverse one complete cycle
        do
        {
            count++;

            // Move to next node
            temp = temp->next;

        } while (temp != head);

        cout << "Number of nodes in the list: " << count << endl;

        return;
    }
}

// Delete all nodes from the circular list
void SinglyCircularList::ClearList()
{
    // Check if list is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Start from the node after head
    temp = head->next;

    // Delete nodes until we reach head again
    while (temp != head)
    {
        // Save the next node before deleting current node
        node* nextNode = temp->next;

        delete temp;

        // Move to the next node
        temp = nextNode;
    }

    // Finally delete the head node
    delete head;

    // Reset the list
    head = NULL;
    tail = NULL;
}

int main()
{
    SinglyCircularList list;

    // Test empty list
    list.PrintList();
    list.CountNodes();

    // Add one node
    list.AddNode(10);
    list.PrintList();
    list.CountNodes();

    // Add more nodes: 10, 20, 30
    list.AddNode(20);
    list.AddNode(30);

    list.PrintList();
    list.CountNodes();

    // Clear the complete list
    list.ClearList();

    // Test empty list again
    list.PrintList();
    list.CountNodes();

    return 0;
}

//  A circular linked list has no NULL at the end because the last node points back to the head.
//  Therefore, a while(temp != NULL) traversal never terminates and keeps visiting the nodes repeatedly.
//   We instead stop when temp becomes equal to head again.