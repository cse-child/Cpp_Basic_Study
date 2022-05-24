// 어소트락 게임아카데미 47화. 과제풀이

#include <iostream>

#include "Linked_Arr.h"

int main(void) {
	tArr s1 = {};
	int arr[] = { 5,10,2,7,3,1,9,4,8,6 };

	Linked_InitArr(&s1);

	for (int i = 0; i < 10; ++i) { // 가변배열에 0~9의 숫자를 넣어라
		Linked_PushBack(&s1, arr[i]);
	}

	printf("버블정렬 전 배열: ");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d  ", s1.pInt[i]);
	}

	for (int i = 1; i <= s1.iCount; ++i) {
		for (int j = 0; j < s1.iCount-i; ++j) {
			if (s1.pInt[j] > s1.pInt[j+1]) {
				int temp = s1.pInt[j];
				s1.pInt[j] = s1.pInt[j + 1];
				s1.pInt[j + 1] = temp;
			}
		}
	}

	printf("\n버블정렬 후 배열: ");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d  ", s1.pInt[i]);
	}

	Linked_ReleaseArr(&s1);

	return 0;
}

// 나중에 추가적으로 삽입정렬, 선택정렬, 합병(머지)정렬, 
// 쾌속(퀵) 정렬, 힙 정렬(완전 이진트리)도 구현하기.