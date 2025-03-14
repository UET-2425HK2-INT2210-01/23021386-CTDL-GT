#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void search(int x) {
        Node* temp = head;
        int position = 1;
        while (temp) {
            if (temp->data == x) {
                cout << position << endl;
                return;
            }
            temp = temp->next;
            ++position;
        }
        cout << "NO" << endl;
    }
    void reverse() {
        if (!head) return; 

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        tail = head; 

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev; 
        printList(); 
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    string command;
    int x;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "append") {
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            cin >> x;
            list.search(x);
        } else if (command == "reverse") {
            list.reverse();
        }
    }

    return 0;
}

