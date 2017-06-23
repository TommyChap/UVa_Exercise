#include <stdio.h>
#include <stdlib.h>

void sort(short arr[],short len){
	short i, j, temp;
	for (i = 0; i < len - 1; i++){
		for (j = 0; j < len - 1 - i; j++){
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void){
        short box[30][10],size[30],k,n,i,j;
        
        while(scanf("%hd %hd",&k,&n) != EOF){
        	for(i=0;i<30;i++){
        		for(j=0;j<10;j++){
        			box[i][j] = 0;
        		}
        	}
        	for(i=0;i<k;i++){
        		for(j=0;j<n;j++){
        			scanf("%hd",&box[i][j]);
        		}
        		sort(box[i],n);
        		/*for(j=0;j<n;j++){
        			printf("%hd ",box[i][j]);
        		}
       			printf("\n");*/
        	}
        	for(i=0;i<k;i++){
        		for(j=0;j<n;j++){
        			scanf("%hd",&box[i][j]);
        		}
        		sort(box[i],n);
        		/*for(j=0;j<n;j++){
        			printf("%hd ",box[i][j]);
        		}
       			printf("\n");*/
        	}
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
