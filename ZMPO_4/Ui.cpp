#include "Ui.h"

CUi::CUi()
{
}

CUi::~CUi()
{
}

void CUi::vMenu()
{
	string sPostfixExpression;
	CList<int> cList;
	bool a = false;
	char c_menu = '1';

	cout << "MENU\n1. ADD ELEMENT\n2. DELETE ELEMENT\n3. FIND ELEMENT \n";
	cout << "4. FIND INDEX\n5. LIST LENGTH\n6. PRINT LIST\n7. CONCENTRATE\n0. EXIT\n";
	while (c_menu)
	{
		c_menu = _getch();
		switch (c_menu)
		{
		case EXIT:
			c_menu = 0;
			break;
		case ADD_ELEMENT:
			vAddElement(&cList);
			break;
		case DELETE_ELEMENT:
			vDeleteElement(&cList);
			break;
		case FIND_ELEMENT:
			vFindElement(cList);
			break;
		case FIND_INDEX:
			vFindIndex(cList);
			break;
		case LENGTH:
			cout << "LIST LENGTH: " << cList.GetLength() << endl;
			break;
		case PRINT_LIST:
			for (int i = 0;i < cList.GetLength(); i++)
				cout << i << ". " << cList.tGetElement(i, a) << endl;
			break;	
		case CONCENTRATE:
			cList.vConcentrate();
				break;
		default:
			//cout << "Wrong number!\n";
			break;
		}
	}
}

void CUi::vAddElement(CList<int> *cList)
{
	int i_value;
	int i_position;
	char c_menu = '0';
	cout << "Value: ";
	i_value = iGetInt();

	cout << "1 - Add First\n2 - Add Last\n3 - Add at any position\n";
	while (c_menu)
	{
		c_menu = _getch();
		switch (c_menu)
		{
		case FIRST:
			cList->vAddFirst(i_value);
			cout << "Operation successful!\n";
			c_menu = 0;
			break;
		case LAST:
			cList->vAddLast(i_value);
			cout << "Operation successful!\n";
			c_menu = 0;
			break;
		case CHOOSE:
			cout << "Position number: ";
			i_position = iGetInt();
			if(!cList->bAdd(i_value, i_position))
				cout<<"Wrong position!\n";
			else
				cout << "Operation successful!\n";
			c_menu = 0;
			break;
		}
	}
}

void CUi::vDeleteElement(CList<int> *cList)
{
	int i_position;
	char c_menu = '0';

	cout << "1 - Delete First\n2 - Delete Last\n3 - Delete at any position\n";
	while (c_menu)
	{
		c_menu = _getch();
		switch (c_menu)
		{
		case FIRST:
			cList->vDeleteFirst();
			cout << "Operation successful!\n";
			c_menu = 0;
			break;
		case LAST:
			cList->vDeleteLast();
			cout << "Operation successful!\n";
			c_menu = 0;
			break;
		case CHOOSE:
			cout << "Position number: ";
			i_position = iGetInt();
			if (!cList->bDelete(i_position))
				cout << "Wrong position!\n";
			else
				cout << "Operation successful!\n";
			c_menu = 0;
			break;
		}
	}
}

void CUi::vFindElement(CList<int> cList)
{
	bool b_temp = false;
	int i_element;
	cout << "Index: ";
	int i_index = iGetInt();
	i_element = cList.tGetElement(i_index, b_temp);
	if (b_temp)
		cout << "Element: " << i_element << endl;
	else
		cout << "Wrong position!\n";
}

void CUi::vFindIndex(CList<int> cList)
{
	int i_index;
	cout << "Element: ";
	int i_element = iGetInt();
	i_index = cList.iGetIndex(i_element);
	if (i_index!=-1)
		cout << "Index: " << i_index << endl;
	else
		cout << "Element doesn't exis!i\n";
}

int CUi::iGetInt()
{
	int iValue;
	while (!(cin >> iValue))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(0, '\n');
	cin.clear();
	return iValue;
}