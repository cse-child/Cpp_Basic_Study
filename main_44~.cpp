// ���Ʈ�� ���Ӿ�ī���� - 44ȭ. �����迭(2) ����

#include <iostream>

#include "Arr.h"
#include "LinkedList.h"



int main()
{
	tArr s1 = {};

	InitArr(&s1);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}

	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	/* ���� 46ȭ. ����Ʈ(1) */
	// ������ ����Ʈ
	// LinkedList.h, LinkedList.cpp ���� ����
	// �����͸� �ϳ� �߰��Ҷ����� ���ο� �޸� ������ �Ҵ��ؼ� �����Ѵ�.

	return 0;
}

// ����
// 1. �����迭
// ������ ���� �����ϰ� ������ ��

// 2. �����迭 �ȿ� ���� ������ ����
// -���� ����