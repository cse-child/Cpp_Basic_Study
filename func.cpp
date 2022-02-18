#include "func.h"
#include "common.h"
// #include : 명시한 파일을 복붙하는 전처리기
#include <stdio.h>

int g_iExtern = 0; // 외부 변수 초기화

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