// 어소트락 게임아카데미 - 44화. 가변배열(2) 부터

#include <iostream>

#include "Arr.h"
#include "LinkedList.h"



int main()
{
	tArr s1 = {};

	InitArr(&s1);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}

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