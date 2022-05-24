// 어소트락 게임아카데미 - 44화. 가변배열(2) 부터

#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

void BubbleSort(int* _iData, int _iCount) {
	// 데이터가 1개 이하인 경우는 정렬하지 않음
	if (_iCount <= 1) {
		return;
	}
	// 오름차순 정렬
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
	// 함수 포인터 선언 방법!
	// 함수의 주소를 불러오는법
	// 반환 타입이 void이고 매개변수가 없는(void) Test 함수 호출
	void(*pFunc)(void) = nullptr; 
	pFunc = Test;
	pFunc(); // Test 함수를 호출한 것과 같은 의미



	int iArr[10] = { 87,644,21,55,879,654,55,131, };
	BubbleSort(iArr, 10);




	tArr s1 = {};

	InitArr(&s1);

	// 난수(랜덤) 생성
	srand(time(nullptr)); // 시간값은 항상 다르기때문에 난수 생성에 사용함

	for (int i = 0; i < 10; ++i)
	{
		// PushBack(&s1, i);
		PushBack(&s1, rand() % 100+1); // 1~100 숫자
	}

	printf("정렬 전\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// Sort(&s1); // 함수 포인터 배우기 전
	
	Sort(&s1, &BubbleSort); // 함수 포인터: 매개변수로 함수를 전달
	// BubbleSort로 써도되고 &Bubblesort로 써도됨
	// 함수 포인터 사용하는 경우:
	// 1. 내가 만든 기능을 다른사람이 가져다 쓰는 경우에 사용한다.
	// 다른사람이 내 기능을 실행시키고, 자신의 함수를 또 실행시킬때
	// 내가 다른사람이 실행시킬 기능을 예측해서 미리 만들어놓을 수 없으니
	// CALLBACK같은 기능을 만들어 놓는것이다.
	// 내가 만든 기능을 함수 포인터로 만들어주면 다른사람이 호출해서 사용해볼 수 있도록한다.

	// 2. 분기가 매번 검사되는 경우에 사용한다.
	// if 어떤 상태면 ~~함수 호출해야 하고, else if 어떤 상태면 ~~함수 호출해야하는 경우
	// if 상태면 이 함수를 가르키도록 셋팅해놓으면 계속 그 함수 포인터만 호출해서 사용 가능

	printf("\n정렬 후\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	/* 강의 46화. 리스트(1) */
	// 연결형 리스트
	// LinkedList.h, LinkedList.cpp 파일 생성
	// 데이터를 하나 추가할때마다 새로운 메모리 공간을 할당해서 저장한다.

	return 0;
}

// 과제
// 1. 가변배열
// 스스로 구현 가능하게 복습할 것

// 2. 가변배열 안에 넣은 데이터 정렬
// -버블 정렬

// 나중에 함수포인터 이용해서 정렬의 종류별로 호출 + 정렬구현 해보기