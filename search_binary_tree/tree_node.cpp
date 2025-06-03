#include "tree_node.h"

tree_node::tree_node(int i): structure_node(i){
    //this->val = i;
    next_right = nullptr;
    next_left = nullptr;
}