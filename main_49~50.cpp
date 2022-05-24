// ���Ʈ�� ���Ӿ�ī���� - 49ȭ. ����Ʈ(2) ����

#include <iostream>

#include "LinkedList.h"

int main() {

	tLinkedList list = {};

	InitList(&list);

	PushBack(&list, 10);
	PushBack(&list, 20);
	PushBack(&list, 30);
	
	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i) {
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}

// 49ȭ. ����Ʈ(2) ����: PushBack���� PushFront �Լ��� �����϶�

// 50ȭ. ����Ʈ(3)
// ����Ʈ�� �����迭�� ��

// ����Ʈ ����
// ����Ʈ�� �����Ͱ� �ƹ��� ���Ƶ� �߰��� ���ο� �����͸� �����ϰų� ������ ��
// (Head, Tail)����� �ּҸ� �����ϸ� �Ǳ� ������ ����� �ʴ�.

// ����Ʈ�� ������� �ʰ� �����迭�� PushFront �Լ��� �����Ѵٸ�
// ���ο� �����Ͱ� ����/���� �� ������
// ���������� �ϳ��� �ڸ��� �Űܾ� �Ѵ�. (�ð� ���⵵ O(n))

// ����Ʈ ����
// ����Ʈ�� �־��� ���� �����Ͱ� n�� ���� �� ���� �������� ��ġ��
// n��° ��忡 �����ϴ� ����̴�. (�ݸ� ����ǥ�� �˰� �ִ� ��쿣 ����� ã�� ��찡 ���� �־�)
// �̷��� ��� �ð� ���⵵�� O(N)

// ���� ���������� C��� ��Ÿ�Ϸ� �ڷᱸ���� ����������
// ���� �������ʹ� C++��� ��Ÿ�Ϸ� Ŭ���� ���κ��� ����