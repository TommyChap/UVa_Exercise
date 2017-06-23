#include <stdio.h>
#include <stdlib.h>

int main(void){
        short box[30][10],k,n,i,;
        
        while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld"
        		,b,g,c,b+1,g+1,c+1,b+2,g+2,c+2) != EOF){
        	for(i=0;i<6;i++){
        		size[i] = Count(i);
        	}
        	printf("%s %ld\n",string[Min()],size[Min()]);
	}
	return 0;
}

/*
5 2 20 1 30 10
23 15 7 9 11 3
40 50 34 24 14 4
9 10 11 12 13 14
31 4 18 8 27 17
44 32 13 19 41 19
1 2 3 4 5 6
80 37 47 18 21 9

1: 30 20 10 05 02 01
2: 23 16 11 09 07 03
3: 50 40 34 24 14 04
4: 14 13 12 11 10 09
5: 31 27 18 17 08 04
6: 44 41 32 19 19 13
7: 06 05 04 03 02 01
8 :80 47 37 21 18 09
7->4
*/
