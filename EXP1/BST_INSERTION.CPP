#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert_iterative(struct TreeNode* root, int key) {
    struct TreeNode* newNode = createNode(key);
    

    if (root == NULL) {
        return newNode;
    }

    struct TreeNode* current = root;
    struct TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

void inorder_traversal(struct TreeNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, key;

    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        root = insert_iterative(root, key);
    }

    printf("Inorder traversal of the BST (Iterative):\n");
    inorder_traversal(root);

    return 0;
}

