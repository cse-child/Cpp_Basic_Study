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

int main() 
{
	wchar_t szName[10] = L"Raimond";

	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);
	
	// ���ڿ� �̾� ���̱�
	Test(10);
	Test(4.15f);

	wchar_t szString[10] = L"abc";
	
	// wcscat_s(szString, 10, L"def");
	StrCat(szString, 10, L"def");
	// StrCat(szString, 10, L"defghijk"); // ��������

	/* ���� */
	int iRet = wcscmp(L"abc", L"cbc");
	// wcscmp�� ���ﰰ�� �Լ��̴�.
	// ���ʰ� �������� �Ϻ��ϰ� ��ġ�ϸ� 0
	// ������ �� �쿭�� ���� ���(���������� ����) 1
	// �������� �� �쿭�� ���� ��� -1
	// Hint : �쿭�� ���� �� �ƽ�Ű�ڵ�� ��

	return 0;
}