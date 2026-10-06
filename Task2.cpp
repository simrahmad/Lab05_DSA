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
        node* next;
        node* prev;
    };

public:

    List();

    node* head;
    node* tail;
    node* temp;

    void AddNode(int value);
    void PrintForward();
    void PrintReverse();
    void ClearList();
    void InsertBefore(int position, int value);
    void DeleteNode(int value);
};

// Constructor
List::List()
{
    // Initially, the list is empty
    head = NULL;
    tail = NULL;
    temp = NULL;
}

// Add a new node at the end of the list
void List::AddNode(int value)
{
    node* n = new node;

    n->data = value;
    n->next = NULL;
    n->prev = NULL;

    // If list is empty, new node becomes head and tail
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    else
    {
        // Connect new node with the current tail
        n->prev = tail;
        tail->next = n;

        // Update tail
        tail = n;
        return;
    }
}

// Print list from head to tail
void List::PrintForward()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // Start from head
        temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "  ";

            // Move to next node
            temp = temp->next;
        }

        cout << endl;
        return;
    }
}

// Print list from tail to head
void List::PrintReverse()
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // Start from tail
        temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << "  ";

            // Move to previous node
            temp = temp->prev;
        }

        cout << endl;
        return;
    }
}

// Delete all nodes from the list
void List::ClearList()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        temp = head;

        while (temp != NULL)
        {
            // Move head to the next node
            head = head->next;

            // Delete current node
            delete temp;

            // Move temp to the new head
            temp = head;
        }

        // List is now empty
        tail = NULL;
        return;
    }
}

// Insert a new node before a given position
void List::InsertBefore(int position, int value)
{
    // According to the requirement, insertion is only
    // possible before an existing node
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node* n = new node;

    n->data = value;
    n->next = NULL;
    n->prev = NULL;

    int count = 1;

    // Start searching from the first node
    temp = head;

    // Find the node at the required position
    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    // Position does not exist
    if (temp == NULL)
    {
        cout << "Position is out of range" << endl;

        // Delete the unused node
        delete n;
        return;
    }
    else
    {
        // New node comes before temp
        n->next = temp;
        n->prev = temp->prev;

        // If temp is not the first node
        if (temp->prev != NULL)
        {
            temp->prev->next = n;
        }
        else
        {
            // If inserting before head, update head
            head = n;
        }

        // Connect temp back to the new node
        temp->prev = n;

        return;
    }
}

// Delete the first node containing the given value
void List::DeleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // Start searching from head
        temp = head;

        // Find the first matching value
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }

        // Value was not found
        if (temp == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }
        else
        {
            // If node has a previous node
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                // Deleting the head
                head = temp->next;
            }

            // If node has a next node
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                // Deleting the tail
                tail = temp->prev;
            }

            // Delete the node
            delete temp;

            return;
        }
    }
}

int main()
{
    List l;

    // Create list
    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    cout << "Original List:" << endl;
    l.PrintForward();
    l.PrintReverse();

    // Insert 15 before position 2
    cout << endl << "Insert 15 before position 2:" << endl;
    l.InsertBefore(2, 15);
    l.PrintForward();
    l.PrintReverse();

    // Delete 20
    cout << endl << "Delete 20:" << endl;
    l.DeleteNode(20);
    l.PrintForward();
    l.PrintReverse();

    // Insert before head
    cout << endl << "Insert 5 before head:" << endl;
    l.InsertBefore(1, 5);
    l.PrintForward();
    l.PrintReverse();

    // Delete head
    cout << endl << "Delete head (5):" << endl;
    l.DeleteNode(5);
    l.PrintForward();
    l.PrintReverse();

    // Delete tail
    cout << endl << "Delete tail (30):" << endl;
    l.DeleteNode(30);
    l.PrintForward();
    l.PrintReverse();

    // Try to delete a value that does not exist
    cout << endl << "Delete missing value (100):" << endl;
    l.DeleteNode(100);

    // Clear the entire list
    l.ClearList();

    // Test empty list
    cout << endl << "Empty List:" << endl;
    l.PrintForward();
    l.PrintReverse();

    return 0;
}