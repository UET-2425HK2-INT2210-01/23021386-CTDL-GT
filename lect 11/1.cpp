#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

// Giá trị vô cực để biểu thị không có đường đi
const int INF = numeric_limits<int>::max();

// Cấu trúc biểu diễn một cạnh trong đồ thị
struct Edge {
    int to;     // Đỉnh kết thúc
    int dirty;  // trọng số cạnh
    Edge(int t, int d) : to(t), dirty(d) {}
};

// Cấu trúc biểu diễn một đỉnh trong hàng đợi ưu tiên (Dijkstra)
struct Node {
    int city;   // Thành phố hiện tại
    int cost;   // Chi phí từ đỉnh bắt đầu đến đây
    Node(int c, int cost) : city(c), cost(cost) {}

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

// Thuật toán Dijkstra tìm đường đi ít "dơ" nhất từ s đến e
void dijkstra(int n, int s, int e, const vector<vector<Edge>>& adj, int& total_dirty, vector<int>& path) {
    vector<int> dist(n + 1, INF);   // Khoảng cách từ s đến các đỉnh
    vector<int> prev(n + 1, -1);    // Mảng truy vết để xây dựng đường đi
    dist[s] = 0;

    // Hàng đợi ưu tiên (min-heap)
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(s, 0));

    while (!pq.empty()) {
        Node current = pq.top(); pq.pop();
        int u = current.city;
        int d = current.cost;
        if (d > dist[u]) continue; // Bỏ qua nếu đã có đường ngắn hơn

        // Duyệt các cạnh kề
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].to;
            int dirty = adj[u][i].dirty;
            // Nếu tìm được đường đi tốt hơn
            if (dist[u] + dirty < dist[v]) {
                dist[v] = dist[u] + dirty;
                prev[v] = u;
                pq.push(Node(v, dist[v]));
            }
        }
    }

    total_dirty = dist[e]; // Tổng mức độ "dơ" nhỏ nhất từ s đến e
    if (total_dirty == INF) return; // Không có đường đi

    // Xây dựng lại đường đi từ s đến e
    for (int at = e; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
}

// Thuật toán Floyd-Warshall tìm đường đi ngắn nhất giữa mọi cặp đỉnh
vector<vector<int>> floyd_warshall(int n, const vector<vector<int>>& mat) {
    vector<vector<int>> dist = mat;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    // Danh sách kề để dùng cho Dijkstra
    vector<vector<Edge>> adj(n + 1);

    // Ma trận khoảng cách để dùng cho Floyd-Warshall
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) mat[i][i] = 0; // Khoảng cách từ đỉnh đến chính nó là 0

    // Đọc dữ liệu cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        adj[u].push_back(Edge(v, d)); // Thêm vào danh sách kề
        mat[u][v] = min(mat[u][v], d); // Ghi vào ma trận nếu có đường tốt hơn
    }

    // Chạy Dijkstra để tìm đường đi từ s đến e
    int total_dirty;
    vector<int> path;
    dijkstra(n, s, e, adj, total_dirty, path);

    // Ghi ra mức độ "dơ" tổng cộng
    fout << (total_dirty == INF ? "INF" : to_string(total_dirty)) << "\n";

    // Ghi ra đường đi
    for (size_t i = 0; i < path.size(); ++i)
        fout << path[i] << (i + 1 < path.size() ? " " : "\n");

    // Chạy Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp
    vector<vector<int>> dist_matrix = floyd_warshall(n, mat);

    // Ghi ra ma trận khoảng cách
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist_matrix[i][j] == INF)
                fout << "INF";
            else
                fout << dist_matrix[i][j];
            fout << (j < n ? " " : "\n");
        }
    }

    return 0;
}