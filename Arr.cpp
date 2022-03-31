#include "Arr.h"

#include <iostream>

// �迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr) 
{
	_pArr->pInt = (int*)malloc(sizeof(int)*2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// ������ �߰� �Լ�
void PushBack(tArr * _pArr, int _iData)
{
	// �� ������ �Ҵ��� ������ �� ��
	if (_pArr->iMaxCount <= _pArr->iCount) 
	{
		// ���Ҵ�
		Reallocate(_pArr);
	}

	// ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData;
}

// �迭�� ���� �߰� Ȯ�� �Լ� (���Ҵ�)
void Reallocate(tArr * _pArr)
{
	// 1. 2�� �� ū ������ �����Ҵ��Ѵ�.
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));
	// ���ο� �޸� ������ �������� pNew�� ���� ������ѵд�.
	// pInt�� �ٷ� ���Ҵ��� �ϸ� pInt�� ���� �Ҵ�Ǿ��ִ� �ּҴ�
	// ���̻� ������ �ʰ� ������� �ȴ�.

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. ���� ������ �޸� ����
	free(_pArr->pInt);

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	_pArr->pInt = pNew;

	// 5. MaxCount ������ ����
	_pArr->iMaxCount *= 2;
}

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr * _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}
