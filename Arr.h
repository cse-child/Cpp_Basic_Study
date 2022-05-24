#pragma once

// int형 가변배열
typedef struct _tabArr
{
	// 필수 멤버 3가지
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// tArr s;를 선언할 때 s 객체를 초기화할 함수 (배열 초기화)
// 함수 생성 단축키 : Ctrl + '+' + '.'
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 배열의 공간 추가 확장 함수
// void Reallocate(tArr* _pArr);
// 해당 함수를 main함수에서 직접 호출하지 못하도록 제한할 수 있다.
// 헤더파일에서 해당 함수선언을 가려도 Arr.cpp파일 내부에서 자체적으로 호출하여
// 프로그램이 정상작동 될 수 있다.

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);

// 데이터 정렬 함수
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));
// 함수 포인터를 두번째 매개변수로 받음