#include <stdio.h>
#include <stdlib.h>

struct Block{
	short front;
	short tail;
};

struct Block blocks[25];

short block_equal(short a, short b){
	short tmp,chk_point;
	chk_point = 0;
	tmp = a;
	while(blocks[tmp].tail != -1){
		if(blocks[tmp].tail == b) chk_point++;
		tmp = blocks[tmp].tail;
	}
	tmp = b;
	while(blocks[tmp].tail != -1){
		if(blocks[tmp].tail == a) chk_point++;
		tmp = blocks[tmp].tail;
	}
	if(chk_point){
		return 0;
	}else{
		return 1;
	}
}

void move_onto(short a, short b){
	short tmp,tmp_tmp;
	if(block_equal(a,b)){
		tmp = a;
		do{
			tmp_tmp = blocks[tmp].tail;
			blocks[tmp].tail = -1;
			tmp = tmp_tmp;
			blocks[tmp].front = -1;
		}while(blocks[tmp].tail != -1);
		tmp = b;
		do{
			tmp_tmp = blocks[tmp].tail;
			blocks[tmp].tail = -1;
			tmp = tmp_tmp;
			blocks[tmp].front = -1;
		}while(blocks[tmp].tail != -1);
		blocks[a].front = b;
		blocks[b].tail = a;
	}
}

void move_over(short a, short b){
	short tmp,tmp_tmp;
	if(block_equal(a,b)){
		tmp = a;
		do{
			tmp_tmp = blocks[tmp].tail;
			blocks[tmp].tail = -1;
			tmp = tmp_tmp;
			blocks[tmp].front = -1;
		}while(blocks[tmp].tail != -1);
		tmp = b;
		if(blocks[tmp].tail != -1){
			while(blocks[tmp].tail != -1){
				tmp = blocks[tmp].tail;
			}
			blocks[tmp].tail = a;
			blocks[a].front = tmp;
		}else{
			blocks[a].front = b;
			blocks[b].tail = a;
		}
	}
}

void pile_onto(short a, short b){
	short tmp,tmp_tmp;
	if(block_equal(a,b)){
		tmp = a;
		do{
			tmp_tmp = blocks[tmp].tail;
			blocks[tmp].tail = -1;
			tmp = tmp_tmp;
			blocks[tmp].front = -1;
		}while(blocks[tmp].tail != -1);
		tmp = b;
		do{
			tmp_tmp = blocks[tmp].tail;
			blocks[tmp].tail = -1;
			tmp = tmp_tmp;
			blocks[tmp].front = -1;
		}while(blocks[tmp].tail != -1);
		blocks[a].front = b;
		blocks[b].tail = a;
	}
}

void pile_over(short a, short b){
	short tmp,tmp_tmp;
	if(block_equal(a,b)){
		tmp = b;
		if(blocks[tmp].tail != -1){
			while(blocks[tmp].tail != -1){
				tmp = blocks[tmp].tail;
			}
			blocks[blocks[a].front].tail = -1;
			blocks[tmp].tail = a;
			blocks[a].front = tmp;
		}else{
			blocks[blocks[a].front].tail = -1;
			blocks[a].front = b;
			blocks[b].tail = a;
		}
	}
}

int main(void){
	int n,sw,i,a,b;
	short tmp;
	char cmd[5],cmd2[5];
	while(scanf("%d",&n) != EOF){
		for(i=0;i<n;i++){
			blocks[i].front = -1;
			blocks[i].tail = -1;
		}
		sw = 1;
		while(sw){
			scanf("%s",cmd);
			scanf("%d%s%d",&a,cmd2,&b);
			switch(cmd[0]){
				case 'm':
					switch(cmd2[1]){
						case 'n':
							move_onto(a,b);
							break;
						case 'v':
							move_over(a,b);
							break;
					}
					break;
                                case 'p':
					switch(cmd2[1]){
						case 'n':
							pile_onto(a,b);
							break;
						case 'v':
							pile_over(a,b);
							break;
					}
                                        break;
                                case 'q':
					sw = 0;
					break;
			}
		}
		for(i=0;i<n;i++){
			printf("%d:",i);
			tmp = i;
			if(blocks[i].front == -1){
				while(blocks[tmp].tail != -1){
					printf(" %d",tmp);
					tmp = blocks[tmp].tail;
				}
				printf(" %d\n",tmp);
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}
