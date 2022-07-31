// ���Ʈ�� ���Ӿ�ī���� - 51ȭ. Ŭ����(1) ����

#include <iostream>

#include "Arr.h"

struct tMy // C++���� �̸� �������� ��� ����
{

};

class CMy
{
	// ���� ���� ������
	// private, protected(���), public
	// C������ ����ü ����� ������ �������� ������ �ش� ���� �����ų ������ ��������
	// C++������ ���� ���� �����ڰ� ���ܼ� �������θ� ������ �� ����

private:
	int m_i;
	float m_f;

public: // ��� �Լ�
	void SetInt(int i) {
		this->m_i = i;
		m_f = 0.f;
	}

	// ���� ������
	// ���� �����ڰ� void���̸� c = c2 = c3;�� ���� �Ұ���
	// void�� ��ȯ���� ���� ������ c = ;�� ���� ����� ���� 
	// CMy�� ���� *this�� ��ȯ������ �ش�.
	CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this; // CMy�� ������ ������ �ְڴ�. c2���� �ְ� c���� ��
	}

public:
	// ������: �ʱ�ȭ ���� �Լ�
	// �����ڴ� ��ȯ���� ����.
	// �̴ϼȶ�����
	CMy()
		: m_i(100)
		, m_f(0.f)
	{

	}

	// �Ҹ���
	~CMy()
	{

	}
};

int main()
{
	/* C++ Ŭ���� Ư¡ */
	// �������� ������
	// Ŭ���� ���� ������� or ����Լ��� ���� ����

	// ������, �Ҹ���
	// ��ü ����, �Ҹ� �� �ڵ����� ȣ��
	// ���� ������ ������ �⺻ ������, �⺻ �Ҹ��ڰ� �������

	// ����Լ�
	// �ش� Ŭ������ ����ϴ� ���� �Լ�
	// �ش� Ŭ������ ��ü�� �ʿ���
	// ����Լ��� ��ü�� ���ؼ� ȣ��Ǹ�, �ش� ��ü�� �ּҰ� this �����ͷ� ���޵ȴ�.

	{
		// ���۷���
		// �ڷ��� * ������;		-> ������ ���� ����
		// *������ ����;			-> �����ͷ� �ּ� ������
		// &����;				-> ������ �ּҰ�
		// �ڷ��� & ������;		-> ���۷��� ���� ���� (C++ ���� �߰���!)

		// C++�� �߰��� ���
		// �����Ϳ� ����
		// ������ �����Ѵ�.
		// ���������� ���ؼ� ���������� ������ ������ �� �ִ�.

		int a = 10;
		int* const p = &a;
		*p = 100;

		int& iRef = a; // a��� ������ �ּҸ� �޾Ƽ� �ּҿ� �����Ѵ�.
		iRef = 100;
		// �����Ͷ� �Ȱ��� ��� (& -> * const�� ����)
		// �ѹ� ���� �ּ� ��ü�� ������ �� ����.
		// ����1: �ּ� ������ �Ǽ��� ���� �ʴ´�. �ٵ� �����Ͷ� �Ȱ��Ƽ� �길�� ������ �ƴ�
		// ����2: ������ ������ �� �ʿ䰡 ���� ������ �ٷ� ���� ���� (�̰� ���� ���۷����� ������ ������ �ִ�)

		const int* const p2 = &a;
		// *p2 = 10;

		const int& iRefConst = 0; // const int& -> ����Ű�� �ָ� ������ �� ����
		// iRefConst = 10;

	}


	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);
	arr.iCount = 100;
	ReleaseArr(&arr);

	// �Լ� ���η� ���� �����: F11
	CMy c; // Ŭ���� ��ü�� ������� �� �����ڰ� �ڵ� ȣ��ȴ�.
	c.SetInt(10);

	CMy c2;
	c2.SetInt(100);

	CMy c3; // ��������������ó������ C�� ���ϰ� Ŭ������ ����� �̰� �������� �𸥴�..^^
	c3.SetInt(1000);

	// ����� �� c,c2,c3�� �Ҹ��� 3�� ����

	// ���� ������
	c = c2 = c3; 
	// c = c2;

	int i = 0;
	int i2 = 5;
	int i3 = 10;

	i = i2 = i3;

	return 0;
}