#include <stdlib.h>

typedef int BType;

typedef struct node_b {
	BType data;
	struct node_b* leftchild;
	struct node_b* rightchild;
}bnode_t;

bnode_t* getBinaryNode(BType key) {
	bnode_t* node;
	node = (bnode_t*)malloc(sizeof(bnode_t));
	node->leftchild = NULL;
	node->rightchild = NULL;
	node->data = key;
	return (node);
}