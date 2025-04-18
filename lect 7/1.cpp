#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mở file đầu vào
    ifstream inputFile("numbers.txt");
    // Mở file đầu ra
    ofstream outputFile("numbers.sorted");


    vector<double> numbers; // Lưu trữ các số thực
    double num;

    // Đọc các số từ file (có thể cách nhau bởi khoảng trắng hoặc xuống dòng)
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    // Sắp xếp các số theo thứ tự tăng dần
    sort(numbers.begin(), numbers.end());

    // Ghi kết quả đã sắp xếp vào file đầu ra
    for (size_t i = 0; i < numbers.size(); ++i) {
        outputFile << numbers[i];
        if (i != numbers.size() - 1) {
            outputFile << " "; // Thêm dấu cách giữa các số
        }
    }

    // Đóng các file
    inputFile.close();
    outputFile.close();

    return 0;
}