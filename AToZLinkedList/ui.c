#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "linkedList.h"
#include "test.h"




	

void NewNodeInput(void)
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

	USERDATA* newUser = malloc(sizeof(USERDATA));
	
	newUser->age = age;
	strcpy_s(newUser->name, sizeof(newUser->name), name);
	strcpy_s(newUser->phone, sizeof(newUser->phone), phone);

	AddNewNode(true, name, newUser, sizeof(newUser), 0);
}

void PrintList(void)
{
	MYNODE* pTmp = &g_HeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %s [%p]\n", pTmp, pTmp->pszKey, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	_getch();
}
MENU PrintMenu(void)
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