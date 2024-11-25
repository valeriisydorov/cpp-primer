#ifndef BINSTRTREE_H
#define BINSTRTREE_H

#include "TreeNode.h"

class TreeNode;

class BinStrTree {
public:
    BinStrTree(): root(nullptr) {}
    BinStrTree(const BinStrTree& other) {
        if (other.root) {
            root = new TreeNode(*other.root);
        } else {
            root = nullptr;
        }
    }
    BinStrTree& operator=(const BinStrTree& other) {
        delete root;
        if (other.root) {
            root = new TreeNode(*other.root);
        } else {
            root = nullptr;
        }
        return *this;
    }
    ~BinStrTree() {
        delete root;
    }
private:
    TreeNode* root;
};

#endif
