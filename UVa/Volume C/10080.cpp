#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define NN 128
#define EPS 1E-7

struct point { double x, y; };
int M, N;
double S, V;
point GG[NN], hole;

double sqd(point a, point b){
	double x = a.x - b.x, y = a.y - b.y;
	return ((x*x)+(y*y));
}
/* {{{ Hopcroft-Karp */
#define tr(x) for(typeof(g[x].begin())it = g[x].begin(); it != g[x].end(); it++)

int dx[NN], dy[NN], px[NN], py[NN], q[NN];
vector <int> g[NN];

bool BFS(int n, int m){
	bool f = 0;
	int i, h = 0, t = 0;
	memset(dx,0,n<<2);
	memset(dy,0,m<<2);
	for(i = 0; i < n; i++) if(px[i] == -1) q[t++] = i;
	while(h < t){
		int x = q[h++];
		tr(x) if(!dy[(*it)]){
			dy[(*it)] = dx[x] + 1;
			if(py[(*it)] == -1) f = 1;
			else dx[py[(*it)]] = dy[(*it)]+1, q[t++] = py[(*it)];
		}
    }
    return f;
}
bool DFS(int x){
	tr(x) if(dy[(*it)] == dx[x]+1){
		dy[(*it)] = 0;
		if(py[(*it)] == -1 || DFS(py[(*it)]))
			return px[x] = (*it), py[(*it)] = x, true;
	}
	return false;
}
int hopcroft_karp(int n, int m){
	int i, mm = 0;
	memset(px,-1,n<<2);
	memset(py,-1,m<<2);
	while(BFS(n, m))
		for(i = 0; i < n; i++)
			mm += (px[i] == -1 && DFS(i));
    return mm;
}
/* }}} */
int main(void){
	int i, j;
	while(scanf("%d %d %lf %lf",&N,&M,&S,&V)==4){
		S = (S*V); S *= S;
		for(i = 0; i < N; i++) g[i].clear();
		for(i = 0; i < N;  i++) scanf("%lf %lf",&GG[i].x,&GG[i].y);
		for(i = 0; i < M; i++){
			scanf("%lf %lf",&hole.x,&hole.y);
			for(j = 0; j < N; j++)
				if(sqd(GG[j],hole) < S+EPS) g[j].push_back(i);
		}
		printf("%d\n",N - hopcroft_karp(N,M));
	}
	return 0;
}
