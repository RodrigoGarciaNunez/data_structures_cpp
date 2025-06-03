#include <iostream>
#include "structure_node.h"

using namespace std;

template <typename t>
class data_structure{
public:
    data_structure();
    virtual void append(int i);
    virtual t * find(int i);
    virtual void delete_node(int i);
    virtual void insert();
    virtual void print();
    t * root;
    int size;
    
protected:
   
};