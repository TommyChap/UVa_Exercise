#include <stdio.h>
#include <stdlib.h>

long bgc_table[3][3],size[6];

short Min(void){
	long min = 0x7fffffff;
	short i,tmp;
	for(i=0;i<6;i++){
		if(size[i] < min){
			min = size[i];
			tmp = i;
		}
	}
	return tmp;
}

long Count(short select){
	switch(select){
		case 0:
			return (bgc_table[0][1]+bgc_table[0][2])+(bgc_table[1][0]+bgc_table[1][1])+(bgc_table[2][0]+bgc_table[2][2]);
		case 1:
			return (bgc_table[0][1]+bgc_table[0][2])+(bgc_table[1][0]+bgc_table[1][2])+(bgc_table[2][0]+bgc_table[2][1]);
		case 2:
			return (bgc_table[0][0]+bgc_table[0][2])+(bgc_table[1][0]+bgc_table[1][1])+(bgc_table[2][1]+bgc_table[2][2]);
		case 3:
			return (bgc_table[0][0]+bgc_table[0][1])+(bgc_table[1][0]+bgc_table[1][2])+(bgc_table[2][1]+bgc_table[2][2]);
		case 4:
			return (bgc_table[0][0]+bgc_table[0][2])+(bgc_table[1][1]+bgc_table[1][2])+(bgc_table[2][0]+bgc_table[2][1]);
		case 5:
			return (bgc_table[0][0]+bgc_table[0][1])+(bgc_table[1][1]+bgc_table[1][2])+(bgc_table[2][0]+bgc_table[2][2]);
	}
}

int main(void){
        long *b,*g,*c;
        char string[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
        short i;
        b = &bgc_table[0][0];
        g = &bgc_table[1][0];
        c = &bgc_table[2][0];
        while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld"
        		,b,g,c,b+1,g+1,c+1,b+2,g+2,c+2) != EOF){
        	for(i=0;i<6;i++){
        		size[i] = Count(i);
        	}
        	printf("%s %ld\n",string[Min()],size[Min()]);
	}
	return 0;
}
