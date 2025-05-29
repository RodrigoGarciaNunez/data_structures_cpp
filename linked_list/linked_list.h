#include "node_list.h"

class linked_list{
public:
    linked_list();
    void append(int i);
    void delete_node(int i);
    node_list * find_node(int i);
    void print_list();
    void reverse();
private:
    node_list * root;

};