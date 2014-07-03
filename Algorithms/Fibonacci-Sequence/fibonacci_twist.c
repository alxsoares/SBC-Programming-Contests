#include <stdio.h>

/*
    ft(n) = ft(n-1) + ft(n-2) + (n-1)
    with ft(0) = 0  & ft(1) = 1

*/
typedef long long LL;

typedef struct matrix {
    LL a1, a2, a3, a4;
} matrix;

matrix product(matrix t1, matrix t2, int M){
	matrix p;
	p.a1 = ((t1.a1*t2.a1) + (t1.a2*t2.a3)) % M;
	p.a2 = ((t1.a1*t2.a2) + (t1.a2*t2.a4)) % M;
	p.a3 = ((t1.a3*t2.a1) + (t1.a4*t2.a3)) % M;
	p.a4 = ((t1.a3*t2.a2) + (t1.a4*t2.a4)) % M;

	return p;
}

// Using matrix exponentiation
matrix get_exp(matrix B, LL n, int M) {
	if(n == 1) return B;

	matrix C = get_exp(B, n/2, M);
	C = product(C, C, M);

	if(n % 2 == 1) return product(B, C, M);
	return C;
}

int main() {
	int t, n, m;
	matrix A, B, F;

	A.a1 = 1; A.a2 = 1; A.a3 = 1; A.a4 = 0;
	F.a1 = 6; F.a2 = 4; F.a3 = 4; F.a4 = 2;
	LL delta;

	scanf("%d", &t);

	while(t--) {
        scanf("%d", &n);
        scanf("%d", &m);

		if(n == 0) {
			printf("0\n");
			continue;
		} else if(n == 1) {
			printf("1\n");
			continue;
		}

		B = get_exp(A, n-1, m);
		B = product(B, F, m);
		delta = ((n+2) / m + 1) * m;
		printf("%lld\n", (B.a2 + delta-n-2) % m);
	}

	return 0;
}
