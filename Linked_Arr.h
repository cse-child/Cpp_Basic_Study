#pragma once


typedef struct _tabArr {
	int* pInt; // 가변 배열 객체
	int iCount; // 배열의 인덱스?
	int iMaxCount; // 가변 배열의 크기
}tArr;

void Linked_InitArr(tArr* _pArr);

void Linked_PushBack(tArr* _pArr, int _iData);

void Linked_ReleaseArr(tArr* _pArr);