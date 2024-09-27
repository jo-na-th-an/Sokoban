#pragma once

class GridNode {
private:
    char symbol;       // Símbolo en la posición del grid
    GridNode* next;    // Puntero al siguiente nodo en la misma fila
    GridNode* down;    // Puntero al siguiente nodo en la misma columna

public:
    // Constructor
    GridNode(char s);

    // Getters
    char getSymbol();
    GridNode* getNext();
    GridNode* getDown();

    // Setters
    void setNext(GridNode* n);
    void setDown(GridNode* d);
};