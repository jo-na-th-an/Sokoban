#include "GridNode.h"

GridNode::GridNode(char s) {
    this->symbol = s;
    this->next = nullptr;
    this->down = nullptr;
}
char GridNode::getSymbol() {
    return this->symbol;
}

GridNode* GridNode::getNext() {
    return this->next;
}

GridNode* GridNode::getDown() {
    return this->down;
}
void GridNode::setNext(GridNode* n) {
    this->next = n;
}

void GridNode::setDown(GridNode* d) {
    this->down = d;
}