#include <iostream>
#include "../structure_node.h"

class node_list: public structure_node<node_list> {
public:
    node_list(int i);
    //node_list * next;
    node_list * prev;
    //int value;
private:
    
};
