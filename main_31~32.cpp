// 어소트락 게임아카데미 - 31화. const포인터 부터

#include <stdlib.h>
#include <stdio.h>


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
	

	return 0;
}


// 단축키 : 함수 호출 원형
// Ctrl + Shift + Space