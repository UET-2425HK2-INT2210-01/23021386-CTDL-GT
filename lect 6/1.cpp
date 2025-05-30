#include <iostream>
using namespace std;

class BS_Tree {
private:
    struct treeNode {
        int data;
        treeNode* left;
        treeNode* right;
        
        treeNode(int value): data(value), left(nullptr), right(nullptr) {}
    };
    
        
    void TREVERSAL_INORDER (treeNode* node) { //duyệt cây theo trung thứ tự (inorder)
        
        if (node != nullptr) {
            TREVERSAL_INORDER(node->left);
            cout << node->data<< " ";
            TREVERSAL_INORDER(node->right);
        }
    }
    
    // chèn một node vào cây
    treeNode* INSERT (treeNode* node, int value) {
        /*
        nếu cây rỗng, tạo node mới làm gốc
        nếu value nhỏ hơn node hiện tại -> chèn vào bên trái
        nếu value lớn hơn node hiện tại -> chèn vào bên phải
        */
        
        // gán newNode là root nếu cây đang rỗng
        if(node == nullptr) return new treeNode(value);
        
        else if (value <= node->data) { 
            node->left = INSERT(node->left, value);
        }
        
        else if (value > node->data) {
            node->right = INSERT(node->right, value);
        }
        
        return node; // Trả về node hiện tại (sau khi chỉnh sửa)
    }
    
    // tìm node nhỏ nhất trong cây con phải (minRight)
    treeNode* findMin(treeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
    
    treeNode* DELETE (treeNode* node, int value) { // xóa node
        // điều kiện dừng
        if (node == nullptr) return node;
        
        // tìm node cần xóa nếu nó bên phải 
        if (value > node->data) node->right = DELETE(node->right, value);
        
        // tìm node cần xóa nếu nó bên trái
        else if (value < node->data) node->left = DELETE(node->left, value);
        
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr; // Trả về nullptr để gỡ bỏ node khỏi cây.
            }
            
            else if (node->left == nullptr) {
                treeNode* temp = node->right; // lưu con bên phải vào temp
                delete node; // xóa node
                return temp; // trả về temp để cha mẹ kết nối trực tiếp với temp - TK1 - bên trái
            }
            
            else if (node->right == nullptr) {
                treeNode* temp = node->left; // lưu con bên trái vào temp
                delete node; // giải phóng node (xóa node)
                return temp; // trả về temp để cha mẹ kết nối trực tiếp với temp - TK2 - bên phải
            }
            
            else {
                treeNode* minRight  = findMin(node->right); // tìm min của bên phải bằng cách chỏ sang bên trái liên tục, xem hàm findMin
                node->data          = minRight->data; // hoán đổi giá trị của node cần xóa với node minRight
                node->right         = DELETE(node->right, minRight->data); // xóa node minRight
            }
        }
        return node;
    }
    
public:
    treeNode* root; // gốc cây nhị phân tìm kiếm
    
    // conductor
    BS_Tree (): root(nullptr) {}
    
    // Hàm public để chèn giá trị vào cây
    void insert(int value) { // gọi hàm đệ quy
        root = INSERT(root, value); // Gán lại root sau khi chèn
    }

    // Hàm public để xóa node trong cây
    void del(int value) {
        root = DELETE(root, value);
    }
    
    // Hàm public để in cây theo thứ tự trung tố
    void printInOrder() {
        TREVERSAL_INORDER(root);
        cout << endl;
    }
};

int main() {
    
    BS_Tree myBST;
    // 2, 1, 10, 6, 3, 8, 7, 13, 20
    
    myBST.insert(2);
    myBST.insert(1);
    myBST.insert(10);
    myBST.insert(6);
    myBST.insert(3);
    myBST.insert(8);
    myBST.insert(7);
    myBST.insert(13);
    myBST.insert(20);
    
    myBST.printInOrder();  // Kết quả: 1 2 3 6 7 8 10 13 20
    
    myBST.del(6);
    myBST.del(13);
    myBST.del(25);
    
    myBST.printInOrder();  // Kết quả: 1 2 3 7 8 10 20
    
    return 0;
}


