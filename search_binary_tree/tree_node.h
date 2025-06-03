#include "../structure_node.h"

class tree_node:public structure_node<tree_node>{
public:
    tree_node(int i=-1);
    tree_node * next_left;
    //tree_node * right_child;
    //int val;
private:
    
};