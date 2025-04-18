#include <iostream>
using namespace std;

// Hàm đệ quy tìm UCLN
int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
        // y sẽ dần dần tiến về 0, khi đó y==0
        
        /* cụ thể như ví dụ
        gcd(10, 50) có y != 0 -> gcd(50, 10%50) -> gcd(50, 10)
        gọi đệ quy tiếp gcd(50, 10) -> gcd(10, 50%10) -> gcd(10, 0) -> điều kiện dừng
        -> y == 0 -> x là UCLN
        */
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;

    return 0;
}