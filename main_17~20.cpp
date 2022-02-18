// 어소트락 게임아카데미 - 17화. 함수(3)부터

#include <stdio.h>

// 함수
// 함수로 기능을 구현해놓으면 코드가 간결화되고, 모듈화 작업을 잘 해놨다면
// 추후에 복잡한 프로그램을 제작할 때 수월하고 쉽게 구현될 수 있는 기반이 된다.

// Factorial 함수
// 함수의 소스코드 자체가 스택 메모리에 저장되는 것이 아니라
// 함수를 호출함으로써 변수가 초기화되는 값들이 메모리로 저장된다.
// 따라서 같은 함수를 여러번 실행한다고 해도 스택에 함수 메모리가 계속 쌓이는 것이 아니라
// 하나의 함수 스택 안에서 변수 메모리가 쌓이게 된다.
int Factorial(int _iNum) {
	int iValue = 1;

	for (int j = 0; j < _iNum - 1; ++j) {
		iValue *= (j + 2);
	}

	return iValue;
}

// 재귀(Recursive)함수
// 가독성, 구현의 용이
// 단점, 속도가 느리다.

// 반드시 탈출 조건이 있어야 한다.
// 탈출하지 못한다면 stack overflow 발생

// 재귀함수 Factorial
int Factorial_Re(int _iNum) {
	if (_iNum == 1) {
		return 1;
	}
	
	return _iNum * Factorial_Re(_iNum - 1);
}

// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55 ...
// 맨앞을 0 1 로 시작할것인지 1 1로 시작할것인지는 선택
int Fibonacci(int _iNum) {
	if (_iNum == 1 || _iNum == 2) {
		return 1;
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i) {
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

// 재귀함수 - 피보나치 수열
int Fibonacci_Re(int _iNum) {
	if (_iNum == 1 || _iNum == 2) {
		return 1;
	}
	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
}


int main() {
	int iValue = Factorial(4);
	iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(8);
	iValue = Fibonacci_Re(8);

	/* 배열 */
	// 메모리가 연속적
	int iArray[10] = {};

	iArray[12] = 10; // 문제 발생
	// 메모리가 연속적으로 저장되는데 배열의 크기를 넘은 12번지 인덱스에 값을 저장하였다.
	// 그런데 우연으로 기존 선언되었던 'iValue'변수의 데이터 저장 위치가 12번지였기 때문에
	// 디버그를 돌려보면 갑자기 iValue값이 10으로 초기화 되었다.
	// 이러한 문제는 디버그 시에도 에러가 나지 않기 때문에 잘못된 위치를 찾기가 매우 어렵고
	// 내가 넣은적도 없는 값이 변수에 저장되어 당황스러운 일이 생길 수 있다.
	// 따라서 배열의 크기, 값의 저장 인덱스를 알맞게 지정하는 것은 매우 중요하다.

	int iData = 0;

	int iArray2[100] = {};

	return 0;
}