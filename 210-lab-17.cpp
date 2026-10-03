// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 17


#include <iostream>
using namespace std;

const int SIZE = 7;  
const int MIN = 1;
const int MAX = 7;
const int EXIT = 7;

struct Node {
    float value;
    Node *next;
};

void addNodeFront(Node *&, float);
void addNodeTail(Node *&, float);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);

void output(Node *);

int main() {
    Node *head = nullptr;
    int choice = 0;

    for (int i = 0; i < SIZE; i++) {
        addNodeFront(head, rand() % 100);
    }
    output(head);

    while (choice != EXIT) {
        cout << endl;
        cout << "1. Add a node to the front" << endl;
        cout << "2. Add a node to the end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Insert a node" << endl;
        cout << "5. Delete the list" << endl;
        cout << "6. Print the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice --> ";
        cin >> choice;

        while (choice < MIN || choice > MAX) {
            cout << "Invalid choice. Enter 1-7: ";
            cin >> choice;
        }

        if (choice == 1) {
            addNodeFront(head, rand() % 100);
            output(head);
        }
        else if (choice == 2) {
            addNodeTail(head, rand() % 100);
            output(head);

        }
        else if (choice == 3) {
            deleteNode(head);
            output(head);
        }
        else if (choice == 4) {
            insertNode(head);
            output(head);
        }
        else if (choice == 5) {
            deleteList(head);
            output(head);
        }
        else if (choice == 6) {
            output(head);
        }    
    }

    deleteList(head);
    return 0;
}



void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

//function for adding a node to the front. 
// I am using pass by reference (*&) because the function has to change head pointer. 
// passing by value did not compile and even if we make it work it will be only inside the function
void addNodeFront(Node *&head, float tmp_val) {
    Node *newVal = new Node;

    if (!head) {
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else {
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
}

void addNodeTail(Node *&head, float tmp_val) {
    Node *newVal = new Node;
    newVal->value = tmp_val;
    newVal->next = nullptr;

    if (!head) {
        head = newVal;
    }
    else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newVal;
    }
}

//copying delete node into a function
void deleteNode(Node *&head) {

    if (!head) {
        cout << "Empty list." << endl;
        return;
    }

    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

void insertNode(Node *&head) {
    if (!head) {
        cout << "Empty list." << endl;
        return;
    }
    cout << "After which node to insert 10000? " << endl;

    int count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }

    int entry;
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = nullptr;

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        head = newnode;
    } else {
        prev->next = newnode;
    }
}

//delete list function
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
