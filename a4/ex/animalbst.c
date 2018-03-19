#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "animalbst.h"
#include "struct.h"


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
struct Node *_addNode(struct Node *cur, TYPE val)
{
    assert(val != NULL);
    if(cur == NULL){
        struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
        assert(newNode != NULL);
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(compare(cur->val, val) <= 0)
        cur->right = _addNode(cur->right, val);
    else
        cur->left = _addNode(cur->left, val);
    
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
    if(cur->left == NULL)
        return cur->val;
    /*write this*/
    return _leftMost(cur->left);
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
    if(cur->left != NULL) {
        cur->left = _removeLeftMost(cur->left);
        return cur;
    }
    else{
        struct Node *newNode = cur->right;
        free(cur);
        return newNode;
    }
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
    if(compare(cur->val, val) < 0)
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
    }
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

struct BSTree *uploaddatabase(){
    struct BSTree *database = newBSTree();
    struct data *data1 = (struct data*)malloc(sizeof(struct data));
    struct data *data2 = (struct data*)malloc(sizeof(struct data));
    struct data *data3 = (struct data*)malloc(sizeof(struct data));
    struct data *data4 = (struct data*)malloc(sizeof(struct data));
    struct data *data5 = (struct data*)malloc(sizeof(struct data));
    struct data *data6 = (struct data*)malloc(sizeof(struct data));
    struct data *data7 = (struct data*)malloc(sizeof(struct data));
    data1->number = 1;
    data1->content = "whale";
    data2->number = 2;
    data2->content = "is it a mamal?";
    data3->number = 3;
    data3->content = "sea turtle";
    data4->number = 4;
    data4->content = "does it live in the water?";
    data5->number = 5;
    data5->content = "cat";
    data6->number = 6;
    data6->content = "does it climb the tree?";
    data7->number = 7;
    data7->content = "dog";
    addBSTree(database, data4);
    addBSTree(database, data2);
    addBSTree(database, data3);
    addBSTree(database, data1);
    addBSTree(database, data5);
    addBSTree(database, data6);
    addBSTree(database, data7);
    return database;
}

