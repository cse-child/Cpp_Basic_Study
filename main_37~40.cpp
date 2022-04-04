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

typedef struct _tagMyST
{
	int a; // 멤버
	float f;
}MYST;

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

/* 과제 풀이 : 문자열의 우선순위 비교 구현 (wcscmp 구현)*/
int StrComparison(const wchar_t* Str1, const wchar_t* Str2)
{
	int i = 0;
	const wchar_t* big = GetLength(Str1) >= GetLength(Str2) ? Str1 : Str2;

	while ('\0' != big[i])
	{
		if (Str1[i] > Str2[i])
		{
			return 1; 
		}
		else if(Str1[i] < Str2[i])
		{
			return -1;
		}
		++i;
	}
	return 0;
}

/* wcscmp 구현 강의 정답 */
int StrCmp(const wchar_t* _left, const wchar_t* _right)
{
	int leftLen = GetLength(_left);
	int rightLen = GetLength(_right);

	int iLoop = leftLen;
	int iReturn = 0;

	if (leftLen < rightLen)
	{
		iLoop = leftLen;
		iReturn = -1;
	}
	else if(leftLen > rightLen)
	{
		iLoop = rightLen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; ++i)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else if(_left[i] > _right[i])
		{
			return 1;
		}
	}
	return iReturn;
}

int main() 
{
	wchar_t szName[10] = L"Raimond";

	int iLen = wcslen(szName);
	int iLen2 = GetLength(szName);
	
	// 문자열 이어 붙이기
	Test(10);
	Test(4.15f);

	wchar_t szString[10] = L"abc";
	
	wcscat_s(szString, 10, L"def");
	StrCat(szString, 10, L"def");
	// StrCat(szString, 10, L"defghijk"); // 에러예시

	/* 과제 */
	int iRet = wcscmp(L"abc", L"abcz");
	int iRet2 = StrComparison(L"abc", L"abcz");
	int iRet3 = StrCmp(L"gbd", L"abb");
	// wcscmp는 저울같은 함수이다.
	// 왼쪽과 오른쪽이 완벽하게 일치하면 0
	// 왼쪽이 더 우열이 높은 경우(사전순서로 후위) 1
	// 오른쪽이 더 우열이 높은 경우 -1
	// Hint : 우열을 가릴 땐 아스키코드로 비교
	printf("wcscmp 결과 : %d\n", iRet);
	printf("wcscmp 결과 : %d\n", iRet2);
	printf("wcscmp 결과 : %d\n", iRet3);
	printf("%d", int('A'));
	

	/* 강의 40화. 구조체 포인터 */
	// 구조체와 포인터
	MYST s = {};

	MYST* pST = &s;

	s.a = 50;
	s.f = 3.14f;

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a; // 역참조 한 이후에 멤버를 지칭할 땐 화살표(포인터)
	pST->f;

	return 0;
}