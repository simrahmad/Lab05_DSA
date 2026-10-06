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

    node* head;
    node* tail;
    node* temp;

    SinglyCircularList();

    void AddNode(int value);
    void PrintList();
    void CountNodes();
    void ClearList();
    void DeleteNode(int value);
};

// Constructor
SinglyCircularList::SinglyCircularList()
{
    // Initially, the list is empty
    head = NULL;
    tail = NULL;
    temp = NULL;
}

// Add a node at the end
void SinglyCircularList::AddNode(int value)
{
    node* n = new node;

    n->data = value;
    n->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = n;
        tail = n;

        // Last node points back to head
        n->next = head;

        return;
    }
    else
    {
        // Connect new node after tail
        tail->next = n;

        // Update tail
        tail = n;

        // Keep the list circular
        n->next = head;

        return;
    }
}

// Print all nodes exactly once
void SinglyCircularList::PrintList()
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

        do
        {
            cout << temp->data << "  ";

            // Move to next node
            temp = temp->next;

        } while (temp != head);  // Stop after one complete cycle

        cout << endl;
        return;
    }
}

// Count the number of nodes
void SinglyCircularList::CountNodes()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        int count = 0;

        temp = head;

        // Traverse one complete cycle
        do
        {
            count++;
            temp = temp->next;

        } while (temp != head);

        cout << "Number of nodes in the list: " << count << endl;

        return;
    }
}

// Delete all nodes
void SinglyCircularList::ClearList()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Start from the node after head
    temp = head->next;

    while (temp != head)
    {
        // Save next node before deleting
        node* nextNode = temp->next;

        delete temp;

        temp = nextNode;
    }

    // Delete the head node
    delete head;

    // Reset list
    head = NULL;
    tail = NULL;
}

// Delete the first node containing the given value
void SinglyCircularList::DeleteNode(int value)
{
    // Check if list is empty
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Start searching from head
    temp = head;

    // Search through one complete cycle
    do
    {
        if (temp->data == value)
            break;

        temp = temp->next;

    } while (temp != head);

    // Value was not found
    if (temp->data != value)
    {
        cout << "Value not found" << endl;
        return;
    }

    // Case 1: Only one node
    if (head == tail)
    {
        delete head;

        head = NULL;
        tail = NULL;

        return;
    }

    // Case 2: Delete head
    if (temp == head)
    {
        // Move head to the next node
        head = head->next;

        // Tail must point to the new head
        tail->next = head;

        delete temp;

        return;
    }

    // Find the node before temp
    node* prevNode = head;

    while (prevNode->next != temp)
    {
        prevNode = prevNode->next;
    }

    // Case 3: Delete tail
    if (temp == tail)
    {
        // Move tail to the previous node
        tail = prevNode;

        // New tail points to head
        tail->next = head;

        delete temp;

        return;
    }

    // Case 4: Delete middle node
    prevNode->next = temp->next;

    delete temp;
}

int main()
{
    SinglyCircularList list;

    // Test empty list
    cout << "Empty List:" << endl;
    list.PrintList();
    list.CountNodes();

    // Add nodes: 10, 20, 30
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    cout << endl << "Original List:" << endl;
    list.PrintList();
    list.CountNodes();

    // Delete head: 10
    cout << endl << "Delete Head (10):" << endl;
    list.DeleteNode(10);
    list.PrintList();
    list.CountNodes();

    // Delete tail: 30
    cout << endl << "Delete Tail (30):" << endl;
    list.DeleteNode(30);
    list.PrintList();
    list.CountNodes();

    // Delete the only remaining node: 20
    cout << endl << "Delete Only Node (20):" << endl;
    list.DeleteNode(20);
    list.PrintList();
    list.CountNodes();

    // Try deleting from an empty list
    cout << endl << "Delete from Empty List:" << endl;
    list.DeleteNode(50);

    // Create another list for middle-node test
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    cout << endl << "New List:" << endl;
    list.PrintList();

    // Delete middle node
    cout << endl << "Delete Middle Node (20):" << endl;
    list.DeleteNode(20);
    list.PrintList();
    list.CountNodes();

    // Try deleting a value that doesn't exist
    cout << endl << "Delete Missing Value (100):" << endl;
    list.DeleteNode(100);

    // Clear list
    cout << endl << "Clear List:" << endl;
    list.ClearList();
    list.PrintList();

    return 0;
}