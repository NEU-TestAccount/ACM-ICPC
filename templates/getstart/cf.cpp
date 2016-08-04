/*****************************************************/
/**********************Asm.Def************************/
/*****************************************************/
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

template <class T>
inline void getint(T &x){
	int ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	x = ch - '0';
	while(isdigit(ch = getchar())) x = x * 10 - '0' + ch;
}
/******************************************************/

int main(){
#ifdef DEBUG
	freopen("test.txt", "r", stdin);
#endif

	return 0;
}


