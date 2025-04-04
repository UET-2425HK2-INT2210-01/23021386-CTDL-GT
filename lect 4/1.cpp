#include<iostream>
using namespace std;

// Cấu trúc 1 Node trong danh sách liên kết đơn
struct Node{
    int data;       
    Node* next;     // Con trỏ trỏ đến node kế tiếp

    
    Node(int x){ // Khởi tạo node
        data = x;
        next = nullptr;
    }
};

// Lớp danh sách liên kết đơn
class singleLinkedList{
public:
    Node* head = nullptr; // Node đầu danh sách
    Node* tail = nullptr; // Node cuối danh sách

    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " "; 
            tmp = tmp->next;          // Di chuyển đến node kế tiếp
        }
        cout << endl;
    }

    // Hàm thêm phần tử vào cuối danh sách
    void append(int x){
        Node* newNode = new Node(x); // Tạo node mới
        if(head == nullptr){         // Nếu danh sách rỗng
            head = newNode;
            tail = newNode;
        }else{                       // Nếu đã có phần tử
            tail->next = newNode;    // Gắn node mới vào sau tail
            tail = newNode;          // Cập nhật tail
        }
    }

    // Hàm tìm kiếm giá trị x trong danh sách
    void search(int x){
        Node* tmp = head;
        int n = 0; // Vị trí (index) bắt đầu từ 0
        while(tmp != nullptr){
            if(tmp->data == x){      // Nếu tìm thấy
                cout << n << endl;   
                return;              
            }
            tmp = tmp->next;
            n++;
        }
        cout << "No" << endl;        // Không tìm thấy
    }

    // Hàm đảo ngược danh sách
    void reverse(){
        Node* prev = nullptr;        // Node phía trước
        Node* curr = head;           // Node hiện tại
        Node* next = nullptr;        // Node tiếp theo

        while(curr != nullptr){
            next = curr->next;       // Lưu lại node tiếp theo
            curr->next = prev;       // Đảo chiều liên kết
            prev = curr;             
            curr = next;             
        }
        head = prev;                 // Cập nhật head về node mới đầu 
    }
};

// Hàm chính
int main(){
    int n;               
    cin >> n;
    string operat;       
    int x;               
    singleLinkedList List; // Tạo danh sách liên kết

    for(int i = 0; i < n; i++){
        cin >> operat;   

        if(operat == "append"){
            cin >> x;
            List.append(x); 
        }
        if(operat == "search"){
            cin >> x;
            List.search(x); 
        }
        if(operat == "reverse"){
            List.reverse(); 
            List.print();   
        }
    }

    return 0;
}
