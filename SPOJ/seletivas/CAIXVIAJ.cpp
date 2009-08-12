#include <cstdio>

#define NN 128
#define TT 1024

inline int max(int a, int b) { return a < b ? b : a; }

int c, s, e, t;
int w[NN][NN], f[NN], m[NN][TT], ans;

int main(void) {
	int i, j, k;

	while(scanf("%d %d %d %d", &c, &s, &e, &t)) {
		if(c == 0 && s == 0 && e == 0 && t == 0) break;
		for(i = 0; i < c; i++) for(j = 0; j < c; j++) scanf("%d", &w[i][j]);
		for(i = 0; i < e; i++) scanf("%d", &f[i]), f[i]--;
		s--;
		for(i = 0; i < c; i++) m[i][1] = w[s][i];
		for(k = 2; k <= t; k++) {
			for(i = 0; i < c; i++) m[i][k] = 0;
			for(i = 0; i < c; i++)
				for(j = 0; j < c; j++)
					m[j][k] = max(m[j][k], m[i][k-1] + w[i][j]);
		}
		ans = 0;
		for(i = 0; i < e; i++) if(m[f[i]][t] > ans) ans = m[f[i]][t];
		printf("%d\n", ans);
	}

	return 0;
}
