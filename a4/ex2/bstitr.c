/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "bstitr.h"
#include "structs.h"


struct Node {
    TYPE         val;
    struct Node *left;
    struct Node *right;
};

struct BSTree {
    struct Node *root;
    int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
 root is null
 */

void initBSTree(struct BSTree *tree)
{
    tree->cnt  = 0;
    tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
 tree->root = 0;
 */

struct BSTree*  newBSTree()
{
    struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
    assert(tree != 0);
    
    initBSTree(tree);
    return tree;
}

/*----------------------------------------------------------------------------*/
/*
 function to free the nodes of a binary search tree
 param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
 */

void _freeBST(struct Node *node)
{
    if (node != 0) {
        _freeBST(node->left);
        _freeBST(node->right);
        free(node);
    }
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
 tree->root = 0;
 tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
    _freeBST(tree->root);
    tree->root = 0;
    tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
    clearBSTree(tree);
    free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.
 
 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
 function to determine the size of a binary search tree
 
 param: tree    the binary search tree
 pre:  tree is not null
 */
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node* _addNode(struct Node *cur, TYPE val)
{
    assert(val != NULL);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->right = NULL;
    temp->left = NULL;
    struct Node *rootcpy = cur;
    if(cur == NULL)
        return temp;
    while(cur != NULL){
        if(compare(cur->val, val) <= 0){
            if(cur->right == NULL){
                cur->right = temp;
                break;
            }
            else
                cur = cur->right;
        }
        else
        {
            if(cur->left == NULL){
                cur->left = temp;
                break;
            }
            else
                cur = cur->left;
        }
    }
    cur = rootcpy;
 
    return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
 val		the value to be added to the tree
 
 pre:	tree is not null
 val is not null
 pose:  tree size increased by 1
 tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
    tree->root = _addNode(tree->root, val);
    tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
 val		the value to search for in the tree
 pre:	tree is not null
 val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
    assert(tree != NULL && val != NULL);
    struct Node *cur = tree->root;
    while (cur != NULL) {
        if(compare(cur->val , val) < 0)
            cur = cur->right;
        else if(compare(cur->val, val) == 0)
            return 1;
        else
            cur = cur->left;
    }
    /*write this*/
    return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
    assert(cur != NULL);
    while(cur->left != NULL)
        cur = cur->left;
    /*write this*/
    return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.
 
 Note:  If you do this iteratively, the above hint does not apply.
 
 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
    assert(cur != NULL);
    struct Node * rootcpy = cur;
    if(cur->left == NULL){
        cur = NULL;
        free(cur);
        return cur;
    }
    while(cur->left != NULL){
        cur = cur->left;
    }
    cur->val = NULL;
    cur = NULL;
    free(cur);
    cur = rootcpy;
    return cur;
}

/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
 val	the value to be removed from the tree
 pre:	val is in the tree
 cur is not null
 val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
    assert(cur != NULL && val != NULL);
    struct Node *target = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    while (1) {
        if(compare(cur->val , val) == 0){
            target = cur;
        }
        if(compare(cur->val, val) < 0){
            if(cur->right == NULL)
                break;
            prev = cur;
            cur = cur->right;
        }
            
        else{
            if (cur->left == NULL) {
                break;
            }
            prev = cur;
            cur = cur->left;
        }
    }
    target->val = cur->val;
    if (prev->left == cur)
        prev->left = cur->right;
    else
        prev->right = cur->left;
    cur = NULL;
    free(cur);
    
    

    /*if(compare(cur->val, val) < 0)
        cur->right = _removeNode(cur->right, val);
    else if(compare(cur->val , val) > 0)
        cur->left = _removeNode(cur->left, val);
    else{
        if(cur->right == 0){
            return cur->left;
        }
        else{
            cur->val = _leftMost(cur->right);
            cur->right = _removeLeftMost(cur->right);
        }
    }*/
    /*write this*/
    return cur;
    
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
 val		the value to be removed from the tree
 pre:	tree is not null
 val is not null
 val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
    if (containsBSTree(tree, val)) {
        tree->root = _removeNode(tree->root, val);
        tree->cnt--;
    }
}
double getMilliseconds() {
    return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]){
    
    /*//After implementing your code, please uncommnet the following calls to the test functions and test your code
    
    testAddNode();
    
    printf("\n");
    testContainsBSTree();
    
    printf("\n");
    testLeftMost();
    
    printf("\n");
    testRemoveLeftMost();
    
    printf("\n");
    testRemoveNode();*/
    int n = 320000,i;
    double t1,t2;
    struct BSTree *tree = newBSTree();
    struct data mydata[320000];
    
    for(i=0;i<n;i++){
        mydata[i].number = rand();
        mydata[i].name = "a";
        addBSTree(tree, &mydata[i]);
    }
    t1 = getMilliseconds();
    for (i=0; i<n; i++) {
        containsBSTree(tree, &mydata[i]);
    }
    t2 = getMilliseconds();
    printf("Time for running contains() on %d elements: %g ms\n", n, t2-t1);
    t1 = getMilliseconds();
    for (i=0; i<n; i++) {
        removeBSTree(tree, &mydata[i]);
    }
    t2 = getMilliseconds();
    printf("Time for running remove() on %d elements: %g ms\n", n, t2-t1);
    deleteBSTree(tree);
    return 0;
}
