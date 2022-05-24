#include "Linked_Arr.h"

#include <iostream>

void Linked_InitArr(tArr* _pArr) {
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // 가변 배열의 크기를 2로 지정
	_pArr->iCount = 0; // 0 인덱스 부터 시작
	_pArr->iMaxCount = 2; // 배열의 최대 크기 (처음 초기화엔 2로)
}

void Linked_Reallocate(tArr* _pArr) {
	int* newArr = (int*)malloc(sizeof(_pArr->pInt) * 2 * sizeof(int));

	for (int i = 0; i < _pArr->iMaxCount; ++i) {
		newArr[i] = _pArr->pInt[i];
	}

	free(_pArr->pInt); // 기존 old 배열은 메모리 할당 해제

	_pArr->pInt = newArr;

	_pArr->iMaxCount *= 2;

}

void Linked_PushBack(tArr* _pArr, int _iData) {
	if (_pArr->iCount >= _pArr->iMaxCount) {
		Linked_Reallocate(_pArr);
	}
	_pArr->pInt[_pArr->iCount++] = _iData;
}



void Linked_ReleaseArr(tArr* _pArr) {
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}