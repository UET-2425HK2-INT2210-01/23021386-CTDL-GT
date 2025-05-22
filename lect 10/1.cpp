#include <iostream>
#include <vector>
using namespace std;

// Hàm DFS: duyệt từ đỉnh 'u' và đánh dấu các đỉnh liên thông
void DFS(int u, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v, graph, visited);
        }
    }
}

int main() {
    int n, m; // số đỉnh và số cạnh
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);  // danh sách kề (1-based)
    vector<bool> visited(n + 1, false); // đánh dấu các đỉnh đã thăm

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x); // vì đồ thị vô hướng
    }

    int count = 0; // đếm số thành phần liên thông

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(i, graph, visited); // duyệt 1 thành phần
            count++;                // tăng số thành phần
        }
    }

    cout << count << endl; // in ra kết quả
    return 0;
}