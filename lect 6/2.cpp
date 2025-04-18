#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;       // Mảng lưu trữ các phần tử của heap
    int maxSize;     // Kích thước tối đa của heap
    int size;        // Số lượng phần tử hiện tại trong heap

    // Hàm lấy chỉ số của nút cha
    int getParentID(int i) {
        return (i - 1) / 2;
    }

    // Hàm lấy chỉ số của con trái
    int getLeftChildID(int i) {
        return 2 * i + 1;
    }

    // Hàm lấy chỉ số của con phải
    int getRightChildID(int i) {
        return 2 * i + 2;
    }

    // Hoán đổi giá trị hai biến
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Đưa phần tử tại vị trí i đi lên để duy trì tính chất heap
    void heapifyUp(int i) {
        while (i > 0 && heap[getParentID(i)] > heap[i]) {
            swap(heap[i], heap[getParentID(i)]);
            i = getParentID(i);
        }
    }

    // Đưa phần tử tại vị trí i đi xuống để duy trì tính chất heap
    void heapifyDown(int i) {
        int smallestID = i;
        int leftID = getLeftChildID(i);
        int rightID = getRightChildID(i);

        if (leftID < size && heap[leftID] < heap[smallestID]) smallestID = leftID;
        if (rightID < size && heap[rightID] < heap[smallestID]) smallestID = rightID;

        if (smallestID != i) {
            swap(heap[i], heap[smallestID]);
            heapifyDown(smallestID);
        }
    }

public:
    // Constructor khởi tạo heap với kích thước cho trước
    MinHeap(int sizeInput): heap(new int[sizeInput]), maxSize(sizeInput), size(0) {}

    // Destructor giải phóng bộ nhớ
    ~MinHeap() {
        delete[] heap;
    }

    // Thêm phần tử vào heap
    void insert(int value) {
        if (size == maxSize) {
            cout << "Your heap is full!" << endl;
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    // Xoá phần tử có giá trị cụ thể khỏi heap
    void del(int value) {
        bool check = false;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                check = true;
                heap[i] = heap[size - 1]; // Thay thế bằng phần tử cuối
                size--;
                heapifyDown(i); // Cập nhật lại cấu trúc heap
                break;
            }
        }
        if (!check) {
            cout << "Your value is not found!" << endl;
        }
    }

    // Xây dựng heap từ một mảng đầu vào
    void buildHeap(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insert(arr[i]);
        }
    }

    // In các phần tử của heap theo thứ tự mảng
    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Duyệt cây theo thứ tự tiền tự (preorder)
    void preorderTraversal(int i = 0) {
        if (i >= size) return;
        cout << heap[i] << " ";
        preorderTraversal(getLeftChildID(i));
        preorderTraversal(getRightChildID(i));
    }

    // Duyệt cây theo thứ tự trung tự (inorder)
    void inorderTraversal(int i = 0) {
        if (i >= size) return;
        inorderTraversal(getLeftChildID(i));
        cout << heap[i] << " ";
        inorderTraversal(getRightChildID(i));
    }

    // Duyệt cây theo thứ tự hậu tự (postorder)
    void postorderTraversal(int i = 0) {
        if (i >= size) return;
        postorderTraversal(getLeftChildID(i));
        postorderTraversal(getRightChildID(i));
        cout << heap[i] << " ";
    }
};

int main() {
    // Mảng ban đầu
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Tạo heap với kích thước đủ lớn
    MinHeap heap(n + 100);
    heap.buildHeap(arr, n);
    heap.print();

    // Duyệt theo các kiểu khác nhau
    cout << "Preorder: ";
    heap.preorderTraversal();
    cout << endl;

    cout << "Inorder: ";
    heap.inorderTraversal();
    cout << endl;

    cout << "Postorder: ";
    heap.postorderTraversal();
    cout << endl;

    // Thêm phần tử mới
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    heap.print();

    // Xoá các phần tử cụ thể
    heap.del(6);
    heap.del(13);
    heap.del(35);
    heap.print();

    return 0;
}