#pragma once


typedef struct _tabArr {
	int* pInt; // ���� �迭 ��ü
	int iCount; // �迭�� �ε���?
	int iMaxCount; // ���� �迭�� ũ��
}tArr;

void Linked_InitArr(tArr* _pArr);

void Linked_PushBack(tArr* _pArr, int _iData);

void Linked_ReleaseArr(tArr* _pArr);