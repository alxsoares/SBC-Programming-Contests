#include <stdio.h>
#include <stdbool.h>

typedef long long LL;
int cnt[2][1000000], d[20], h, n, m;
LL p10[11];

void savemod(int digits, int *c){
    int i, mod = 0;
    for(i = 0; i < digits; ++i) mod = (mod * 10 + d[i]) % m;
    ++c[mod];
}

void number(int k, bool left){
    if(k >= (h + 1) >> 1) {
        savemod(h + (left ? h : 0), cnt[left]);
        return;
    }

    int i;
    for(i = !k && left; i < 10; ++i) {
        d[k] = d[h - 1 - k] = i;
        number(k + 1, left);
    }
}

int main() {
    int i;
    LL ans = 0;

    scanf("%d %d", &n, &m);
    h = n >> 1; p10[0] = 1;

    for(i = 0; i < 20; ++i) d[i] = 0;
    for(i = 1; i < 11; ++i) p10[i] = p10[i - 1] * 10LL;
    for(i = 0; i < m; ++i) cnt[0][i] = cnt[1][i] = 0;

    number(0, 1); number(0, 0);

    for(i = 1; i < m; ++i)
        if(cnt[0][i] && cnt[1][m - i])
            ans += ((LL) cnt[0][i]) * cnt[1][m - i];

    ans += ((LL) cnt[0][0]) * cnt[1][0];
    printf("%lld\n", ans);
    return 0;
}
