#include <stdio.h>
#include <stdlib.h>

struct Block{
	short front;
	short tail;
};

struct Block blocks[25];

void move_onto(short a, short b){
	short tmp,tmp_tmp;
	if(a != b){
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
	if(a != b){
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
			switch(cmd[0]){
				case 'm':
					scanf("%d%s%d",&a,cmd2,&b);
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
					scanf("%d%s%d",&a,cmd2,&b);
					switch(cmd2[1]){
						case 'n':

							break;
						case 'v':
							break;
					}
                                        break;
                                case 'q':
					sw = 0;
					break;
			}
		//}
		for(i=0;i<n;i++){
			/*printf("blocks_front[%d]=%hd\n",i,blocks[i].front);
			printf("blocks_tail[%d]=%hd\n",i,blocks[i].tail);*/
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
	}
	return 0;
}
