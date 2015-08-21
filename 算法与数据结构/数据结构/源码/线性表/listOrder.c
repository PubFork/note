/*
 * =====================================================================================
 *
 *       Filename:  listOrder.c
 *
 *    Description:  2.2 线性表的顺序表实现
 *
 *        Version:  1.0
 *        Created:  2015/03/30 22时41分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wolf (), wolf430@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define LIST_INIT_SIZE 10		//线性表存储空间的初始分配量
#define LIST_INCREMENT 2

typedef int ElemType;

struct SqList{
	ElemType *elem;			//存储空间基地址
	int		length;
	int		listsize;
};
