#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char value[10];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char* val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->value, val);
    node->left = node->right = NULL;
    return node;
}


struct Node* createOpNode(char* op, struct Node* left, struct Node* right) {
    struct Node* node = createNode(op);
    node->left = left;
    node->right = right;
    return node;
}


void printPostOrder(struct Node* root) {
    if (root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%s ", root->value);
}

int main() {
    // Common subexpression (b - c)
    struct Node* b = createNode("b");
    struct Node* c = createNode("c");
    struct Node* sub_bc = createOpNode("-", b, c);


    struct Node* a1 = createNode("a");
    struct Node* d  = createNode("d");


    struct Node* mul1 = createOpNode("*", a1, sub_bc);
    struct Node* add1 = createOpNode("+", a1, mul1);


    struct Node* mul2 = createOpNode("*", sub_bc, d);


    struct Node* root = createOpNode("+", add1, mul2);

    printf("DAG Postfix Expression:\n");
    printPostOrder(root);
    printf("\n");

    return 0;
}

