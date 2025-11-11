#ifndef TREENODE_H
#define TREENODE_H

#include <vector>

// Define DLL export/import macro
#ifdef GRAPH_LIBRARY_EXPORTS
#define GRAPH_LIBRARY_API __declspec(dllexport)
#else
#define GRAPH_LIBRARY_API __declspec(dllimport)
#endif

struct TreeNode
{
    int val;
    std::vector<TreeNode*> children;

    TreeNode(int v) : val(v) {};
};

#endif // TREENODE_H