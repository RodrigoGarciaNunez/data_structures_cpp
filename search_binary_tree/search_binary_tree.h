#include <iostream>
#include "tree_node.h"

using namespace std;

class search_binary_tree{
public:
    search_binary_tree();
    void print_preorden();
    void print_preorden(tree_node *& aux);
    void add_node(int i);
    void add_node_recursive(int i);
    void add_node_recursive(tree_node *& child, tree_node *& aux);
    void delete_node(int i);
    bool search_node(int i, tree_node *& root);
     tree_node * root;
private:
   
};
