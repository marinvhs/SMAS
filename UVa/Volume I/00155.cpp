#include <cstdio>
int res, x, y, k;

void square(int xc, int yc, int k) {
	if(x >= (xc-k) && x <= (xc+k) && y >= (yc-k) && y <= yc+k)
			res++;
	if (k <= 1)
			return;
	square(xc-k,yc-k,k/2);
	square(xc+k,yc-k,k/2);
	square(xc-k,yc+k,k/2);
	square(xc+k,yc+k,k/2);
}

int main(void) {
	while(scanf("%d %d %d",&k,&x,&y)){
		if(!k)
				break;
		res = 0;
		square(1024,1024,k);
		printf("%3d\n",res);
	}
}
