#include "linkedList.h"
#include "ui.h"

void testStep01()
{
	USERDATA hoon = { 10, "Hoon", "1111", false};
	USERDATA kim = { 20, "kim", "2222", false};
	USERDATA jang = { 30, "jang", "3333", false};
	AddNewNode(&hoon);
	AddNewNode(&kim);
	AddNewNode(&jang);
}