// ���Ʈ�� ���Ӿ�ī���� - 37ȭ. ���ڿ�(3) ����

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>


// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(Read Only Memory, �б�����, �ڵ�)


// �Լ� �����ε� (�������̵��� �ٸ� ���)
void Test(int a)
{

}

void Test(float a)
{

}

typedef struct _tagMyST
{
	int a; // ���
	float f;
}MYST;

/* ���ڿ��� ���� üũ �Լ� (wcslen ����) */
unsigned int GetLength(const wchar_t* _pStr) 
{
	// ���� ���� üũ �뵵
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

	// ���� ����
	//while ('\0' != _pStr[i])
	//{
	//	++i;
	//}

	return i;
}

/* ���ڿ� �̾� ���̱� ���� (wcscat_s ����) */
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	
	if (_iBufferSize < iDestLen + iSrcLen + 1) // Null ���� �������� ���(+1)
	{
		// ����� ����ִ� ���
		assert(nullptr);
	}

	// ���ڿ� �̾� ���̱�
	// 1. Dest ���ڿ��� ���� Ȯ�� (���ڿ��� �̾� ���� ���� ��ġ)
	iDestLen; // Dest ���ڿ��� �� �ε��� ('\0')

	// 2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	// 3. Src ���ڿ��� ���� ������ �ݺ� ����
	for (int i = 0; i < iSrcLen+1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

/* ���� Ǯ�� : ���ڿ��� �켱���� �� ���� (wcscmp ����)*/
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

/* wcscmp ���� ���� ���� */
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
	
	// ���ڿ� �̾� ���̱�
	Test(10);
	Test(4.15f);

	wchar_t szString[10] = L"abc";
	
	wcscat_s(szString, 10, L"def");
	StrCat(szString, 10, L"def");
	// StrCat(szString, 10, L"defghijk"); // ��������

	/* ���� */
	int iRet = wcscmp(L"abc", L"abcz");
	int iRet2 = StrComparison(L"abc", L"abcz");
	int iRet3 = StrCmp(L"gbd", L"abb");
	// wcscmp�� ���ﰰ�� �Լ��̴�.
	// ���ʰ� �������� �Ϻ��ϰ� ��ġ�ϸ� 0
	// ������ �� �쿭�� ���� ���(���������� ����) 1
	// �������� �� �쿭�� ���� ��� -1
	// Hint : �쿭�� ���� �� �ƽ�Ű�ڵ�� ��
	printf("wcscmp ��� : %d\n", iRet);
	printf("wcscmp ��� : %d\n", iRet2);
	printf("wcscmp ��� : %d\n", iRet3);
	printf("%d", int('A'));
	

	/* ���� 40ȭ. ����ü ������ */
	// ����ü�� ������
	MYST s = {};

	MYST* pST = &s;

	s.a = 50;
	s.f = 3.14f;

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a; // ������ �� ���Ŀ� ����� ��Ī�� �� ȭ��ǥ(������)
	pST->f;

	return 0;
}