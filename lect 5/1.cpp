#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Tree{ // tạo lớp cây
public:
    unordered_map<int, vector<int>> adj;  // lưu cấu trúc cây vào adj, int là khóa(nút cha), vector<int> chứa các nút con
    
    void addedge(int parent, int child){  // hàm thêm cạnh, parent(nút cha) -> child(nút con)
        adj[parent].push_back(child);  // thêm vào cuối danh sách adj các nút con, adj chứa tất cả các nút con của nút cha
    }
    
    int height(int node){ // tính chiều cao cây từ nút được gọi
        int h = 0;
        for(int child : adj[node]){ // duyệt các nút con của nút hiện tại
            h = max(h, height(child) + 1);
            // dùng đệ quy, nếu 1 nút không có nút con thì sẽ trả về 0, +1 để tính thêm cạnh nốt nút đến con
        }
        return h;
    }
    
    void preorder(int node){  // hàm duyệt cây theo thứ tự trước (preorder)
        cout << node << " ";  // in nút hiện tại để bắt đầu duyệt
        for(int child : adj[node]){  // duyệt các nút con của nút hiện tại
            preorder(child);
            // sử dụng đệ quy để in ra các nút con của nút hiện tại, in nút cha trước rồi tới nút con
        }
    }
    
    void postorder(int node ){ // duyệt cây theo thứ tự sau (postorder)
        for (int child : adj[node]){  //duyệt các nút con
            postorder(child);
            // dùng đệ quy để duyệt tất cả các nút con của 1 nút cha trước, in tất cả nút con rồi tới nút cha
        }
        cout << node << " ";  // in ra nút hiện tại
    }
    
    void inorder(int node){  // duyệt cây theo thứ tự giữa, trái-gốc-phải
        if (adj[node].size() > 0) inorder(adj[node][0]);
        // duyệt từ nút con bên trái trước
        cout << node << " ";  // in ra nút hiện tại
        if (adj[node].size() > 1) inorder(adj[node][1]);
        // duyệt nút con bên phải
    }
    
    bool checkBinary(){ // kiểm tra cây nhị phân
        for(auto& [parent, child_list] : adj){  
        // auto giúp tự động xác định kiểu dữ liệu (parent là int, child_list là vector<int>)
            if(child_list.size() > 2) return false;  // nhiều hơn 2 con thì không phải là cây nhị phân
        }
        return true;
    }
};

int roottree(const unordered_map<int, vector<int>>& adj){ // hàm tìm gốc cây
    unordered_set<int> children;  // tập hợp lưu các nút con
    for (const auto& [parent, child_list] : adj) {  // duyệt từng cặp parent và child_list trong danh sách
        for (int child : child_list) {  //  duyệt từng nút con trong child_list
            children.insert(child);  // các nút con được thêm vào children
        }
    }
    for (const auto& [parent, _] : adj) {  // duyệt qua các nút cha
        if (children.find(parent) == children.end()) {  // kiểm tra xem parent có trong children không
            return parent;  // nút không có cha là gốc
        }
    }
    return -1;  // không tìm thấy gốc
}

int main(){
    int n, m;
    cin >> n >> m;  // nhập số lượng nút và cạnh
    Tree tree;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;   // nhập từng cặp cạnh
        tree.addedge(u, v);
    }

    int root = roottree(tree.adj);     // tìm gốc của cây
    cout << tree.height(root) << endl; // in ra chiều cao của cây
    tree.preorder(root);
    cout << endl;  // duyệt trước
    tree.postorder(root);
    cout << endl;  // duyệt sau
    if (tree.checkBinary()) {
        tree.inorder(root);
        cout << endl;  // Duyệt giữa nếu là cây nhị phân
        }
    else cout << "NOT BINARY TREE" << endl; // Thông báo nếu không phải cây nhị phân
    return 0;
}