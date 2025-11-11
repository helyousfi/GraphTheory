#include "pch.h"
#ifdef EXCLUDE_THIS_FILE
#include <iostream>
#include "tree.hpp"

int LeafSum(TreeNode* node)
{
    if(node->children.size() == 0) // isLeaf
        return node->val;
    int total = 0;
    for(TreeNode* nodeIterator : node->children)
    {
        total += LeafSum(nodeIterator);
    }
    return total;
}

int TreeHeight(TreeNode* node) {
    if (node == nullptr) {
        return -1;
    }
    if (node->children.size() == 0) {
        return 0; 
    }
    int maxChildHeight = -1;
    for (TreeNode* child : node->children) {
        maxChildHeight = std::max(maxChildHeight, TreeHeight(child));
    }
    return maxChildHeight + 1;
}
#else
#endif