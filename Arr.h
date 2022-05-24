#pragma once

// int�� �����迭
typedef struct _tabArr
{
	// �ʼ� ��� 3����
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// tArr s;�� ������ �� s ��ü�� �ʱ�ȭ�� �Լ� (�迭 �ʱ�ȭ)
// �Լ� ���� ����Ű : Ctrl + '+' + '.'
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �迭�� ���� �߰� Ȯ�� �Լ�
// void Reallocate(tArr* _pArr);
// �ش� �Լ��� main�Լ����� ���� ȣ������ ���ϵ��� ������ �� �ִ�.
// ������Ͽ��� �ش� �Լ������� ������ Arr.cpp���� ���ο��� ��ü������ ȣ���Ͽ�
// ���α׷��� �����۵� �� �� �ִ�.

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);

// ������ ���� �Լ�
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));
// �Լ� �����͸� �ι�° �Ű������� ����