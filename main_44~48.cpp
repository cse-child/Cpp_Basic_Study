// ���Ʈ�� ���Ӿ�ī���� - 44ȭ. �����迭(2) ����

#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

void BubbleSort(int* _iData, int _iCount) {
	// �����Ͱ� 1�� ������ ���� �������� ����
	if (_iCount <= 1) {
		return;
	}
	// �������� ����
	while (true) {
		bool bFinish = true;

		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i) {
			if (_iData[i] > _iData[i + 1]) {
				int iTemp = _iData[i];
				_iData[i] = _iData[i + 1];
				_iData[i + 1] = iTemp;
				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}
}

void Test() {

}

int main()
{
	// �Լ� ������ ���� ���!
	// �Լ��� �ּҸ� �ҷ����¹�
	// ��ȯ Ÿ���� void�̰� �Ű������� ����(void) Test �Լ� ȣ��
	void(*pFunc)(void) = nullptr; 
	pFunc = Test;
	pFunc(); // Test �Լ��� ȣ���� �Ͱ� ���� �ǹ�



	int iArr[10] = { 87,644,21,55,879,654,55,131, };
	BubbleSort(iArr, 10);




	tArr s1 = {};

	InitArr(&s1);

	// ����(����) ����
	srand(time(nullptr)); // �ð����� �׻� �ٸ��⶧���� ���� ������ �����

	for (int i = 0; i < 10; ++i)
	{
		// PushBack(&s1, i);
		PushBack(&s1, rand() % 100+1); // 1~100 ����
	}

	printf("���� ��\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// Sort(&s1); // �Լ� ������ ���� ��
	
	Sort(&s1, &BubbleSort); // �Լ� ������: �Ű������� �Լ��� ����
	// BubbleSort�� �ᵵ�ǰ� &Bubblesort�� �ᵵ��
	// �Լ� ������ ����ϴ� ���:
	// 1. ���� ���� ����� �ٸ������ ������ ���� ��쿡 ����Ѵ�.
	// �ٸ������ �� ����� �����Ű��, �ڽ��� �Լ��� �� �����ų��
	// ���� �ٸ������ �����ų ����� �����ؼ� �̸� �������� �� ������
	// CALLBACK���� ����� ����� ���°��̴�.
	// ���� ���� ����� �Լ� �����ͷ� ������ָ� �ٸ������ ȣ���ؼ� ����غ� �� �ֵ����Ѵ�.

	// 2. �бⰡ �Ź� �˻�Ǵ� ��쿡 ����Ѵ�.
	// if � ���¸� ~~�Լ� ȣ���ؾ� �ϰ�, else if � ���¸� ~~�Լ� ȣ���ؾ��ϴ� ���
	// if ���¸� �� �Լ��� ����Ű���� �����س����� ��� �� �Լ� �����͸� ȣ���ؼ� ��� ����

	printf("\n���� ��\n");
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

// ���߿� �Լ������� �̿��ؼ� ������ �������� ȣ�� + ���ı��� �غ���