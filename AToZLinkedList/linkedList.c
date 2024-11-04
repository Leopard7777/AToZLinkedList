#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedList.h"

MYNODE g_HeadNode = { 0 };
MYNODE g_TailNode = { 0 };
static unsigned int g_listCount = 0;

void InitList()
{
	ReleaseList();
	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
}

bool IsEmpty(void)
{
	if (g_HeadNode.pNext == &g_TailNode && g_TailNode.pPrev == &g_HeadNode)
		return true;
	else
		return false;
}

void AddNewNode(int age, char* pszName, char* pszPhone)
{
	MYNODE* pTmp = &g_TailNode;
	MYNODE* pNewNode = (MYNODE*)malloc(sizeof(MYNODE));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->bNew = true;
		
	int lenOfKey = (int)strlen(pszName);
	pNewNode->pszKey = malloc(lenOfKey + 1);
	strcpy_s(pNewNode->pszKey, lenOfKey + 1, pszName); // Key

	if (pNewNode->pszKey != NULL && lenOfKey > 0)
	{
		USERDATA* pNewData = malloc(sizeof(USERDATA));
		pNewData->age = 10;
		strcpy_s(pNewData->name, sizeof(pNewData->name), pszName);
		strcpy_s(pNewData->phone, sizeof(pNewData->phone), pszPhone);
		pNewData->isDeleted = false;

		pNewNode->pDataCache = pNewData;
		pNewNode->sizeOfData = sizeof(pNewData);
			
	}
	pNewNode->sizeOfData = sizeof(USERDATA);
	pNewNode->offset = 0;

	pNewNode->pPrev = pTmp->pPrev;
	pNewNode->pNext = pTmp;

	pTmp->pPrev->pNext = pNewNode;
	pTmp->pPrev = pNewNode;



	return;	
}

void ReleaseList(void)
{
	if (IsEmpty() == true)
		return;

	MYNODE* pTmp = g_HeadNode.pNext;
	MYNODE* pDelete;
	
	while (pTmp != NULL && pTmp != &g_TailNode)
	{
		pDelete = pTmp;
		printf("remove : %s\n", pTmp->pszKey);
		pTmp = pTmp->pNext;

		free(pDelete->pszKey);
		if (pDelete->pDataCache != NULL)
			free(pDelete->pDataCache);
		free(pDelete);
	}

	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
}