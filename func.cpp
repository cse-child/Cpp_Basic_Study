#include "func.h"
#include "common.h"
// #include : ����� ������ �����ϴ� ��ó����
#include <stdio.h>

int g_iExtern = 0; // �ܺ� ���� �ʱ�ȭ

int Add(int a, int b) {
	printf("%d", g_iExtern);
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}