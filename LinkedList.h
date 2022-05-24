// 46ȭ. ����Ʈ(1)�� �̾ 49ȭ. ����Ʈ(2)
#pragma once

// List���� Node ������ �ʼ�
typedef struct _tagNode
{
	int iData;

	// �ڱ�� ���� ����� ����Ű�� ��������� �ּҸ� �˾ƾ� ��
	struct _tagNode* pNextNode;
}tNode;

// int�� ������ ����Ʈ�� ����
typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
	// int iMaxCount; // List�� ��ü ũ�� ������ �ʿ�X
}tLinkedList;

// ����Ʈ �ʱ�ȭ �Լ�
void InitList(tLinkedList* _pList);

// ������ ����Ʈ ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData);

// ������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);