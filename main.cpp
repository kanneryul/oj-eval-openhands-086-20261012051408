#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int left;
    int right;
    TreeNode() : left(-1), right(-1) {}
    TreeNode(int l, int r) : left(l), right(r) {}
};

vector<TreeNode> tree;
vector<int> inorder_result;

void inorder_traversal(int node, int depth) {
    if (node == -1) return;
    
    // Traverse left subtree
    inorder_traversal(tree[node].left, depth + 1);
    
    // Visit current node
    inorder_result.push_back(node);
    
    // Traverse right subtree
    inorder_traversal(tree[node].right, depth + 1);
}

void swap_subtrees(int node, int depth, int k) {
    if (node == -1) return;
    
    // If current depth is a multiple of k, swap left and right subtrees
    if (depth % k == 0) {
        swap(tree[node].left, tree[node].right);
    }
    
    // Recursively process left and right subtrees
    swap_subtrees(tree[node].left, depth + 1, k);
    swap_subtrees(tree[node].right, depth + 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Resize tree to accommodate nodes 1 to n
    tree.resize(n + 1);
    
    // Read tree structure
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        tree[i] = TreeNode(left, right);
    }
    
    int t;
    cin >> t;
    
    // Process each operation
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Perform swapping operation
        swap_subtrees(1, 1, k);  // Start from root at depth 1
        
        // Perform inorder traversal and output result
        inorder_result.clear();
        inorder_traversal(1, 1);  // Start from root at depth 1
        
        // Output inorder traversal
        for (size_t j = 0; j < inorder_result.size(); j++) {
            if (j > 0) cout << " ";
            cout << inorder_result[j];
        }
        cout << "\n";
    }
    
    return 0;
}