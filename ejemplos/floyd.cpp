#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits.h>
using namespace std;

#define nodes 5

void camino(int inicio, int fin, int P[][nodes]) {
    if(P[inicio][fin] != 0) {
        camino(inicio, P[inicio][fin] - 1, P);
        cout << P[inicio][fin] << " "; 
        camino(P[inicio][fin] - 1, fin, P);
    }
}

int main() {
    
    int nodos, caminos, queries;
    ifstream entrada;
    entrada.open("datosFloyd2.txt");
    entrada >> nodos >> caminos >> queries;
    int D[5][5] = {};
    int P[5][5] = {};

    // Inicializar las matrices
    for(int i = 0; i < nodos; i++)
        for(int j = 0; j < nodos; j++)
            D[i][j] = INT_MAX;

    for(int i = 0; i < nodos; i++)
        D[i][i] = 0;

    int nodo1, nodo2, ponderacion;
    // Inicializar la matriz de adyacencia con los datos
    for(int i = 0; i < caminos; i++) {
        entrada >> nodo1 >> nodo2 >> ponderacion; 
        D[nodo1-1][nodo2-1] =  ponderacion;
    }

    // FLOYD
    for(int k = 0; k < nodos; k++) {
        for(int i = 0; i < nodos; i++) {
            for(int j = 0; j < nodos; j++) {
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && (D[i][k] + D[k][j]) < D[i][j]) {
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    for(int i = 0; i < queries; i++) {
        entrada >> nodo1 >> nodo2;
        cout << nodo1 << " ";
        camino(nodo1 - 1, nodo2 - 1, P);
        cout << nodo2 << endl;
    }
    return 0;
}
