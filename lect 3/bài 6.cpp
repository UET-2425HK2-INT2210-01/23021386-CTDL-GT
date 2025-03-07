#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) {
        data = n;
        next = NULL;
    }
};

class Stack {
public:
    Node* top;
    
    Stack() : top(NULL) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void print(Node* node) {
        if (!node) return;
        print(node->next);
        cout << node->data << " ";
    }
    
    void print() {
        print(top);
    }
};

int main() {
    int n;
    cin >> n;
    
    Stack s;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }
    
    s.print();
    
    return 0;
}



//CLASS Node:
//    DATA INTEGER data
//    POINTER Node next
//
//    FUNCTION Node(n):
//        data ? n
//        next ? NULL
//
//CLASS Stack:
//    POINTER Node top
//
//    FUNCTION Stack():
//        top ? NULL
//
//    FUNCTION push(x):
//        CREATE newNode ? NEW Node(x)
//        newNode.next ? top
//        top ? newNode
//
//    FUNCTION pop():
//        IF top = NULL THEN RETURN
//        temp ? top
//        top ? top.next
//        DELETE temp
//
//    FUNCTION print(node):
//        IF node = NULL THEN RETURN
//        CALL print(node.next)
//        PRINT node.data + " "
//
//    FUNCTION print():
//        CALL print(top)
//push(x)		O(1)	
//pop()			O(1)	
//print() 		O(n)