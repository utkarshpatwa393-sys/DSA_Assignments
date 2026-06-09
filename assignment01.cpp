#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    // Insert at front
    void insertFront(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int x)
    {
        Node* newNode = new Node(x);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at position (0-based indexing)
    void insertPosition(int pos, int x)
    {
        if(pos == 0)
        {
            insertFront(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* temp = head;

        for(int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete front node
    void deleteFront()
    {
        if(head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete last node
    void deleteLast()
    {
        if(head == NULL)
            return;

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Delete node at position
    void deletePosition(int pos)
    {
        if(head == NULL)
            return;

        if(pos == 0)
        {
            deleteFront();
            return;
        }

        Node* temp = head;

        for(int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search key
    bool search(int key)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // Length of linked list
    int length()
    {
        int count = 0;
        Node* temp = head;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display list
    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertFront(5);

    list.display();

    cout << "Length: " << list.length() << endl;

    if(list.search(20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    list.deletePosition(2);
    list.display();

    return 0;
}
