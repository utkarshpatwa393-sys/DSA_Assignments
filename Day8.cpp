// 1. Implement Doubly Linked List Class

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
}; 



// 2.Insert Front

void insertFront(int x) {
    Node* temp = new Node(x);

    if(head == NULL) {
        head = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}



// 3.Insert End

void insertEnd(int x) {
    Node* temp = new Node(x);

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;

    while(curr->next)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
}



// 4.Delete Node

void deleteNode(int key) {
    Node* curr = head;

    while(curr && curr->data != key)
        curr = curr->next;

    if(curr == NULL)
        return;

    if(curr == head)
        head = head->next;

    if(curr->prev)
        curr->prev->next = curr->next;

    if(curr->next)
        curr->next->prev = curr->prev;

    delete curr;
}



// 5.Reverse Doubly Linked List


void reverse() {
    Node* curr = head;
    Node* temp = NULL;

    while(curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if(temp)
        head = temp->prev;
}



// 6.Traverse Circular Linked List


Node* temp = head;

do {
    cout << temp->data << " ";
    temp = temp->next;
}
while(temp != head);



// 7. LeetCode 707 – Design Linked List

class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
    };

    Node* head;

    MyLinkedList() {
        head = new Node(0); // dummy node
    }

    int get(int index) {
        Node* cur = head->next;
        while (cur && index--) cur = cur->next;
        return cur ? cur->val : -1;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(val);
    }

    void addAtIndex(int index, int val) {
        Node* cur = head;
        while (cur && index--) cur = cur->next;

        if (!cur) return;

        Node* temp = new Node(val);
        temp->next = cur->next;
        cur->next = temp;
    }

    void deleteAtIndex(int index) {
        Node* cur = head;
        while (cur->next && index--) cur = cur->next;

        if (!cur->next) return;

        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
};



// 8. LeetCode 430 – Flatten a Multilevel Doubly Linked List


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;

                Node* childHead = flatten(curr->child);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                Node* tail = childHead;
                while (tail->next)
                    tail = tail->next;

                tail->next = nextNode;

                if (nextNode)
                    nextNode->prev = tail;
            }

            curr = curr->next;
        }

        return head;
    }
};


// 9. LeetCode 146 – LRU Cache (Theory Only)


// LRU = Least Recently Used
// It is a cache that stores a limited number of items. When the cache becomes full and a
// new item needs to be inserted, the item that was used least recently is removed.

// #Operations
// 1.get(key)
// ->If key exists → return value.
// ->Move that key to the most recently used position.
// 2.put(key, value)
// ->If key already exists → update value and move it to the front.
// ->If key doesn't exist:
// ->If cache has space → insert it.
// ->If cache is full → remove least recently used item and insert new one.
