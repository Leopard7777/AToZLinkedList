#include "ui.h"
#include "linkedList.h"
#include "test.h"


void NewNodeInput()
{
	int age;
	char name[32];
	char phone[32];
	printf("age: ");
	scanf_s("%d%*c", &age);
	printf("name: ");
	scanf_s("%s%*c", name, (unsigned)sizeof(name));
	printf("phone: ");
	scanf_s("%s%*c", phone, (unsigned)sizeof(phone));

	AddNewNode(age, name, phone);
}

void PrintList()
{
	MYNODE* pTmp = &g_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s [%p]\n", pTmp, pTmp->pszKey, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	_getch();
}
MENU PrintMenu()
{
	system("cls");
	MENU input;
	puts("[1] new  [2] search  [3] edit  [4] remove  [5] print  [0] exit");
	scanf_s("%d%*c", &input);

	return input;
}


void RunEventLoop()
{	
	MENU input;
	while ((input = PrintMenu()) != NULL)
	{
		switch (input) {
		case NEW:
			NewNodeInput();
			break;
		case SEARCH:
			break;
		case EDIT:
			break;
		case REMOVE:
			break;
		case PRINT:
			PrintList();
			break;
		case EXIT:
			return;
		default:
			return;
		}
	}
}