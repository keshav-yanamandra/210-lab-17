// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 17


#include <iostream>
using namespace std;

const int SIZE = 7;  

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
    //int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    // for (int i = 0; i < SIZE; i++) {
    //     int tmp_val = rand() % 100;
    //     Node *newVal = new Node;
        
    //     // adds node at head
    //     if (!head) {
    //         head = newVal;
    //         newVal->next = nullptr;
    //         newVal->value = tmp_val;
    //     }
    //     else {
    //         newVal->next = head;
    //         newVal->value = tmp_val;
    //         head = newVal;
    //     }
    // }

    //call the new add node to front function
    for (int i = 0; i < SIZE; i++) {
        addNodeFront(head, rand() % 100);
    }
    output(head);

    //testing add node to tail
    addNodeTail(head, 5);
    output(head);

    // // deleting a node
    // cout << "Which node to delete? " << endl;
    // output(head);
    // int entry;
    // cout << "Choice --> ";
    // cin >> entry;

    // // traverse that many times and delete that node
    // Node *current = head;
    // Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    // for (int i = 0; i < (entry - 1); i++) {
    //     prev = current;
    //     current = current->next;
    // }

    // // at this point, delete current and reroute pointers
    // if (current) {
    //     if (prev == nullptr) {
    //         // deleting the head node
    //         head = current->next;
    //     } else {
    //         prev->next = current->next;
    //     }
    //     delete current;
    //     current = nullptr;
    // }

    //testing delete node
    deleteNode(head);
    output(head);

    // // insert a node
    // Node *current = head;
    // Node *prev = nullptr;
    // int entry;

    // cout << "After which node to insert 10000? " << endl;
    // count = 1;
    // current = head;
    // while (current) {
    //     cout << "[" << count++ << "] " << current->value << endl;
    //     current = current->next;
    // }
    // cout << "Choice --> ";
    // cin >> entry;

    // current = head;
    // prev = nullptr;  // reset prev to nullptr for same reason

    // for (int i = 0; i < entry; i++) {
    //     prev = current;
    //     current = current->next;
    // }

    // // at this point, insert a node between prev and current
    // Node *newnode = new Node;
    // newnode->value = 10000;
    // newnode->next = current;

    // if (prev == nullptr) {
    //     // inserting before the head
    //     head = newnode;
    // } else {
    //     prev->next = newnode;
    // }
    // output(head);

    //testing insert node
    insertNode(head);
    output(head);


    // deleting the linked list
    // Node *current = head;
    // while (current) {
    //     head = current->next;
    //     delete current;
    //     current = head;
    // }
    // head = nullptr;
    
    output(head);
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
