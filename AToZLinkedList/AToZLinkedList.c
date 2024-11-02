#include <stdio.h>
#include "linkedList.h"
#include "ui.h"


int main(void)
{
	InitList();
	RunEventLoop();
	ReleaseList();
}