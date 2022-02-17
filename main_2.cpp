#include <stdio.h>
// 어소트락 게임아카데미 - 13화. 함수(1) / 반복문 부터


int Add(int a, int b) {
	return a + b;
}

// 함수
int main() {
	int iData = Add(100, 200);

	// 반복문
	//for (/*반복자 초기화*/;/*반복자 조건 체크*/;/*반복자 변경*/) {

	//}

	// i = 0, 1, 2, 3
	for (int i = 0; i < 4; ++i) {
		printf("Output Test\n");

		if (i % 2 == 1) {
			continue;
		}
	}

	//while (/*조건 체크*/) {

	//}

	/*int i = 0;
	while (i < 2) {
		printf("Output Test2\n");
		++i;
	}*/

	int i = 0;
	int i2 = 2;

	// 콘솔
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

/* 단축키 */
// 지정한 구문 주석		: Ctrl + k, c
// 지정한 구문 주석 해제	: Ctrl + k, u
// 원하는 영역만 드래그	: Alt + Drag

// 디버깅
// 디버깅 시작			: F5
// 다음 중단점까지 코드 실행

// 중단점 생성 및 해제	: F9
// 디버깅 중, 구문 수행	: F10
// 디버깅 중, 구문 수행(함수 진입)	: F11
// 디버깅 중, 디버깅 종료하기		: Shift + F5