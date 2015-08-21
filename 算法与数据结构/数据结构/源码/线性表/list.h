/*
 * =====================================================================================
 *
 *       Filename:  link.h
 *
 *    Description:  线性表头文件
 *
 *        Version:  1.0
 *        Created:  2015/03/30 22时20分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wolf (), wolf430@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

typedef int ElemType;

typedef struct{
	ElemType data;
	struct List *next;
}List,*qList;

void Union(List &La, List Lb);

void MergeList(List La, List Lb, List &Lc);
