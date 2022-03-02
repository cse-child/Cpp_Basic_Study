// 어소트락 게임아카데미 - 28화. 포인터 배열부터

#include <stdlib.h>
#include <stdio.h>

int main() {
	// 포인터 변수
	// 자료형 변수명
	int* pInt = nullptr;

	// 주소를 저장
	
	char* pChar = nullptr;
	short* pShort = nullptr;

	// 포인터의 크기는? 8 바이트 이다.
	// 내가 목적으로하는 운영체제에 따라 32bit 기반이면 4 Byte이고
	// 64bit 운영체제이면 8 Byte 이다.

	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i;
	// pInt의 주소가 100이라면 i는 int형(4Byte)이므로 
	// 101, 102, 103, 104번지에 저장됨




	return 0;
}