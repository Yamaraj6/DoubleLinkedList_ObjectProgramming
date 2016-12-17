#pragma once
#include <iostream>

using namespace std;

template<typename T> class CElement
{
	template<typename T> friend class CList;
private:
	CElement *pc_next;
	CElement *pc_prev;
	T t_value;

public:
	CElement()
	{
		pc_next = NULL;
		pc_prev = NULL;
		t_value = NULL;
	};

	CElement(T tValue)
	{
		pc_next = NULL;
		pc_prev = NULL;
		t_value = tValue;
	};

	CElement(T tValue, CElement *Prev)
	{
		pc_next = NULL;
		pc_prev = Prev;
		t_value = tValue;
	};

	CElement(T tValue, CElement *Prev, CElement *Next)
	{
		pc_next = Next;
		pc_prev = Prev;
		t_value = tValue;
	};

	~CElement() {};
};



template<typename T> class CList
{
private:
	CElement<T> *pc_root;
	int i_length;

public:
	CList() 
	{
		pc_root = NULL;
		i_length = 0;
	};

	CList(T tValue)
	{
		pc_root = new CElement<T>(tValue);
		i_length = 1;
	};

	~CList() 
	{
		int ilength = i_length;
		for (int i = 0;i < ilength; i++)
			vDeleteFirst();
	};

	void CList::vAddFirst(T tValue)
	{
		if (pc_root != NULL)
		{
			CElement<T> &pcNext = *pc_root;
			pc_root = new CElement<T>(tValue);
			pc_root->pc_next = &pcNext;
			pc_root->pc_next->pc_prev = pc_root;
		}
		else
			pc_root = new CElement<T>(tValue);
		i_length++;
	};

	void CList::vAddLast(T tValue)
	{
		if (pc_root != NULL)
		{
			while(pc_root->pc_next!=NULL)
				pc_root = pc_root->pc_next;
			pc_root->pc_next = new CElement<T>(tValue);
			pc_root->pc_next->pc_prev = pc_root;

			while (pc_root->pc_prev != NULL)
				pc_root = pc_root->pc_prev;
		}
		else
			pc_root = new CElement<T>(tValue);
		i_length++;
	};

	bool CList::bAdd(T tValue, int iIndex)
	{
		bool b_temp = false;
		if (iIndex < i_length)
		{
			for (int i = 0;iIndex != i;i++)
				pc_root = pc_root->pc_next;
			CElement<T> &pcTemp = *pc_root;
			pc_root = new CElement<T>(tValue, pcTemp.pc_prev, &pcTemp);
			if (pcTemp.pc_prev != NULL)
				pcTemp.pc_prev->pc_next = pc_root;
			pcTemp.pc_prev = pc_root;
			while (pc_root->pc_prev != NULL)
				pc_root = pc_root->pc_prev;
			i_length++;
			b_temp = true;
		}
		else if (iIndex == i_length) 
		{
			vAddLast(tValue);
			b_temp = true;
		}
		return b_temp;
	};

	T CList::tGetElement(int iIndex, bool &bOut)
	{
		T t_temp = NULL;
		bOut = false;
		if (iIndex < i_length)
		{
			for (int i = 0;iIndex != i;i++)
				pc_root = pc_root->pc_next;
			t_temp = pc_root->t_value;
			while (pc_root->pc_prev != NULL)
				pc_root = pc_root->pc_prev;
			bOut = true;
		}
		return t_temp;
	};

	int CList::iGetIndex(T tValue)
	{
		int i_temp = -1;
		for (int i = 0;i < i_length && i_temp == -1;i++)
		{
			if (pc_root->t_value == tValue)
				i_temp = i;
			if (pc_root->pc_next != NULL)
				pc_root = pc_root->pc_next;
			else i = i_length;
		}
		while (pc_root->pc_prev != NULL)
			pc_root = pc_root->pc_prev;

		return i_temp;
	};

	void CList::vDeleteFirst()
	{
		if (pc_root != NULL)
		{
			if (pc_root->pc_next != NULL)
			{
				CElement<T> &pcNext = *pc_root->pc_next;
				delete pc_root;
				pc_root = &pcNext;
				pc_root->pc_prev = NULL;
			}
			else
			{
				delete pc_root;
				pc_root = NULL;
			}
			i_length--;
		}
	};

	void CList::vDeleteLast()
	{
		if (pc_root != NULL)
		{
			if (pc_root->pc_next != NULL)
			{
				while (pc_root->pc_next->pc_next != NULL)
					pc_root = pc_root->pc_next;
				delete pc_root->pc_next;
				pc_root->pc_next = NULL;
				while (pc_root->pc_prev != NULL)
					pc_root = pc_root->pc_prev;
			}
			else
			{
				delete pc_root;
				pc_root = NULL;
			}
			i_length--;
		}
	};

	bool CList::bDelete(int iIndex)
	{
		bool b_temp = false;
		if (iIndex < i_length)
		{
			if (iIndex == 0)
				vDeleteFirst();
			else if (iIndex == (i_length - 1))
				vDeleteLast();
			else
			{
				for (int i = 1;iIndex != i;i++)
					pc_root = pc_root->pc_next;

				CElement<T> &pcNext = *pc_root->pc_next;
				pc_root->pc_next = pc_root->pc_next->pc_next;
				if (pc_root->pc_next != NULL)
					pc_root->pc_next->pc_prev = pc_root;
				while (pc_root->pc_prev != NULL)
					pc_root = pc_root->pc_prev;
				delete &pcNext;
				i_length--;
			}
			b_temp = true;
		}
		return b_temp;
	};

	int CList::GetLength() { return i_length; };

	void CList::vConcentrate()
	{
		if (typeid(T) == typeid(int))
		{
			if (pc_root != NULL)
			{
				while (pc_root->pc_next != NULL)
				{
					if (pc_root->t_value == pc_root->pc_next->t_value)
					{
						CElement<T> &t_temp = *pc_root->pc_next;
						pc_root->pc_next = pc_root->pc_next->pc_next;
						pc_root->pc_next->pc_prev = pc_root;
						delete &t_temp;
						i_length--;
					}
					else
						pc_root = pc_root->pc_next;
				}
			}
			while (pc_root->pc_prev != NULL)
				pc_root = pc_root->pc_prev;
		}
	}
};