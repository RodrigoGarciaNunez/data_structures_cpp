#include "double_linked_list.h"


linked_list::linked_list(){
    raiz = NULL;
    bottom = NULL;
    size =0;
}

void linked_list::add_node(int i){
    node_list * newNode = new node_list(i);
    size++;
    if (raiz == NULL){
        raiz = newNode;
        bottom = newNode;
        return;
    }

    node_list * aux;
    aux = bottom;
    newNode->prev = bottom;
    bottom = newNode;
    aux->next = newNode;

    
}

void linked_list::delete_node(int to_delete){
    node_list *  node =  find_node(to_delete);
    if (node == NULL){
        cerr << "NO está el nodo al eliminar" << endl;
        return;
    }
    node_list * izquerda = node->prev;
    node_list * derecha = node->next;

    derecha->prev = izquerda;
    izquerda->next = derecha;

    node->next = NULL;
    node->prev = NULL;

    free(node);
    cerr << "Nodo borrado" << endl;
}

node_list * linked_list::find_node(int looking){
    node_list * left_aux = raiz->next;
    node_list * right_aux = bottom->prev;
    node_list * found =NULL;
    int izquierda, derecha;
    if (raiz->value == looking || bottom->value == looking){

            found = (raiz->value == looking) ? found=raiz : found = bottom;
            izquierda = (found->prev != NULL) ? found->prev->value : -1;
            derecha = (found->next != NULL) ? found->next->value : -1;

            cerr << "Valor: "<< found->value << " Siguiente: "<< derecha <<"Izquierda: " << izquierda << endl;
            return found;
        }

    while (left_aux != right_aux){
        if (left_aux->value == looking || right_aux->value == looking){
            found = (left_aux->value == looking) ? found=left_aux : found = right_aux;

            izquierda = (found->prev != NULL) ? found->prev->value : -1;
            derecha = (found->next != NULL) ? found ->next->value : -1;

            cerr << "Valor: "<< found->value << " Siguiente: "<< derecha <<"Izquierda: " << izquierda << endl;
            return found;
        }

        left_aux = left_aux->next;
        right_aux = right_aux->prev;
    }
    
    return NULL;
}

void linked_list::reverse(){
    node_list *current = raiz;
    node_list *aux = current;
    raiz = bottom;
    bottom = aux;
    aux = current->next;

    int left_counter =0;
    int izq, der;
    while(current != NULL){
        aux = current->next;
        current->next = current->prev;
        current->prev = aux;
        izq = (current->prev != NULL)? current->prev->value : -1;
        der =  (current->next != NULL)? current->next->value: -1;

        current = current->prev;
    }
    
    print_list();
}


void linked_list::print_list(){
    node_list * aux = raiz;
    while (aux != NULL){
        cout << "current:" << aux->value;
        if(aux->next!= NULL) cout <<  " next:" << aux->next->value;
        else cout <<" next: NULL";
        
        if(aux->prev !=NULL) cout <<  " prev:" << aux->prev->value;
        else cout << " prev: NULL";

        cout << endl;
        aux = aux->next;
    }
    cout << "\n\n"  << endl;
}
