#include <iostream>
#include "double_linked_list.h"

using namespace std;

int main(int argc, char* argv[]){
    d_linked_list * ll = new d_linked_list();
    for(int i=0; i < 10; i++){
        ll->append(i);
    }

    ll->print();
    cout << "print listo" << endl;
    ll->reverse();

    node_list * found = ll->find(5);
    if (found == NULL)  cerr << "Nodo no encontrado" << endl;
    else cerr << "Nodo encontrado" << endl;

    ll->delete_node(8);

    ll->print();
        
}
