#include <stdio.h>
// ���Ʈ�� ���Ӿ�ī���� - 13ȭ. �Լ�(1) / �ݺ��� ����


int Add(int a, int b) {
	return a + b;
}

// �Լ�
int main() {
	int iData = Add(100, 200);

	// �ݺ���
	//for (/*�ݺ��� �ʱ�ȭ*/;/*�ݺ��� ���� üũ*/;/*�ݺ��� ����*/) {

	//}

	// i = 0, 1, 2, 3
	for (int i = 0; i < 4; ++i) {
		printf("Output Test\n");

		if (i % 2 == 1) {
			continue;
		}
	}

	//while (/*���� üũ*/) {

	//}

	/*int i = 0;
	while (i < 2) {
		printf("Output Test2\n");
		++i;
	}*/

	int i = 0;
	int i2 = 2;

	// �ܼ�
	// printf
	printf("abcdef %d \n", 10);

	for (int i = 0; i < 10; ++i) {
		printf("Output i : %d\n", i);
	}

	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);

	return 0;
}

/* ����Ű */
// ������ ���� �ּ�		: Ctrl + k, c
// ������ ���� �ּ� ����	: Ctrl + k, u
// ���ϴ� ������ �巡��	: Alt + Drag

// �����
// ����� ����			: F5
// ���� �ߴ������� �ڵ� ����

// �ߴ��� ���� �� ����	: F9
// ����� ��, ���� ����	: F10
// ����� ��, ���� ����(�Լ� ����)	: F11
// ����� ��, ����� �����ϱ�		: Shift + F5