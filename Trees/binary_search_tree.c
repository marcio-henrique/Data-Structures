//
// Created by ikkeg on 11/12/2019.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree bs_tree;

struct binary_search_tree {
    int item;
    bs_tree *left;
    bs_tree *right;
};

bs_tree* create_bs_tree();
bs_tree* add(bs_tree *root, int item);
bs_tree* remove_node(bs_tree *root, int item);
int search(bs_tree *root, int item);
void print_pre_order(bs_tree *root);
void print_in_order(bs_tree *root);
void print_post_order(bs_tree *root);
int is_empty(bs_tree *root);
int has_child(bs_tree *root);


bs_tree* create_bs_tree() {
    return NULL;
}

bs_tree* create_node(int item, bs_tree *left, bs_tree *right) {
    bs_tree *new_node = (bs_tree*) malloc(sizeof(bs_tree));
    new_node->item = item;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

bs_tree* add(bs_tree *root, int item) {
    if (is_empty(root)) {
        root = create_node(item, NULL, NULL);
        return root;
    }
    if(item <= root->item) {
        root->left = add(root->left, item);
    } else {
        root->right = add(root->right, item);
    }

    return root;
}

bs_tree* remove_node(bs_tree *root, int item) {
    return NULL;
}

int search(bs_tree *root, int item) {
    return 0;
}

void print_pre_order(bs_tree *root) {
    if(!is_empty(root)) {
        printf("%d ", root->item);
        print_pre_order(root->left);
        print_pre_order(root->right);
    }
}

void print_in_order(bs_tree *root) {
    if(!is_empty(root)) {
        print_in_order(root->left);
        printf("%d ", root->item);
        print_in_order(root->right);
    }
}

void print_post_order(bs_tree *root) {
    if(!is_empty(root)) {
        print_post_order(root->left);
        print_post_order(root->right);
        printf("%d ", root->item);
    }
}

int is_empty(bs_tree *root) {
    return (root == NULL);
}

int has_children(bs_tree *root) {
    return (root->left != NULL || root->right != NULL);
}
