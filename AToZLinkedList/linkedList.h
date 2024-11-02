#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	bool isDeleted;
}USERDATA;

typedef struct MYNODE {
	bool bNew;
	char* pszKey;
	void* pDataCache;
	unsigned int sizeOfData;
	unsigned int offset;

	struct MYNODE* pPrev;
	struct MYNODE* pNext;
}MYNODE;

extern MYNODE g_HeadNode;
extern MYNODE g_TailNode;

void InitList();
void AddNewNode(USERDATA* pUser);
void ReleaseList(void);