#include "double_linked_list.h"


d_linked_list::d_linked_list(): data_structure(){
    root = nullptr;
    bottom = nullptr;
    size =0;
}

void d_linked_list::append(int i){
    node_list * newNode = new node_list(i);
    size++;
    if (root == nullptr){
        root = newNode;
        bottom = newNode;
        return;
    }

    node_list * aux;
    aux = bottom;
    newNode->prev = bottom;
    bottom = newNode;
    aux->next_right = newNode;

    
}

void d_linked_list::delete_node(int to_delete){
    node_list * node = find(to_delete);
    //node = static_cast<node_list*>(node);

    if (node == nullptr){
        cerr << "NO está el nodo al eliminar" << endl;
        return;
    }
    node_list * izquerda = node->prev;
    node_list * derecha = node->next_right;

    derecha->prev = izquerda;
    izquerda->next_right = derecha;

    node->next_right = nullptr;
    node->prev = nullptr;

    free(node);
    cerr << "Nodo borrado" << endl;
}

node_list * d_linked_list::find(int looking){
    node_list * left_aux = root->next_right;
    node_list * right_aux = bottom->prev;
    node_list * found =nullptr;
    int izquierda, derecha;
    if (root->id == looking || bottom->id == looking){

            found = (root->id == looking) ? found=root : found = bottom;
            izquierda = (found->prev != nullptr) ? found->prev->id : -1;
            derecha = (found->next_right != nullptr) ? found->next_right->id : -1;

            cerr << "Valor: "<< found->id << " Siguiente: "<< derecha <<"Izquierda: " << izquierda << endl;
            return found;
        }

    while (left_aux != right_aux){
        if (left_aux->id == looking || right_aux->id == looking){
            found = (left_aux->id == looking) ? found=left_aux : found = right_aux;

            izquierda = (found->prev != nullptr) ? found->prev->id : -1;
            derecha = (found->next_right != nullptr) ? found ->next_right->id : -1;

            cerr << "Valor: "<< found->id << " Siguiente: "<< derecha <<"Izquierda: " << izquierda << endl;
            return found;
        }

        left_aux = left_aux->next_right;
        right_aux = right_aux->prev;
    }
    
    return nullptr;
}

void d_linked_list::reverse(){
    node_list *current = root;
    node_list *aux = current;
    root = bottom;
    bottom = aux;
    aux = current->next_right;

    int left_counter =0;
    int izq, der;
    while(current != nullptr){
        aux = current->next_right;
        current->next_right = current->prev;
        current->prev = aux;
        izq = (current->prev != nullptr)? current->prev->id : -1;
        der =  (current->next_right != nullptr)? current->next_right->id: -1;

        current = current->prev;
    }
    
    print();
}


void d_linked_list::print(){
    node_list * aux = root;
    while (aux != nullptr){
        cout << "current:" << aux->id;
        if(aux->next_right!= nullptr) cout <<  " next_right:" << aux->next_right->id;
        else cout <<" next_right: nullptr";
        
        if(aux->prev !=nullptr) cout <<  " prev:" << aux->prev->id;
        else cout << " prev: nullptr";

        cout << endl;
        aux = aux->next_right;
    }
    cout << "\n\n"  << endl;
}
