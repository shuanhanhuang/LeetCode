#include<stdio.h>
#include<stdlib.h>
//typedef struct listnode* ListNode;
typedef struct ListNode {
	int data;
	struct ListNode* next;
}node,*nodeptr;
nodeptr removeNthFromEnd(nodeptr head, int n);
int main(void){
	printf("輸入要建立多長的linked list : ");
	int len,i,num,n;
	scanf("%d",&len);
	
	nodeptr a,ans;
	nodeptr head = NULL;
	nodeptr temp = NULL;
	
	
	for(i=0; i<len; i++){
		printf("輸入數字 : ");
		scanf("%d",&num);
		a = (nodeptr) malloc(sizeof(node));
		a->data = num;
		a->next = NULL;
		if(head != NULL){	
			head-> next = a;	
		}
		else{
			temp= a;
		}		
		head = a;
		
	}

	printf("請輸入要刪除倒數第幾個node : ");
	scanf("%d",&n);
	
	ans = removeNthFromEnd(temp,n);
	printf("\n刪除後的linked-list : ");
	while(ans != NULL){
		printf("%d ",ans->data);
		ans = ans->next;
	}
}
nodeptr removeNthFromEnd(nodeptr head, int n){
    int count = 0;
    int index = 1;
    nodeptr p = head;
    nodeptr temp = head;
    int i;
    while(p != NULL){
        count = count + 1;
        p = p->next;
    }

    if(n == 1){
        if(count == 1){
            temp = NULL;
        }
        else{
            for(i=0; i<count-2;i++){
                    head = head->next;
            }
            head->next = NULL;
        }
        
    }
    else if(n == count){
        temp = head->next; 
    }
    else{
        while(head != NULL){
            if(index == count-n){
                head->next = head->next->next;
            }
            head = head->next; 
            index = index+1;
            
        }
    }

	
    return temp;
}


