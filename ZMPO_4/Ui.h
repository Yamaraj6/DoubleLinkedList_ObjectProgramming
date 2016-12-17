#pragma once
#include "List.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
#define EXIT '0'
#define ADD_ELEMENT '1'
#define DELETE_ELEMENT '2'
#define FIND_ELEMENT '3'
#define FIND_INDEX '4'
#define LENGTH '5'
#define PRINT_LIST '6'
#define CONCENTRATE '7'

#define FIRST '1'
#define LAST '2'
#define CHOOSE '3'

class CUi
{
public:
	CUi();
	~CUi();
	void CUi::vMenu();

private:
	void CUi::vAddElement(CList<int> *cList);
	void CUi::vDeleteElement(CList<int> *cList);
	void CUi::vFindElement(CList<int> cList);
	void CUi::vFindIndex(CList<int> cList);
	int CUi::iGetInt();
};