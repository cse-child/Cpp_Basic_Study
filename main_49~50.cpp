// 어소트락 게임아카데미 - 49화. 리스트(2) 부터

#include <iostream>

#include "LinkedList.h"

int main() {

	tLinkedList list = {};

	InitList(&list);

	PushBack(&list, 10);
	PushBack(&list, 20);
	PushBack(&list, 30);
	
	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i) {
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}

// 49화. 리스트(2) 과제: PushBack말고 PushFront 함수를 구현하라

// 50화. 리스트(3)
// 리스트와 가변배열의 비교

// 리스트 장점
// 리스트는 데이터가 아무리 많아도 중간에 새로운 데이터를 삽입하거나 삭제할 때
// (Head, Tail)노드의 주소만 변경하면 되기 때문에 어렵지 않다.

// 리스트를 사용하지 않고 가변배열로 PushFront 함수를 구현한다면
// 새로운 데이터가 삽입/삭제 될 때마다
// 오른쪽으로 하나씩 자리를 옮겨야 한다. (시간 복잡도 O(n))

// 리스트 단점
// 리스트의 최악의 경우는 데이터가 n개 있을 때 가장 마지막에 위치한
// n번째 노드에 접근하는 경우이다. (반면 꼬리표를 알고 있는 경우엔 가운데를 찾는 경우가 가장 최악)
// 이러한 경우 시간 복잡도는 O(N)

// 지금 수업까지는 C언어 스타일로 자료구조를 공부했지만
// 이후 수업부터는 C++언어 스타일로 클래스 공부부터 시작