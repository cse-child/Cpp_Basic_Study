// ���Ʈ�� ���Ӿ�ī���� - 28ȭ. ������ �迭����

#include <stdlib.h>
#include <stdio.h>

int main() {
	// ������ ����
	// �ڷ��� ������
	int* pInt = nullptr;

	// �ּҸ� ����
	
	char* pChar = nullptr;
	short* pShort = nullptr;

	// �������� ũ���? 8 ����Ʈ �̴�.
	// ���� ���������ϴ� �ü���� ���� 32bit ����̸� 4 Byte�̰�
	// 64bit �ü���̸� 8 Byte �̴�.

	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i;
	// pInt�� �ּҰ� 100�̶�� i�� int��(4Byte)�̹Ƿ� 
	// 101, 102, 103, 104������ �����




	return 0;
}