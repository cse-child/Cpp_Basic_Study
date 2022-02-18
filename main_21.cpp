// 어소트락 게임아카데미 - 21화. 구조체
// 우선 초반엔 C언어를 이용하고 이후 C++방식으로 학습할 예정

#include <stdio.h>


// 사용자 정의 자료형
typedef struct _tagMyST{
	// 아래 변수가 선언된 것이 아닌 내가 만든 자료형의 구성을
	// int형 1개, float 1개라고 나타내는 것
	int		a;
	float	f;
}MYST;

typedef struct _tagBig {
	MYST k; // 구조체안에 구조체를 또 자료형으로 사용 가능
	int i;
	char c;
}BIG;

typedef int INT; // typdef는 이름을 정의해주는 것. 
// int의 이름을 INT로 정의하는것처럼 위에 _tagBig에서도
// "struct _tagBig ~~ char c;" 를 BIG이라는 이름으로 정의 해준 것.

// 아래처럼 구조체를 선언하는 것은 C언어와 C++언어 둘다 
// 사용 가능하기 때문에 많이 사용되는 방법이다.
// 그러나 C++에선 "typdef"까지 이용한 구조체 선언은 필요없기 때문에 사용하지 않을 것.
typedef struct NewStruct {
	int a;
	short s;
}NEWST;

int main() {
	
	int arr[10] = { 1, 2, 3, 4, 5, 6 };

	// 구조체
	// 초기화하는 방법은 배열을 초기화하는 것과 비슷하다.
	MYST t = {100, 3.14f};
	// 나만의 자료형을 만들고 내부에 이름을 부여하여 접근 가능
	t.a = 10;
	t.f = 10.2312f;

	struct _tagMyST s;

	// 특정 자료형의 사이즈를 알려준다.
	int iSize = sizeof(MYST); // 8byte


	return 0;
}

