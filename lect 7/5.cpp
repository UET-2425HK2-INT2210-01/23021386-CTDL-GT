#include <iostream>
#include <vector>
using namespace std;

// Hàm sinh ra tất cả các hoán vị
void Permutations(vector<int>& arr, vector<bool>& used, int n, int index) {
    // Nếu đã đạt đến độ dài n thì in ra tất cả các hoán vị
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    // Quay lui:
    for (int i = 0; i < n; ++i) {
        // Nếu phần tử chưa được sử dụng
        if (!used[i]) {
            // Đánh dấu phần tử đã được sử dụng
            used[i] = true;
            arr[index] = i + 1; // Lưu giá trị phần tử vào vị trí hiện tại (i + 1 vì chỉ số bắt đầu từ 0)
            
            // Đệ quy để chọn phần tử tiếp theo cho hoán vị
            Permutations(arr, used, n, index + 1);
            
            // Quay lại trạng thái ban đầu, đánh dấu phần tử là chưa sử dụng
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Mảng lưu các phần tử của hoán vị
    vector<int> arr(n);
    
    // Mảng used lưu trạng thái của các phần tử đã sử dụng
    vector<bool> used(n, false);

    // Gọi hàm đệ quy để sinh ra tất cả các hoán vị
    Permutations(arr, used, n, 0);

    return 0;
}