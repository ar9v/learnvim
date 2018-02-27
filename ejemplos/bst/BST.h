// Andrés Ricardo Garza Vela A00820361
// Grupo 4
//
// BST.h : Tarea de programación número 7
//
// NOTA: Esta versión también contiene los métodos 
//       de la Tarea de programación número 8

#include "NodeTree.h"
#include <stack>
#include <queue>

class BST {
    public:
        BST();
        BST(const BST &objeto);
        ~BST();
        bool search(int data);
        void add(int data);
        void del(int data);
        void print(int tipo);
        void printLeaves();
        int count();
        int altura(NodeTree *r);
        int height(); 
        void ancestors(int data);
        int whatLevelamI(int data);
        void printLevel();
        int maxWidth();
        int nearestRelative(int numero1, int numero2);
        bool operator==(const BST &objeto);
        void mirror();
    

    private:
        NodeTree *root;
        int howManyChildren(NodeTree *aux);
        int predecesor(NodeTree *aux);
        int sucesor(NodeTree *aux);
        void preorden(NodeTree *r);
        void inorden(NodeTree *r);
        void postorden(NodeTree *r);
        void imprimeHojas(NodeTree *r);
        int cuentaNodos(NodeTree *r);
        void borraTodo(NodeTree *r);
        void preordenConstructor(NodeTree *r, queue<int> &bst);

}; 

BST::BST() {
    root = NULL;
}

BST::BST(const BST &objeto) {
    queue<int> bst;  
    preordenConstructor(objeto.root, bst); 
    
    this->root = new NodeTree(bst.front());
    bst.pop();
    while(!bst.empty()) {
        add(bst.front());  
        bst.pop();
    }
}

void BST::preordenConstructor(NodeTree *r, queue<int> &bst) {
    if(r != NULL) {
        bst.push(r->getData()); 
        preordenConstructor(r->getLeft(), bst);
        preordenConstructor(r->getRight(), bst);
    }
}

BST::~BST() {
    borraTodo(root);
}

void BST::borraTodo(NodeTree *r) {
    if(r != NULL) {
        borraTodo(r->getLeft());
        borraTodo(r->getRight());
        delete r;
    }
}

int BST::howManyChildren(NodeTree *aux) {
    int cont = 0;
    if(aux->getRight() != NULL)
        cont++;
    if(aux->getLeft() != NULL)
        cont++;
    return cont;
}

int BST::predecesor(NodeTree *aux) {
    NodeTree *aux1 = aux->getLeft();

    while(aux1->getRight() != NULL) {
        aux1 = aux1->getRight();
    }
    return aux1->getData();
}

int BST::sucesor(NodeTree *aux) {
    NodeTree *aux1 = aux->getRight();

    while(aux1->getLeft() != NULL) {
        aux1 = aux1->getLeft();
    }
    return aux1->getData();
}

void BST::preorden(NodeTree *r) {
    if(r != NULL) {
        cout << r->getData() << " ";
        preorden(r->getLeft());
        preorden(r->getRight());
    }
        
}

void BST::inorden(NodeTree *r) {
    if(r != NULL) {
        inorden(r->getLeft());
        cout << r->getData() << " ";
        inorden(r->getRight());
    }
}

