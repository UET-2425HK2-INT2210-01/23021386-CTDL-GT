#include <iostream>
using namespace std;

// Hàm đệ quy để tạo các chuỗi nhị phân độ dài n
void Binary(int n, string output = "") {
    // Nếu độ dài chuỗi hiện tại bằng n → in ra chuỗi đó
    if (output.length() == n) {
        cout << output << endl;
        return;
    }

    // Thêm '0' vào chuỗi và gọi đệ quy
    Binary(n, output + "0");

    // Thêm '1' vào chuỗi và gọi đệ quy
    Binary(n, output + "1");
}

int main() {
    int n;
    cin >> n;

    // bắt đầu  chuỗi nhị phân
    Binary(n);

    return 0;
}