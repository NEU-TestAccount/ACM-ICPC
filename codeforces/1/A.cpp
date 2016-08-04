#include <cstdio>

using namespace std;

int main(){
    int N, M, W;
    scanf("%d %d %d", &N, &M, &W);
    printf("%I64d\n", (long long) ((N - 1) / W + 1) * ((M - 1) / W + 1));
    return 0;
}

