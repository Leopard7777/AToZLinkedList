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

void AddNewNode(bool boolNew, char* pszKey, void* pDataCache, 
	unsigned int sizeOfData, unsigned int intOffset)
{
	MYNODE* pTmp = &g_TailNode;
	MYNODE* pNewNode = (MYNODE*)malloc(sizeof(MYNODE));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->bNew = boolNew;
		
	int lenOfKey = (int)strlen(pszKey);  // Key
	pNewNode->pszKey = malloc(lenOfKey + 1);
	if (pNewNode->pszKey == NULL)
		return 0;
	strcpy_s(pNewNode->pszKey, lenOfKey + 1, pszKey);

	if (pNewNode->pszKey != NULL && lenOfKey > 0) //datacache & sizeofdata
	{
		USERDATA* pNewData = malloc(sizeof(USERDATA));
		pNewNode->pDataCache = pNewData;
		pNewNode->sizeOfData = sizeof(pNewData);
			
	}
	pNewNode->offset = intOffset;

	pNewNode->pPrev = pTmp->pPrev;
	pNewNode->pNext = pTmp;

	pTmp->pPrev->pNext = pNewNode;
	pTmp->pPrev = pNewNode;



	return;	
}

void LoadListFromFile(void)
{
	FILE* fp = NULL;
	fopen_s(&fp, "listData.dat", "rb");
	if (fp == NULL)
		return 0;

	unsigned int offset = 0;
	USERDATA user = { 0 };
	while (fread(&user, sizeof(USERDATA), 1, fp) > 0)
	{
		AddNewNode(false, user.name, &user, sizeof(user), offset);
		++offset;
	}

	fclose(fp);
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