#include "node_list.h"
#include "../data_structure.h"

class linked_list: public data_structure<node_list>{
public:
    linked_list();
    void append(int i) override;
    void delete_node(int i) override;
    node_list * find(int i) override;
    void print() override;
    void reverse();

private:
    //node_list * root;

};