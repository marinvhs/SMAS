#include <cstdio>
#include <cstring>
#define MAX(a,b) ((a)>(b)?(a):(b))
char c[2][1200], *c_pos, num, *k, oc;
bool op;
int main(void){
	int i, s_pos, TERM, POS;
	while(scanf("%s%d%d",c,&TERM,&POS) && TERM){
		for(op = i = 1; i < TERM; i++, op = !op){
			for(c_pos = &c[op][0], oc = '1', num = c[!op][0], k = &c[!op][1]; *k; k++){
				if(*k == num) ++oc;
				else {
					*c_pos++ = oc;
					*c_pos++ = num;
					num = *k;
					oc = '1';
					if((c_pos - &c[op][0]) > POS+50) break;

				}
			}
			*c_pos++ = oc;
			*c_pos++ = num;
			*c_pos = 0;
		}
		printf("%c\n",c[!op][POS-1]);
	}
	return 0;
}

