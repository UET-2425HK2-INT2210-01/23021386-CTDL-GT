#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, X;
    cin >> n >> X; 

    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i]; // nhập mảng
    }

    bool sum = false; // biến để kiểm tra xem có dãy con nào hợp lệ không
    for (int i=0; i<n; i++) {
        int count = 0; 
        for (int j = i; j < n; j++) {
            count += a[j]; // cộng dồn các phần tử
            if (count == X) { 
                sum = true; // đánh dấu đã tìm được
                break; 
            }
        }
        if (sum) break; // nếu tìm thấy rồi thì out khỏi vòng lặp
    }
    if (sum) 
        cout << "YES\n" ;
    else 
        cout << "NO\n" ;

    return 0;
}