#include "linked_list.h"

using namespace std;

int main(int argc, char * argv[]){
    linked_list * ll = new linked_list();
    for(int i=0; i < 10; i++){
        ll->append(i);
    }

    ll->print_list();
    cout << "print listo" << endl;
    ll->reverse();
    cout << "reverse listo" << endl;
    ll->print_list();

    node_list * found = ll->find_node(11);
    if (found == nullptr)  cerr << "Nodo no encontrado" << endl;
    else cerr << "Nodo encontrado" << endl;

    ll->delete_node(8);

    ll->print_list();
        
}