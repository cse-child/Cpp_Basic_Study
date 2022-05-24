// 46화. 리스트(1)에 이어서 49화. 리스트(2)

#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList * _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList * _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr; // 리스트 가장 마지막에 넣기때문에 nextNode는 null

	// 추가한 데이터가 처음인지 아닌지
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else 
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움
		
		tNode* pCurFinalNode = _pList->pHeadNode;
		
		// 마지막 노드를 찾기 위해 nextNode가 nullptr인지 찾기ㅋ
		while (pCurFinalNode->pNextNode) {
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}
	++_pList->iCount;
}

void PushFront(tLinkedList * _pList, int _iData)
{
	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	
	// 리스트의 헤드노드 포인터를 갱신한다.
	_pList->pHeadNode = pNode;

	// 데이터 카운트 증가
	++_pList->iCount;
}

// 재귀함수 사용해서 동적 메모리 해제하기
// 다만 재귀함수는 함수 호출이 너무 많아서 효율이 좋지 않다.
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
	// 재귀함수 ver 메모리 해제
	// Release(_pList->pHeadNode);

	// 재귀함수 안쓴 ver 메모리 해제
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode) 
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
