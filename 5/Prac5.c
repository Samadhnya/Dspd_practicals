#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(int nodecount, int* nodeinserted) {
    if (*nodeinserted >= nodecount) 
	return NULL;

    int data;
    printf("Enter node data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) 
	return NULL;

    struct node* newnode = create(data);
    (*nodeinserted)++;

    printf("Enter left child of %d:\n", data);
    newnode->left = insert(nodecount, nodeinserted);

    printf("Enter right child of %d:\n", data);
    newnode->right = insert(nodecount, nodeinserted);

    return newnode;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void search(struct node* root, int key) {
    if (root == NULL) 
	return;
    if (root->data == key) {
        printf("Found\n");
        return;
    }
    search(root->left, key);
    search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, nodeinserted = 0, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Create binary tree:\n");
    root = insert(n, &nodeinserted);

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}
