#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedList.h"

MYNODE g_HeadNode = { 0 };
MYNODE g_TailNode = { 0 };

void InitList()
{

	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
}

void AddNewNode(USERDATA* pUser)
{
	MYNODE* pTmp = &g_TailNode;
	if (pTmp != NULL) {
		MYNODE* pNewData = (MYNODE*)malloc(sizeof(MYNODE));
		pNewData->bNew = true;
		
		int lenOfKey = (int)strlen(pUser->name);
		pNewData->pszKey = malloc(sizeof(lenOfKey + 1));
		strcpy_s(pNewData->pszKey, lenOfKey + 1, pUser->name); // Key

		if (pUser != NULL && sizeof(pUser) > 0)
		{
			void* newData = malloc(sizeof(pUser));
			memcpy_s(newData, sizeof(newData), pUser, sizeof(pUser));
			pNewData->pDataCache = newData;
			pNewData->sizeOfData = sizeof(newData);
			
		}
		pNewData->sizeOfData = sizeof(MYNODE);
		pNewData->offset = 0;

		pNewData->pPrev = pTmp->pPrev;
		pNewData->pNext = pTmp;

		pTmp->pPrev->pNext = pNewData;
		pTmp->pPrev = pNewData;



		return;
	}
	else
	{
		puts("error: where's tailnode?");
		return;
	}	
}

releaseList()
{

}