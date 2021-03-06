// 어소트락 게임아카데미 - 31화. const포인터 부터

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>


// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(Read Only Memory, 읽기전용, 코드)


void Output(const int *pI) {
	int i = *pI;
	
	// 물론 const 포인터를 강제로 수정할수도 있긴 함.
	int * pInt = (int*)pI;
	*pInt = 1000;
}


int main() {

	// 1. const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;
	// 포인터의 두가지 상황
	// 1. 포인터 자체가 가르킬 변수 주소가 변경되거나
	// 2. 포인터가 가르킨 변수의 값을 변경하거나

	// =============
	// const 포인터
	// =============
	int b = 0;
	const int* pConstInt = &a;
	// const 포인터는 "포인터가 가르키는 원본 변수가 상수화가 된 것"이다.

	// *pConstInt = 100;

	// 따라서 가르키는 변수의 값을 변경하진 못한다.

	pConstInt = &b;
	// 그러나 가르킬 변수는 변경할 수 있다.

	// =============
	// 포인터 const
	// =============
	int* const pIntConst = &a;
	*pIntConst = 400;
	// 포인터 const는 "포인터 변수 자체가 상수화가 된 것"이다.
	// 따라서 포인터가 가르키는 변수의 값은 변경할 수 있지만

	// pIntConst = &b;

	// 포인터가 가르킬 변수를 변경할 순 없다.

	// const와 포인터를 적절한 위치에 사용하면 두가지 모두 사용할수도 있다.
	// 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정할 수 없음
	const int* const pConstIntConst = nullptr;

	// 쉬운 암기법 !
	// const 위치 앞에 무엇이 있느냐?
	// const int* : const는 * '포인터'를 지칭하여 가르키는 변수를 상수화
	// const pIntConst : const는 pIntConst '변수'를 지칭하여 변수 자체가 상수화


	/* const 포인터를 사용하는 예시(경우) */
	a = 100;
	Output(&a);
	// 회사 내의 데이터가 너무 커서 데이터를 전달받진 못하고 
	// 데이터 저장 주소를 전달받는 경우 데이터를 변형시키지 않기 위해
	// 매개변수를 const 포인터로 받아야 한다.
	// 즉, 이 함수의 매개변수를 보면 "아~ 데이터 주소만 읽고 데이터를 바꾸진 않겠다는 거구나~" 라고 이해하면 됨
	// (단, 절대 못바꾸는 것은 아니고 바꿀 생각이 없다는 제작자의 의도를 보여주는 것)
	

	/* 33화. void 강의 */
	// void 포인터
	// 1. 원본의 자료형을 정하지 않는다.
	// 2. 어떠한 타입의 변수의 주소든 다 저장 가능
	// 3. 역참조 불가능
	// 4. 주소 연산 불가능
	void* pVoid = nullptr;
	
	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;
		// void 포인터는 주소를 해석할 때 해석의 단위가 정해지지 않은 포인터이다.
		// 따라서 어떤 변수의 주소든지 모두 저장이 가능하다.

		// *pVoid;
		// 역참조가 불가능하며
		// pVoid + 1;
		// 주소 연산이 안된다.
	}

	// 포인터에서 가장 중요한 개념
	// 원본 데이터가 실제로 어떻게 사용되고 있는지는 포인터와 무관하다.
	// 포인터는 오로지 선언 시점때의 해당 포인터에 선언된 자료형 타입이 무엇인지에 따라 
	// 주소에 접근하는 방법과 분석 방법, 주소 연산 방법이 결정되는 것이다.
	// 따라서 어떠한 메모리 공간에 의미있는 데이터를 저장 시켰을 때에
	// 그 데이터대로 사용하려면 타입(자료형)에 정확히 매칭되도록 선언해야 한다.



	/* 34화. 문자 */
	wchar_t wc = 65; // 아스키코드 A
	short s = 49;

	// 메모리 상에서 상수 1과 문자로써 '1'은 다르다.
	char c = 1; // \x1
	c = '1'; // 아스키코드 49

	wc = 459; // 459를 숫자로 저장하면 459의 2진수 값이 저장된다.
	wc = '459'; // 그러나 459를 문자로 저장하면 '4'의 아스키코드 값과
	// '5', '9'의 아스키코드값이 각각 1바이트로 저장되어 총 3바이트에 저장된다.




	/* 35화. 문자열(1) */
	// char(1), wchar(2)
	char ch = 'a';
	wchar_t wct = L'a'; // 2바이트 문자(wchar)은 'L'을 붙여야 한다.

	char szChar[10] = "abcdef";
	
	wchar_t szWChar[10] = L"abcdef";  // 문자열도 마찬가지로 2바이트 문자열은 'L'을 붙인다.
	// 문자열은 끝에 널문자('\0')가 필요하기 때문에 6글자여도 7글자 크기의 배열이 필요하다.
	short arrShort[10] = { 97,98,99,100,101,102, };
	// short 자료형은 abcdef를 아스키코드 값인 정수형으로 저장한다. 위 szWChar과 똑같은 내용의 배열임.
	// 문자 자료형 저장 및 초기화는 character 자료형만 가능하다.


	const wchar_t* pChar = L"abcdef";
	// const 포인터로 pChar 변수를 선언했는데 abcdef 문자열을 받을 수 있다는 것은
	// 문자열의 정체가 주소값이라는 것이다.
	
	// wchar_t의 배열은 문자열에 적힌 데이터(L"abc")를 배열로 복사해오는 것이다.
	// 따라서 아래 두 선언의 "차이점"을 이해해야 한다 !!!
	wchar_t szWChar2[10] = L"abcdef";
	const wchar_t* pChar2 = L"abcdef";

	szWChar2[1] = 'z'; 
	// wchar_t의 문자열은 배열에 복사해온 데이터를 수정하는 것이기 때문에
	// 배열의 1번째 인덱스인 'b'를 'z'로 변경할 수 있다.
	
	// 그러나 const wchar_t*의 포인터 변수 문자열은 해당 문자열이 존재하는 시작 주소를
	// 가리키고 있기 때문에 아래와 같은

	// pChar[1] = 'z'; 
	// = *(pChar + 1) = 'z';

	// 문자열 변경 수식은 적용되지 않는다. (에러남)

	// @ 정리 @
	// wchar_t szWChar[10] 배열의 의미는 :
	// 스택 메모리에 10크기의 메모리가 지정되고,
	// 해당 메모리에 내가 작성한 문자열(L"abcdef")를 복사시키라는 명령이다.

	// const wchar_t* pChar 포인터 변수의 의미는 :
	// main함수 스택에 포인터변수가 존재하고, 
	// 타이핑한 코드가 다른 메모리 상에 존재할 때, 
	// 포인터 변수는 타이핑한 코드 속 문자열의 시작 주소가 저장되는 것이다.
	// 따라서 pChar[1] = 'z';와 같이 문자열 수정을 시도하면
	// 프로그램 실행 도중 실시간으로 코드가 수정되는 것과 마찬가지이기 때문에
	// 정상작동될 수 없다. 그리고 이미 코드가 작성되는 메모리 영역은 ROM영역으로, 읽기전용이기 때문에 수정도 불가하다.



	/*36화. 문자열(2)*/
	char szTest[10] = "abc한글";
	// char 자료형은 멀티바이트 문자열이다.
	// a,b,c는 1byte에 표현되지만 '한'과 '글'은 1byte, 1byte 두개에 동시에 표현된다.
	// 즉, 2byte를 걸쳐 표현되는 것이다.
	// 멀티바이트라고 해서 2바이트로 통틀어 표현되는것으로 오해하기 좋지만
	// 멀티는 어쩔땐 1byte로 표현되고, 어쩔땐 2byte로 표현되는 것을 의미한다.
	// 현재 Microsoft에서는 멀티바이트는 사용되지 않고 utf-8이라는 인코딩 방식만 사용한다.
	// (표준으로 사용되는 인코딩 방식이 아니다. 현재는 유니코드 문자셋을 사용함)

	wchar_t szTestW[10] = L"abc한글";
	// wchar_t는 2byte로 문자를 표현하는 와이드바이트 시스템(유니코드 방식)이다.
	// a,b,c,한,글 모두 2byte씩 한칸을 차지한다.
	// 수업에서는 무조건 와이드바이트 wchar_t 방식을 사용함

	// 멀티바이트(char)의 문제점은 어떤 문자열을 저장했을 때 각 문자가
	// 몇바이트씩 차지하는지 파악하기 어렵다.


	{
		wchar_t szName[10] = L"Raimond";

		int iLen = wcslen(szName);
		// wcslen은 문자열의 길이를 알려주는 함수이다.
		// 매개변수로 const wchar_t*를 요구하는 이유는 선언된 문자열에 직접 접근해야 하기 때문이다.
		// 문자열은 ROM(읽기전용) 데이터이기 때문에 선언된 데이터를 가져오거나 수정할 수 없다.
		// ROM(읽기전용) 영역 안에 '코드 영역'과 '메모리 초기화 영역'이 따로 존재하는데, 현재 해당 문제는
		// 메모리 초기화 영역에 존재한다.

		// 따라서 wcslen의 매개변수로 배열의 시작 주소인 "szName"을 입력하면 된다.
	}
	return 0;
}


// 단축키 : 함수 호출 원형
// Ctrl + Shift + Space