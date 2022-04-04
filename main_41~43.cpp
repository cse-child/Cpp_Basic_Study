// 어소트락 게임아카데미 - 41화. 동적할당(1) 부터

#include <stdio.h>
#include <iostream>

#include "Arr.h"

// 변수의 데이터 영역
// 지역(스택)
// 전역, 정적, 외부(데이터)

// 메모리 영역
// 스택
// 데이터
// ROM
// ★힙 영역(동적할당)



int main() {
	// 동적할당 : 프로그램 실행 도중에(런타임 중) 내가 원하는 만큼 메모리를 요청할 수 있는 것
	// 이때 사용하는 영역은 힙 메모리 영역이며, 원하는 메모리 크기를 잡고
	// 주소를 받아와서 어떤 목적으로 쓸지 포인터 캐스팅을 해주면 된다.

	int* pInt = (int*)malloc(100);
	// 힙 영역에 100바이트 메모리를 할당해놓고 해당 메모리의
	// 시작 주소를 pInt 포인터 변수에 준 것이다.
	
	// (int*)강제 캐스팅을 한 이유:
	// malloc(memory allocator)는 반환 타입이 void 포인터이다.
	// void포인터는 주소만을 저장하기 위한 목적으로 실제 원형 데이터를 분석할 순 없기 때문에
	// 원형을 어떻게 볼지 캐스팅을 통해 정해준 것이다.

	float* pF = (float*)malloc(4);

	// 동적 할당에서 중요한 점!
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 관리해야함(해제) 
	// - 해제를 안하고 프로그램을 종료하면, 메모리가 사용된다고 계속 체크되어 "메모리 누수"가 발생


	int iInput = 0;
	scanf_s("%d", &iInput);

	int* pInt2 = nullptr;

	if (100 == iInput) {
		pInt = (int*)malloc(100);
	}

	if (nullptr != pInt) {
		free(pInt); 
		// free 함수의 인자인 pInt의 주소로 가서
		// 거기있는 힙 메모리를 해제하는 것
	}

	/* 43화. 가변 배열 */
	// 가변 배열
	int a = 100;
	
	// 배열 개수를 선언할 때에는 변수를 사용할 수 없다.
	// int arr[a] = {};

	// 객체(Instance)
	// int,
	// int a;

	// 가변배열 자료형을 만들기 위해 Arr.cpp, Arr.h 생성
	tArr arr;
	tArr arr2;
	tArr arr3;

	return 0;
}