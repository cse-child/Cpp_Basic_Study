// ���Ʈ�� ���Ӿ�ī���� 47ȭ. ����Ǯ��

#include <iostream>

#include "Linked_Arr.h"

int main(void) {
	tArr s1 = {};
	int arr[] = { 5,10,2,7,3,1,9,4,8,6 };

	Linked_InitArr(&s1);

	for (int i = 0; i < 10; ++i) { // �����迭�� 0~9�� ���ڸ� �־��
		Linked_PushBack(&s1, arr[i]);
	}

	printf("�������� �� �迭: ");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d  ", s1.pInt[i]);
	}

	for (int i = 1; i <= s1.iCount; ++i) {
		for (int j = 0; j < s1.iCount-i; ++j) {
			if (s1.pInt[j] > s1.pInt[j+1]) {
				int temp = s1.pInt[j];
				s1.pInt[j] = s1.pInt[j + 1];
				s1.pInt[j + 1] = temp;
			}
		}
	}

	printf("\n�������� �� �迭: ");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d  ", s1.pInt[i]);
	}

	Linked_ReleaseArr(&s1);

	return 0;
}

// ���߿� �߰������� ��������, ��������, �պ�(����)����, 
// ���(��) ����, �� ����(���� ����Ʈ��)�� �����ϱ�.