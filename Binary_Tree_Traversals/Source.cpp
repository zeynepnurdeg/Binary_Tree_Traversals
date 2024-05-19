#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binaryList.h"

int menu() {
	printf("MENU\n");
	printf("1. Insert a number to tree\n");
	printf("2. Display tree\n");
	printf("3. Search min value of tree\n");
	printf("4. EXIT\n");

	int choice;
	do {
		printf("Enter choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);

	return (choice);
}

bnode_t* insertRec(bnode_t* root, BType key) {
	if (root == NULL)
		return (getBinaryNode(key));
	else if (root->data < key)
		root->rightchild = insertRec(root->rightchild, key);
	else
		root->leftchild = insertRec(root->leftchild, key);
	return (root);
}

void preOrderDisplay(bnode_t* root) {
	if (root != NULL) {
		printf("%d -> ", root->data);
		preOrderDisplay(root->leftchild);
		preOrderDisplay(root->rightchild);
	}
}

void inOrderDisplay(bnode_t* root) {
	if (root != NULL) {
		inOrderDisplay(root->leftchild);
		printf("%d -> ", root->data);
		inOrderDisplay(root->rightchild);
	}
}

void postOrderDisplay(bnode_t* root) {
	if (root != NULL) {
		postOrderDisplay(root->leftchild);
		postOrderDisplay(root->rightchild);
		printf("%d -> ", root->data);
	}
}

bnode_t* SearchMin(bnode_t* root) {
	bnode_t* tp;
	tp = root;
	while (tp->leftchild != NULL)
		tp = tp->leftchild;
	return (tp);
}

int main(void)
{
	int choice, insertNum, treeNum, minNum;

	bnode_t* root = NULL;
	bnode_t* temp;
	
	do {
		choice = menu();

		switch (choice)
		{
		case 1:
			printf("Enter num to insert: ");
			scanf("%d", &insertNum);
			root = insertRec(root, insertNum);
			printf("\n%d has been inserted\n\n", insertNum);
			break;

		case 2:
			do {
				printf("\nEnter type of display (pre:1, in:2, post:3): ");
				scanf("%d", &treeNum);
			} while (treeNum < 1 || treeNum > 3);
			
			switch (treeNum)
			{
			case 1:
				preOrderDisplay(root);	break;
			case 2:
				inOrderDisplay(root);	break;
			case 3:
				postOrderDisplay(root);	break;
			}

			break;

		case 3:
			temp = SearchMin(root);
			if (temp != NULL)
				printf("\nMin number is: %d\n\n", root->data);
			else
				printf("Insert a number to tree\n\n");
			break;
		}

		printf("\n");
	} while (choice != 4);

	return 0;
}