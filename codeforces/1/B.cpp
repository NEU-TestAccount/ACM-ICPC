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
const int maxn = 20;
char A[maxn], B[maxn];

inline void print_col(int col){
	static char buf[maxn];
	int i, len = 0;
	--col;
	while(col){
		buf[len++] = 'A' + col % 26;
		col /= 26;
	}
	--len;
	if(len) --buf[len];

	for(i = 0;i <= len;++i)
		B[i] = buf[len - i];
	B[i] = 0;
}

inline void get_co(int Alen, int &row, int &col){
	int i;
	col = A[i] - 'A' + 1;
	for(i = 0;isalpha(A[i]);++i)
		col = col * 26 + A[i] - 'A';
	++col;

	sscanf(A + i, "%d", &row);
}

inline void work(){
	int ch, len = 0, i,row, col;
	bool rc = false;
	while(isalpha(ch = getchar()) || isdigit(ch)) A[len++] = ch;
	A[len] = 0;

	for(i = 0;i < len;++i) if(isdigit(A[i])) break;
	for(;i < len;++i) if(isalpha(A[i])){
		rc = true;
		break;
	}

	if(rc){
		sscanf(A, "R%dC%d", &row, &col);
		print_col(col);
		printf("%s%d\n", B, row);
	}
	else{
		get_co(len, row, col);
		printf("R%dC%d\n", row, col);
	}
}

int main(){
#ifdef DEBUG
	freopen("test.txt", "r", stdin);
#endif

	int T;
	getint(T);
	while(T--) work();
	return 0;
}


