// 46화. 리스트(1)에 이어서 49화. 리스트(2)
#pragma once

// List에는 Node 개념이 필수
typedef struct _tagNode
{
	int iData;

	// 자기와 같은 멤버가 가르키는 다음노드의 주소를 알아야 함
	struct _tagNode* pNextNode;
}tNode;

// int형 연결형 리스트를 구현
typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
	// int iMaxCount; // List는 전체 크기 변수가 필요X
}tLinkedList;

// 리스트 초기화 함수
void InitList(tLinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);