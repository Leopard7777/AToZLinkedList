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

void AddNewNode(USERDATA* pUser)
{
	MYNODE* pTmp = &g_TailNode;
	MYNODE* pNewData = (MYNODE*)malloc(sizeof(MYNODE));
	if (pNewData == NULL)
		return NULL;
	pNewData->bNew = true;
		
	int lenOfKey = (int)strlen(pUser->name);
	pNewData->pszKey = malloc(lenOfKey + 1);
	strcpy_s(pNewData->pszKey, lenOfKey + 1, pUser->name); // Key

	if (pUser != NULL && sizeof(pUser) > 0)
	{
		void* pNewDataCache = malloc(sizeof(USERDATA));
		memcpy_s(pNewDataCache, sizeof(USERDATA), pUser, sizeof(USERDATA)); // DataCahce
		pNewData->pDataCache = pNewDataCache;
		pNewData->sizeOfData = sizeof(pNewDataCache);
			
	}
	pNewData->sizeOfData = sizeof(USERDATA);
	pNewData->offset = 0;

	pNewData->pPrev = pTmp->pPrev;
	pNewData->pNext = pTmp;

	pTmp->pPrev->pNext = pNewData;
	pTmp->pPrev = pNewData;



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