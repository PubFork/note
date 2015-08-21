/*
 * =====================================================================================
 *
 *       Filename:  searchBinaryTreeXunHuan.c
 *
 *    Description:  搜索二叉树的三种查询函数，用循环实现
 *
 *        Version:  1.0
 *        Created:  2015/03/28 22时43分25秒
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

Posistion IterFind(ElementType x, BinTree BST){
	if(!BST) return NULL;
	while(BST){
		if(BST->data > x)
			BST = BST->left;
		else if(BST->data < x)
			BST = BST->right;
		else
			return BST;
	}
	return NULL;
}

Posistion IterFindMin(BinTree BST){
	if(!BST) return NULL;
	while(BST->left)
		BST = BST->left;
	return BST;
}

Posistion IterFindMax(BinTree BST){
	if(!BST) return NULL;
	while(BST->right)
		BST = BST->right;
	return BST;
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

	pos = IterFindMax(&A);
	if(pos != NULL)
		printf("%d\n",pos->data);
	else
		printf("not find\n");
	return 0;
}
