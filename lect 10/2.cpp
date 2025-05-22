#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> graph(n + 1);  // danh sách kề (1-based)
    vector<int> distance(n + 1, -1);   // -1 nghĩa là chưa thăm

    // Nhập các cạnh có hướng
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // chỉ 1 chiều từ u -> v
    }

    // BFS bắt đầu từ X
    queue<int> q;
    q.push(X);
    distance[X] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << distance[Y] << endl; // in ra số cạnh ngắn nhất từ X đến Y
    return 0;
}