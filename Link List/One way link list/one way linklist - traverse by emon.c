#include<stdio.h>
struct block{ //Structing a data type named block //
    char cdata;
    struct block *nxb;
};
struct block *tnb, *head, *tb, *cb;

// Prototypes of functions //
int get_set_node(char rdata);
void traverse_list(struct block *rhead);

// Main function //
int main(){
    int i;
    char data;
    printf("Input a character\n");
    scanf("%c",&data);
    i=get_set_node(data); // Sending data to and receiving head from get_set_node //
    printf("Below is the traversed data\n");
    traverse_list(i); // Calling traverse_list function for desired output //
    return 0;
}

// Commencing get_set_node function //
int get_set_node(char rdata){
    char ch;
    tnb=(struct block*)malloc(sizeof(struct block)); // Allocating a new block for pointer tnb //
    head=tnb;
    head->cdata=rdata;
    tb=head;
    ch=rdata;
    printf("Input '#' to terminate\n"); // Termination condition of data input //
    while(1){
        tb=tnb;
        tb->cdata=ch;
        scanf("\n%c",&ch);
        tnb=(struct block*)malloc(sizeof(struct block)); // Allocating block for tnb one by one //
        if(ch=='#'){
            tb->nxb='\0'; // Assigning tb->nxb by null will end the link line //
            break; // Breaking of the loop //
        }
        tb->nxb=tnb;
    }
    return head;
}

// Commencing of the traverse_list function //
void traverse_list(struct block *rhead){
    cb=rhead;
    printf("Current node  Current node data  Next node link\n");
    while(cb!='\0'){ // Checking for the null character to find the end of list //
        printf("%10x %15c %15x",cb,(cb->cdata),(cb->nxb));
        printf("\n");
        cb=cb->nxb; // Approaching to the next block using tail //
    }
}
