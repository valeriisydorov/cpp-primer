#ifndef TREENODE_H
#define TREENODE_H

#include <string>

class TreeNode {
public:
    TreeNode(std::string s): value(s), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& orig): value(orig.value), count(orig.count), left(nullptr), right(nullptr) {
        if (orig.left) {
            left = new TreeNode(*orig.left);
        }
        if (orig.right) {
            right = new TreeNode(*orig.right);
        }
    }
    TreeNode& operator=(const TreeNode& orig) {
        delete left;
        delete right;

        value = orig.value;
        count = orig.count;
        left = nullptr;
        right = nullptr;

        if (orig.left) {
            left = new TreeNode(*orig.left);
        }
        if (orig.right) {
            right = new TreeNode(*orig.right);
        }

        return *this;
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
private:
    std::string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

#endif
