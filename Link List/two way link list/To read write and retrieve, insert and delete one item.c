#include<stdio.h>
#include<malloc.h>
struct section{
	struct section* prb;
	char ch;
	struct section* nxb;
};
struct section *head, *tail, *tnb, *tb, *i, *tr;

struct section* get_set_node(){
	char tch;
	tnb=(struct section*)malloc(sizeof(struct section));
	head=tnb;
	head->prb='\0';
	printf("Start inputting characters: (Insert '#' to end) \n");
	while(1==scanf("\n%c",&tch)){
		if(tch=='#'){
			tb->nxb='\0';
			tail=tb;
			break;
		}
		tb=tnb;
		tb->ch=tch;
		tnb=(struct section*)malloc(sizeof(struct section));
		tnb->prb=tb;
		tb->nxb=tnb;
	}
	return head;
}

traverse(struct section *rhead){
	printf("Parent Block | Current Block | Current Block Element | Next Block\n");
	while(rhead){
		printf("%10x %12x %15c %22x\n",rhead->prb,rhead,rhead->ch,rhead->nxb);
		rhead=rhead
		->nxb;
	}
}

struct section* insert_char( struct section *rhead2){
	int choice2;
	char tc, ic;
	struct section *tp, *tb3;
	tnb=(struct section*)malloc(sizeof(struct section));
	printf("\nWhich character do you want to insert?\n");
	scanf("\n%c",&ic);
	getchar();
	tnb->ch=ic;
	printf("\n1. Before node\n2. Inside node\n3. After node ");
	scanf("\n%d",&choice2);
	tb3=rhead2;
	if(choice2==2){
		printf("After which character and which position?\n");
		scanf("\n%c",&tc);
		scanf("\n%x",&tp);
		while(tb3){
			if(tb3->ch==tc&&tb3==tp){
				tnb->nxb=tb3->nxb;
				tnb->prb=tb3;
				(tnb->nxb)->prb=tnb;
				tb3->nxb=tnb;
			}
			tb3=tb3->nxb;
		}
		tb3=rhead2;
	}
	else if(choice2==1){
		tnb->nxb=tb3;
		tnb->prb=tb3->prb;
		tb3->prb=tnb;
		tb3=tnb;
	}
	else{
		while(tb3){
			if(tb3->nxb=='\0'){
				tb3->nxb=tnb;
				tnb->prb=tb3;
				tnb->nxb='\0';
			}
			tb3=tb3->nxb;
		}
		tb3=rhead2;
	}
	return tb3;
}

struct section* delete_char(struct section* rhead3){
	struct section *tb4, *tp;
	char tc;
	tb4=rhead3;
	printf("Which character and which position?\n");
	scanf("\n%c",&tc);
	scanf("\n%x",&tp);
	while(tb4){
		if((tb4->ch==tc)&&(tb4==tp)){
			if(rhead3==tb4){
				tb4=tb4->nxb;
				tb4->prb='\0';
				break;
			}
			else if(tb4->nxb=='\0'){
				(tb4->prb)->nxb='\0';
				tb4=rhead3;
				break;
			}
			else{
				(tb4->prb)->nxb=tb4->nxb;
				(tb4->nxb)->prb=tb->prb;
				tb4=rhead3;
				break;
			}
		}
		tb4=tb4->nxb;
	}
	return tb4;
}

int main(){
	int choice;
	i=get_set_node();
	while(choice){
		printf("\nWould You Like To: \n1. Display Input Data\n2. Insert something\n3. Delete something\n4. Exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: traverse(i);
			break;
			case 2: i=insert_char(i);
			break;
			case 3: i=delete_char(i);
			break;
			default : exit(1);
		}
	}
	return 0;
}
