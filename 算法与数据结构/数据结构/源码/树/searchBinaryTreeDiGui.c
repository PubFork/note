/*
 * =====================================================================================
 *
 *       Filename:  binaryTreeSearch.c
 *
 *    Description:  二叉搜索树的三种查找函数，递归实现
 *
 *        Version:  1.0
 *        Created:  2015/03/22 22时09分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wolf (), wolf430@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct tree{
	struct tree *left;
	struct tree *right;
	ElementType data;
}*BinTree;

typedef BinTree Posistion;

Posistion Find(ElementType x, BinTree BST){
	if(!BST) return NULL;
	if(x > BST->data)
		return Find(x,BST->right);
	else if(x < BST->data)
		return Find(x,BST->left);
	else
		return BST;
}

Posistion FindMin(BinTree BST){
	if(!BST) return NULL;
	else if(!BST->left)
		return BST;
	else
		return FindMin(BST->left);
}

Posistion FindMax(BinTree BST){
	if(!BST) return NULL;
	else if(!BST->right)
		return BST;
	else
		return FindMax(BST->right);
}

int main(void){
	struct tree A,B,C,D,E;
	Posistion pos;

	A.data = 10;
	A.left = &B;
	A.right = &C;

	B.data = 8;
	B.left = &D;
	B.right = NULL;

	C.data = 13;
	C.left = NULL;
	C.right = &E;
	
	D.data = 6;
	D.left = NULL;
	D.right = NULL;

	E.data = 18;
	E.left = NULL;
	E.right = NULL;

	pos = Find(6,&A);
	if(pos != NULL)
		printf("%d\n",pos->data);
	else
		printf("not find\n");
	return 0;
}
