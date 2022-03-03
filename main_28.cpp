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
	// 따라서 pInt의 주소를 +1한다면 101번지가 아닌 104번지가 된다.
	
	// 강의 속 정리 : pInt는 int* 변수이기 때문에, 가리키는 곳을 int로 해석한다.
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가하게 된다.






	return 0;
}