void BST::postorden(NodeTree *r) {
    if(r != NULL) {
        postorden(r->getLeft());
        postorden(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::imprimeHojas(NodeTree *r) {
    if(r != NULL) {
        if(r->getLeft() == NULL && r->getRight() == NULL)
            cout << r->getData() << " ";
        else {
            imprimeHojas(r->getLeft());
            imprimeHojas(r->getRight());
        }
    }
}

int BST::cuentaNodos(NodeTree *r) {
    if(r == NULL)
        return 0;
    else
        return 1 + cuentaNodos(r->getLeft()) + cuentaNodos(r->getRight());
}

bool BST::search(int data) {
    NodeTree *aux = root;
    while(aux != NULL) {
        if(aux->getData() == data) 
            return true;
        aux = (aux->getData() > data ?  aux->getLeft() : aux->getRight());
    }
    return false;
}

void BST::add(int data) {
    if(root == NULL) 
        root = new NodeTree(data);
    else {
        NodeTree *father = NULL;
        NodeTree *aux = root;
        while(aux != NULL) {
            if(aux->getData() == data)
                return;
            father = aux;
            aux = (aux->getData() > data ?  aux->getLeft() : aux->getRight());
        }
        if(father->getData() > data)
            father->setLeft(new NodeTree(data));
        else
            father->setRight(new NodeTree(data)); 
    }
}

void BST::del(int data) {
    if(root == NULL) 
        return ;
    
    NodeTree *father = NULL;
    NodeTree *aux = root;

    while(aux->getData() != data) { // Seguimos recorriendo el árbol hasta encontrar el nodo a borrar
        father = aux;
        aux = (aux->getData() > data ? aux->getLeft() : aux->getRight());

        if(aux == NULL) // El número buscado no está en el árbol
            return ;
    }
    int contHijos = howManyChildren(aux); 
    if(contHijos == 0) {
        if(father == NULL)  // Si el nodo que buscamos es la raíz...
            root = NULL; // El árbol queda vacío...
        else {
            if(father->getData() > data) // Si no es la raíz y el dato es menor...
                father->setLeft(NULL);   // Ya no hay hijo izquierdo o...
            else
                father->setRight(NULL);  //... ya no hay derecho
        }
        delete aux; // Libera el espacio de memoria; las líneas de arriba no son sinónimos.
    }
    else if(contHijos == 1) {  
        if(father == NULL) { 
            if(aux->getLeft() != NULL) // Si el izquierdo no es null quiere decir que ése es el hijo
                root = aux->getLeft();
            else
                root = aux->getRight();
        }
        else { // Si el nodo a buscar no es la raíz
            NodeTree *nieto = (aux->getLeft() != NULL ? aux->getLeft() : aux->getRight());
            if(father->getData() > data) 
                father->setLeft(nieto);
            else
                father->setRight(nieto);
        }
        delete aux;
    }
    else {
        int suc = sucesor(aux);        
        del(suc);
        aux->setData(suc);
    }
}

void BST::print(int tipo) {
    switch (tipo) {
        case 1: preorden(root);
                break;
        case 2: inorden(root); 
                break;
        case 3: postorden(root);
                break;
        case 4: imprimeHojas(root);
                break;
        case 5: printLevel();
                break;
    }
    cout << endl;
}

//void BST::printLeaves() {
//    imprimeHojas(root);
//    cout << endl;
//}

int BST::count() {
    return cuentaNodos(root);
}

int BST::altura(NodeTree *r) {
    if(r == NULL)
        return 0;

    int camino_izquierda = altura(r->getLeft());
    int camino_derecha = altura(r->getRight());

    if(camino_izquierda > camino_derecha)
        return 1 + camino_izquierda;
    else
        return 1 + camino_derecha;
}

int BST::height() {
    return altura(root);
}

void BST::ancestors(int data) {
    NodeTree *aux = root;
    stack<int> ancestry;
    while(aux->getData() != data) {
        ancestry.push(aux->getData()); 
        aux = (aux->getData() > data ?  aux->getLeft() : aux->getRight());
        
        if(aux == NULL) {
            cout << "NO ANCESTORS" << endl;
            return ;
        }
    }
    if(aux == root)
        cout << "ROOT";

    while(!ancestry.empty()) {
        cout << ancestry.top() << " ";
        ancestry.pop();
    }
    cout << endl;
}

int BST::whatLevelamI(int data) {
    NodeTree *aux = root;
    int contador = -1;
    while(aux != NULL) {
        contador++;
        if(aux->getData() == data) 
            return contador;
        aux = (aux->getData() > data ?  aux->getLeft() : aux->getRight());
    }
    return -1;
}

void BST::printLevel() {
    queue<NodeTree*> levels;
    levels.push(root);

    while(!levels.empty()) {
        cout << levels.front()->getData() << " ";
        if(levels.front()->getLeft() != NULL)
            levels.push(levels.front()->getLeft());
        if(levels.front()->getRight() != NULL)
            levels.push(levels.front()->getRight());

        levels.pop(); 
    }

}

int BST::maxWidth() {
    if(root == NULL) 
        return 0;

    queue<NodeTree*> levels;
    levels.push(root);
    int levelWidth = 1;
    int width = 0;
    int maxNodes = 1;

    while(!levels.empty()) {
        levelWidth--;
        if(levels.front()->getLeft() != NULL) {
            levels.push(levels.front()->getLeft());
            width++;
        }
        if(levels.front()->getRight() != NULL) {
            levels.push(levels.front()->getRight());
            width++;
        }
        levels.pop(); 

        if(levelWidth == 0) {
            levelWidth = width;
            width = 0;
            if(maxNodes < levelWidth)
                maxNodes = levelWidth;
        }
    }
    return maxNodes;
}

int BST::nearestRelative(int numero1, int numero2) {
    NodeTree *aux = root;
    NodeTree *aux2 = root;
    NodeTree *father = root;
    NodeTree *father2 = root;
    int switchFather = 0;

    while(aux->getData() != numero1 || aux2->getData() != numero2) {
        if((aux->getData() > numero1 && aux2->getData() < numero2) || (aux->getData() < numero1 && aux2->getData() > numero2)) {
            if(search(numero1) && search(numero2))
                return aux->getData();
            else
                return 0;
        }

        if(aux->getData() != numero1) {
            father = aux;
            aux = (aux->getData() > numero1 ?  aux->getLeft() : aux->getRight());
        }
        else 
            if(switchFather == 0)
                switchFather = 1;

        if(aux2->getData() != numero2) {
            father2 = aux2;
            aux2 = (aux2->getData() > numero2 ?  aux2->getLeft() : aux2->getRight());
        }
        else 
            if(switchFather == 0)
                switchFather = 2;

        if(aux == NULL) 
            return 0;

    }
    if(aux == root || aux2 == root)
        return 0;

    if(switchFather == 1)
        return father->getData();
    else
        return father2->getData();
}

bool BST::operator==(const BST &objeto) {
    queue<int> bst1;
    queue<int> bst2;

    preordenConstructor(this->root, bst1);
    preordenConstructor(objeto.root, bst2);

    while(!bst1.empty()) {
        if(bst1.front() != bst2.front())
            return false;
        
        bst1.pop();
        bst2.pop();
    }
    if(!bst2.empty())
        return false;
    else
        return true;
}

void BST::mirror() {
    NodeTree *aux = root;
    queue<NodeTree*> levels;

    levels.push(root);

    while(!levels.empty()) {
        aux = levels.front()->getRight();
        levels.front()->setRight(levels.front()->getLeft());
        levels.front()->setLeft(aux);
        
        if(levels.front()->getLeft() != NULL)
            levels.push(levels.front()->getLeft());
        if(levels.front()->getRight() != NULL)
            levels.push(levels.front()->getRight());

        levels.pop();
    }
} 
