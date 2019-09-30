#if !defined(TREE_H)
#define TREE_H

#include <stdlib.h> /* for size_t definition */

/**
 * Structure to hold all data for one list element
 */
typedef struct NodeStruct {
    struct NodeStruct *parent;   /**< pointer to parent tree node, in case we need it */
    struct NodeStruct *child[2]; /**< pointers to child tree nodes 0 = left, 1 = right */
    void* content;               /**< pointer to element content */
    size_t size;                     /**< size of content */
    unsigned int red : 1;
} Node;


/**
 * Structure to hold all data for one tree
 */
typedef struct {
    struct {
        Node *root;     /**< root node pointer */
        int (*compare)(void*, void*, int);  /**< comparison function */
    } index[2];
    int indexes;        /**< no of indexes into tree */
    int count;          /**< no of items */
    size_t size;        /**< heap storage used */
} Tree;


Tree* TreeInitialize(int(*compare)(void*, void*, int));
void TreeInitializeNoMalloc(Tree* aTree, int(*compare)(void*, void*, int));
void TreeAddIndex(Tree* aTree, int(*compare)(void*, void*, int));

void* TreeAdd(Tree* aTree, void* content, size_t size);

void* TreeRemove(Tree* aTree, void* content);

void* TreeRemoveKey(Tree* aTree, void* key);
void* TreeRemoveKeyIndex(Tree* aTree, void* key, int index);

void* TreeRemoveNodeIndex(Tree* aTree, Node* aNode, int index);

void TreeFree(Tree* aTree);

Node* TreeFind(Tree* aTree, void* key);
Node* TreeFindIndex(Tree* aTree, void* key, int index);

Node* TreeNextElement(Tree* aTree, Node* curnode);

int TreeIntCompare(void* a, void* b, int);
int TreePtrCompare(void* a, void* b, int);
int TreeStringCompare(void* a, void* b, int);

#endif

