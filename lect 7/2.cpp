#include <iostream>
#include <fstream>
#include <vector>
#include <climits> // Để dùng INT_MIN

using namespace std;

int main() {
    // Mở file đầu vào và đầu ra
    ifstream inputFile("matrix.txt");
    ofstream outputFile("matrix.out");

    int m, n;
    inputFile >> m >> n; // Đọc số hàng (m) và số cột (n)

    // Đọc ma trận từ file
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            inputFile >> matrix[i][j];

    // Biến lưu kết quả lớn nhất tìm được
    int maxSum = INT_MIN;
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

    // Duyệt qua tất cả cặp hàng trên - dưới (top-bottom)
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // Mảng tạm đại diện cho tổng theo cột

        for (int bottom = top; bottom < m; ++bottom) {
            // Cộng dồn các giá trị hàng từ top tới bottom theo từng cột
            for (int col = 0; col < n; ++col)
                temp[col] += matrix[bottom][col];

            int sum = 0, startCol = 0;
            int localLeft = 0, localRight = 0;
            int localMax = INT_MIN;

            for (int col = 0; col < n; ++col) {
                sum += temp[col];

                if (sum > localMax) {
                    localMax = sum;
                    localLeft = startCol;
                    localRight = col;
                }

                if (sum < 0) {
                    sum = 0;
                    startCol = col + 1; // Bắt đầu lại dãy mới
                }
            }

            // Nếu tìm được tổng lớn hơn, cập nhật kết quả
            if (localMax > maxSum) {
                maxSum = localMax;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = localLeft;
                finalRight = localRight;
            }
        }
    }

    // Ghi kết quả ra file (dùng chỉ số bắt đầu từ 1)
    outputFile << finalTop + 1 << " " << finalLeft + 1 << " "
               << finalBottom + 1 << " " << finalRight + 1 << " "
               << maxSum << endl;

    return 0;
}