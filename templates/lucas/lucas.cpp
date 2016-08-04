#include <cstdio>

namespace Lucas{
	typedef long long LL;
	const int P = 110119;
	LL fact[P], fact_i[P];

	LL powmod(LL a, int n){
		LL ans = 1;
		while(n){
			if(n & 1) ans = ans * a % P;
			a = a * a % P;
			n >>= 1;
		}
		return ans;
	}

	void init(){
		int i;
		fact[0] = fact[1] = 1;
		fact_i[0] = fact_i[1] = 1;

		for(i = 2;i < P;++i){
			fact[i] = fact[i-1] * i % P;
			fact_i[i] = fact_i[i-1] * powmod(i, P-2) % P;
		}
	}

	int C(int M, int N){
		if(M < N) return 0;
		if(M < P) return (int)(fact[M] * fact_i[N] % P * fact_i[M-N] % P);
		int s = M / P, t = N / P;
		return (LL) C(s, t) * C(M - s * P, N - t * P) % P;
	}
}

int main(){
#ifdef DEBUG
	freopen("test.txt", "r", stdin);
#endif

	int a, b;
	Lucas::init();
	for(int i = 0;i < 10;++i) printf("%lld %lld\n", Lucas::fact[i], Lucas::fact_i[i]);


	while(~scanf("%d %d", &a, &b))
		printf("%d\n", Lucas::C(a, b));
	return 0;
}

