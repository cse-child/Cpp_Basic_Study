// 어소트락 게임아카데미 - 51화. 클래스(1) 부터

#include <iostream>

#include "Arr.h"

struct tMy // C++에는 이름 지정없이 사용 가능
{

};

class CMy
{
	// 접근 제한 지정자
	// private, protected(상속), public
	// C언어에서는 구조체 멤버가 무조건 공개여서 누군가 해당 값을 변경시킬 위험이 존재했음
	// C++에서는 접근 제한 지정자가 생겨서 공개여부를 제어할 수 있음

private:
	int m_i;
	float m_f;

public: // 멤버 함수
	void SetInt(int i) {
		this->m_i = i;
		m_f = 0.f;
	}

	// 대입 연산자
	// 대입 연산자가 void형이면 c = c2 = c3;의 연산 불가능
	// void는 반환값이 없기 때문에 c = ;와 같은 결과임 따라서 
	// CMy의 원본 *this를 반환값으로 준다.
	CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this; // CMy의 원본을 참조로 주겠다. c2에게 주고 c에게 줌
	}

public:
	// 생성자: 초기화 제공 함수
	// 생성자는 반환값이 없다.
	// 이니셜라이저
	CMy()
		: m_i(100)
		, m_f(0.f)
	{

	}

	// 소멸자
	~CMy()
	{

	}
};

int main()
{
	/* C++ 클래스 특징 */
	// 접근제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨

	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수가 객체를 통해서 호출되면, 해당 객체의 주소가 this 포인터로 전달된다.

	{
		// 레퍼런스
		// 자료형 * 변수명;		-> 포인터 변수 선언
		// *포인터 변수;			-> 포인터로 주소 역참조
		// &변수;				-> 변수의 주소값
		// 자료형 & 변수명;		-> 레퍼런스 변수 선언 (C++ 에서 추가됨!)

		// C++에 추가된 기능
		// 포인터와 유사
		// 원본을 참조한다.
		// 참조변수를 통해서 직접적으로 원본을 수정할 수 있다.

		int a = 10;
		int* const p = &a;
		*p = 100;

		int& iRef = a; // a라는 변수의 주소를 받아서 주소에 접근한다.
		iRef = 100;
		// 포인터랑 똑같은 기능 (& -> * const와 동일)
		// 한번 받은 주소 객체를 변경할 수 없다.
		// 장점1: 주소 연산의 실수를 하지 않는다. 근데 포인터랑 똑같아서 얘만의 장점은 아님
		// 장점2: 역참조 연산을 할 필요가 없이 원본을 바로 변경 가능 (이걸 통해 레퍼런스만 가능한 구문이 있다)

		const int* const p2 = &a;
		// *p2 = 10;

		const int& iRefConst = 0; // const int& -> 가르키는 애를 변경할 수 없음
		// iRefConst = 10;

	}


	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);
	arr.iCount = 100;
	ReleaseArr(&arr);

	// 함수 내부로 들어가는 디버깅: F11
	CMy c; // 클래스 객체가 만들어질 때 생성자가 자동 호출된다.
	c.SetInt(10);

	CMy c2;
	c2.SetInt(100);

	CMy c3; // ㅋㅋㅋㅋㅋㅋㅋ처음부터 C언어를 안하고 클래스를 만들면 이게 고마운줄 모른다..^^
	c3.SetInt(1000);

	// 종료될 때 c,c2,c3의 소멸자 3번 실행

	// 대입 연산자
	c = c2 = c3; 
	// c = c2;

	int i = 0;
	int i2 = 5;
	int i3 = 10;

	i = i2 = i3;

	return 0;
}