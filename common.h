#pragma once

// 모든 파일에서 하나의 변수를 사용하고 싶은 경우 '외부 변수'를 사용한다.
extern int g_iExtern;
// extern int g_iExtern = 0;  (X)

// extern 변수의 초기화는 다른 파일에서 
// int g_iExtern = 0; 와 같이 수행해야 한다.
