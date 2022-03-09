// 어소트락 게임아카데미 - 37화. 문자열(3) 부터

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>


// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(Read Only Memory, 읽기전용, 코드)


// 함수 오버로딩 (오버라이딩과 다른 기능)
void Test(int a)
{

}

void Test(float a)
{

}

/* 문자열의 길이 체크 함수 (wcslen 구현) */
unsigned int GetLength(const wchar_t* _pStr) 
{
	// 문자 개수 체크 용도
	int i = 0;

	while (true)
	{
		// wchar_t c = *(_pStr + i);
		wchar_t c = _pStr[i];

		if ('\0' == c)
		{
			break;
		}
		++i;
	}

	// 줄인 버전
	//while ('\0' != _pStr[i])
	//{
	//	++i;
	//}

	return i;
}

/* 문자열 이어 붙이기 구현 (wcscat_s 구현) */
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	
	if (_iBufferSize < iDestLen + iSrcLen + 1) // Null 문자 공간까지 계산(+1)
	{
		// 경고문을 띄워주는 기능
		assert(nullptr);
	}

	// 문자열 이어 붙이기
	// 1. Dest 문자열의 끝을 확인 (문자열이 이어 붙을 시작 위치)
	iDestLen; // Dest 문자열의 끝 인덱스 ('\0')

	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen+1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int main() 
{
	wchar_t szName[10] = L"Raimond";

	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);
	
	// 문자열 이어 붙이기
	Test(10);
	Test(4.15f);

	wchar_t szString[10] = L"abc";
	
	// wcscat_s(szString, 10, L"def");
	StrCat(szString, 10, L"def");
	// StrCat(szString, 10, L"defghijk"); // 에러예시

	/* 과제 */
	int iRet = wcscmp(L"abc", L"cbc");
	// wcscmp는 저울같은 함수이다.
	// 왼쪽과 오른쪽이 완벽하게 일치하면 0
	// 왼쪽이 더 우열이 높은 경우(사전순서로 후위) 1
	// 오른쪽이 더 우열이 높은 경우 -1
	// Hint : 우열을 가릴 땐 아스키코드로 비교

	return 0;
}