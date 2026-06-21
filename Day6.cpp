#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// 1. Search an element
bool search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

// 2. Count nodes
int countNodes(Node* head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// 3. Count occurrences of a value
int countOccurrences(Node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count++;

        head = head->next;
    }

    return count;
}

// 4. Insert at position (1-based indexing)
void insertAtPosition(Node*& head, int pos, int val) {
    Node* newNode = new Node(val);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Delete at position
void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL)
        return;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;

    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL)
        return;

    Node* del = curr->next;
    curr->next = del->next;
    delete del;
}

// 6. Delete last node
void deleteLast(Node*& head) {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}



// 9. Print alternate nodes
void printAlternate(Node* head) {
    int index = 1;

    while (head != NULL) {
        if (index % 2 == 1)
            cout << head->data << " ";

        head = head->next;
        index++;
    }
    cout << endl;
}

// 10. Nth node from beginning
int nthFromBeginning(Node* head, int n) {
    int count = 1;

    while (head != NULL) {
        if (count == n)
            return head->data;

        count++;
        head = head->next;
    }

    return -1;
}

// Display linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 20);
    insertAtEnd(head, 50);

    cout << "Linked List: ";
    display(head);

    cout << "Search 30: "
         << (search(head, 30) ? "Found" : "Not Found") << endl;

    cout << "Total Nodes: "
         << countNodes(head) << endl;

    cout << "Occurrences of 20: "
         << countOccurrences(head, 20) << endl;

    insertAtPosition(head, 3, 25);
    cout << "After Insert at Position 3: ";
    display(head);

    deleteAtPosition(head, 4);
    cout << "After Delete at Position 4: ";
    display(head);

    deleteLast(head);
    cout << "After Delete Last Node: ";
    display(head);

    cout << "Maximum Element: "
         << findMax(head) << endl;

    cout << "Minimum Element: "
         << findMin(head) << endl;

    cout << "Alternate Nodes: ";
    printAlternate(head);

    cout << "3rd Node from Beginning: "
         << nthFromBeginning(head, 3) << endl;

    cout << "2nd Node from End: "
         << nthFromEnd(head, 2) << endl;

    return 0;
}
