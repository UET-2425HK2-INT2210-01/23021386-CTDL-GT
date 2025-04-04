#include<iostream>
using namespace std;

// cấu trúc Node cho danh sách liên kết đôi
struct Node {
    int data1, data2;  
    Node* next;        
    Node* prev;        

    // Hàm khởi tạo node mới
    Node(int x, int p) {
        data1 = x;
        data2 = p;
        next = nullptr;
        prev = nullptr;
    }
};

// Định nghĩa lớp danh sách liên kết đôi (dùng để cài đặt hàng đợi ưu tiên)
class doubleLinkedList {
public:
    Node* head = nullptr; // Con trỏ trỏ đến node đầu tiên
    Node* tail = nullptr; // Con trỏ trỏ đến node cuối cùng

    // Hàm in danh sách liên kết
    void print() {
        Node* tmp = head;

        while (tmp != nullptr) {
            cout << "(" << tmp->data1 << ", " << tmp->data2 << ")"; // In giá trị và độ ưu tiên
            tmp = tmp->next;
            if (tmp != nullptr) {
                cout << "; "; 
            }
        }
        cout << endl;
    }

    // Hàm enqueue thêm phần tử vào hàng đợi ưu tiên (
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p); // Tạo node mới

        if (head == nullptr) { 
            // Nếu danh sách rỗng, đặt node mới là head và tail
            head = newNode;
            tail = newNode;
        } 
        else if (newNode->data2 > head->data2) { 
            // Nếu độ ưu tiên của node mới cao hơn head, chèn vào đầu danh sách
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        } 
        else if (newNode->data2 < tail->data2) { 
            // Nếu độ ưu tiên của node mới nhỏ hơn tail, chèn vào cuối danh sách
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } 
        else {
            // Chèn vào giữa danh sách sao cho danh sách vẫn giữ thứ tự giảm dần theo độ ưu tiên
            Node* tmp = head;
            while (!(newNode->data2 < tmp->data2 && newNode->data2 > (tmp->next)->data2)) {
                tmp = tmp->next;
            }
            tmp->next = newNode;              // Cập nhật next của tmp trỏ đến newNode
            (tmp->next)->prev = newNode;      // Cập nhật prev của node phía sau newNode
            newNode->prev = tmp;              // newNode trỏ prev về tmp
            newNode->next = tmp->next;        // newNode trỏ next đến node phía sau tmp
        }
    }

    // Hàm dequeue xóa phần tử có độ ưu tiên cao nhất 
    void dequeue() {
        if (head != nullptr) {
            Node* tmp = head; // Lưu node cần xóa
            head = head->next; // Di chuyển head đến node tiếp theo

            if (head != nullptr) {
                head->prev = nullptr; // Cập nhật prev của head mới thành nullptr
            } else {
                tail = nullptr; // Nếu danh sách trống sau khi xóa, tail cũng về nullptr
            }
            delete tmp; // Giải phóng bộ nhớ của node đã xóa
        }
    }
};

int main() {
    int n;
    cin >> n; 
    string operat;
    int x, p;
    doubleLinkedList List; // Tạo danh sách liên kết đôi

    for (int i = 0; i < n; i++) {
        cin >> operat; // Nhập lệnh (enqueue hoặc dequeue)

        if (operat == "enqueue") {
            cin >> x >> p; 
            List.enqueue(x, p); // Thêm phần tử vào danh sách theo độ ưu tiên
        } 
        else if (operat == "dequeue") {
            List.dequeue(); // Xóa phần tử có độ ưu tiên cao nhất
        } 
        else {
            cout << "invalid"; // Nếu nhập sai, in ra invalid
        }
    }

    List.print(); // In danh sách sau khi thực hiện các thao tác
    return 0;
}
