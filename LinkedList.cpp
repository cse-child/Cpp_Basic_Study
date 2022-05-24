// 46ȭ. ����Ʈ(1)�� �̾ 49ȭ. ����Ʈ(2)

#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList * _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList * _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr; // ����Ʈ ���� �������� �ֱ⶧���� nextNode�� null

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else 
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��
		
		tNode* pCurFinalNode = _pList->pHeadNode;
		
		// ������ ��带 ã�� ���� nextNode�� nullptr���� ã�⤻
		while (pCurFinalNode->pNextNode) {
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}
	++_pList->iCount;
}

void PushFront(tLinkedList * _pList, int _iData)
{
	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	
	// ����Ʈ�� ����� �����͸� �����Ѵ�.
	_pList->pHeadNode = pNode;

	// ������ ī��Ʈ ����
	++_pList->iCount;
}

// ����Լ� ����ؼ� ���� �޸� �����ϱ�
// �ٸ� ����Լ��� �Լ� ȣ���� �ʹ� ���Ƽ� ȿ���� ���� �ʴ�.
void Release(tNode* _pNode) 
{
	if (nullptr == _pNode) {
		return;
	}
	Release(_pNode->pNextNode);

	free(_pNode);
}

void ReleaseList(tLinkedList * _pList)
{
	// ����Լ� ver �޸� ����
	// Release(_pList->pHeadNode);

	// ����Լ� �Ⱦ� ver �޸� ����
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode) 
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
