#include<iostream>
using namespace std;
// cấu trúc node cho stack
struct Node {
    char data;  
    Node* prev; // Con trỏ trỏ về phần tử trước trong stack

    // khởi tạo Node mới
    Node(char c) {
        data = c;
        prev = nullptr;
    }
};

// Định nghĩa lớp Stack 

class Stack {
public:
    Node* head = nullptr; // Đỉnh của stack
    int n = 0;            

    // Hàm insert đẩy một ký tự vào stack 
    void insert(char c) {
        Node* newNode = new Node(c); // Tạo node mới

        if (head == nullptr) {
            // Nếu stack đang rỗng
            head = newNode;
        } else {
            // Stack không rỗng → đưa node mới lên đầu
            newNode->prev = head; // Nối newNode về phần tử cũ
            head = newNode;       // Cập nhật đỉnh stack
        }
        n++; // Tăng số lượng phần tử
    }

    // Hàm isValid kiểm tra và xóa cặp dấu ngoặc đúng
    void isValid() {
        if (n > 1) {
            Node* tmp = head;
            // Kiểm tra nếu 2 phần tử trên cùng là một cặp đúng ((), {}, [])
            if (
                (tmp->data == ')' && tmp->prev->data == '(') ||
                (tmp->data == '}' && tmp->prev->data == '{') ||
                (tmp->data == ']' && tmp->prev->data == '[')
            ) {
                // Cặp đúng → xóa cả 2 node
                head = tmp->prev->prev; // Cập nhật đỉnh stack (lùi 2 bước)
                delete tmp->prev; // Xóa phần tử trước
                delete tmp;       // Xóa phần tử hiện tại
                n -= 2;           
            }
        }
    }
};


int main() {
    char c; 
    Stack myStack; // tạo stack mới

    // Đọc từng ký tự cho đến khi gặp dấu xuống dòng '\n'
    while ((c = getchar()) != '\n') {
        myStack.insert(c);   // Đưa ký tự vào stack
        myStack.isValid();   // Kiểm tra xem có thể xóa cặp dấu ngoặc không
    }

    // Nếu stack rỗng → tất cả các dấu ngoặc đã khớp đúng
    if (myStack.head == nullptr) {
        cout << "Valid";   
    } else {
        cout << "Invalid"; 
    }

    return 0;
}
