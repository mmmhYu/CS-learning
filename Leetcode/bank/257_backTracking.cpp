#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<int> path;
        vector<string> res;

        if (root)
            backTracking(root, path, res);

        return res;
    }

    void backTracking(TreeNode* p,vector<int>& path,vector<string>& res){
        path.push_back(p->val);

        if ((!p->left) && (!p->right)){
            string str = to_string(path[0]);

            for (int i = 1; i < path.size(); i++){
                str += "->" + to_string(path[i]);
            }

            res.push_back(str);
        }

        if (p->left)
            backTracking(p->left, path, res);

        if (p->right)
            backTracking(p->right, path, res);

        path.pop_back();
    }
};

int main() {
    Solution s;

    // Test 1
    //        1
    //       / \
    //      2   3
    //       \
    //        5
    //
    // Expected:
    // 1->2->5
    // 1->3

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);

    cout << "Test 1:" << endl;
    for (auto& path : s.binaryTreePaths(root1))
        cout << path << endl;


    // Test 2：只有一个节点
    //
    //      1
    //
    // Expected:
    // 1

    TreeNode* root2 = new TreeNode(1);

    cout << "\nTest 2:" << endl;
    for (auto& path : s.binaryTreePaths(root2))
        cout << path << endl;


    // Test 3：只有左孩子
    //
    //        1
    //       /
    //      2
    //     /
    //    3
    //   /
    //  4
    //
    // Expected:
    // 1->2->3->4

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(3);
    root3->left->left->left = new TreeNode(4);

    cout << "\nTest 3:" << endl;
    for (auto& path : s.binaryTreePaths(root3))
        cout << path << endl;


    // Test 4：比较完整的二叉树
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    //
    // Expected:
    // 1->2->4
    // 1->2->5
    // 1->3->6
    // 1->3->7

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    root4->right->left = new TreeNode(6);
    root4->right->right = new TreeNode(7);

    cout << "\nTest 4:" << endl;
    for (auto& path : s.binaryTreePaths(root4))
        cout << path << endl;


    // Test 5：节点值包含负数和多位数
    //
    //          10
    //         /  \
    //       -2    30
    //       /
    //     100
    //
    // Expected:
    // 10->-2->100
    // 10->30

    TreeNode* root5 = new TreeNode(10);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(30);
    root5->left->left = new TreeNode(100);

    cout << "\nTest 5:" << endl;
    for (auto& path : s.binaryTreePaths(root5))
        cout << path << endl;

    return 0;
}