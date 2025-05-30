#include <iostream>
#include "tree_node.h"

using namespace std;

class search_binary_tree{
public:
    search_binary_tree();
    void print_preorden(tree_node * aux = nullptr);
    void add_node(int i);
    void add_node_recursive(tree_node *& root, tree_node *aux = nullptr, int i =-1);
    void delete_node(int i);
    tree_node *& search_node(int i, tree_node *& root);
    tree_node * root;

private:
   
};
