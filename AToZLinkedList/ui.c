#include "ui.h"
#include "linkedList.h"
#include "test.h"


void printList()
{
	MYNODE* pTmp = &g_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s [%p]\n", pTmp, pTmp->pszKey, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}
MENU printMenu()
{
	MENU input;
	puts("[1] new  [2] search  [3] edit  [4] remove  [5] print  [0] exit");
	scanf_s("%d%*c", &input);

	return input;
}


void RunEventLoop()
{	
	MENU input;
	while ((input = printMenu()) != NULL)
	{
		switch (input) {
		case NEW:
			testStep01();
			break;
		case SEARCH:
			break;
		case EDIT:
			break;
		case REMOVE:
			break;
		case PRINT:
			printList();
			break;
		case EXIT:
			return;
		default:
			return;
		}
	}
}