#include<stdio.h>
#include<string.h>
#include <stdlib.h>

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

void printTree(struct Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    printTree(root->right);
    printf("%s ", root->value);
}
int main(){

    struct Node* N1 = createNode("a");
    struct Node* N2 = createNode("a");
    struct Node* N3 = createNode("b");
    struct Node* N4 = createNode("c");
    struct Node* N5 = createNode("b");
    struct Node* N6 = createNode("c");
    struct Node* N7 = createNode("d");

    struct Node* sub1 = createOpNode("-", N3, N4);
    struct Node* mul1 = createOpNode("*", N2, sub1);
    struct Node* add1 = createOpNode("+", N1, mul1);

    struct Node* sub2 = createOpNode("-", N5, N6);
    struct Node* mul2 = createOpNode("*", sub2, N7);


    struct Node* root = createOpNode("+", add1, mul2);


       printf("Abstract Syntax Tree in Post-order Traversal:\n");
       printTree(root);
       printf("\n");

  return 0;
}
