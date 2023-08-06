#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int val;
	struct Node* next;
}node, *ListNode;
ListNode mergeTwoLists(ListNode list1, ListNode list2){
    ListNode list3, prev;
    list3=(ListNode)malloc(sizeof(node));
    
    list3->val=0;
    list3->next=NULL;

    prev=list3;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->val<=list2->val)
        {
            prev->next=list1;
            list1=list1->next;
        }
        else
        {
            prev->next=list2;
            list2=list2->next;
        }
        prev=prev->next;
    }
    if(list1!=NULL)
    {
        prev->next=list1;
    }
    if(list2!=NULL)
    {
        prev->next=list2;
    }
    

    //list3=list1->next;
    
    return list3->next;
}
int main(void){
	printf("輸入要建立多長的 list1: ");
	int len_list1,len_list2,i,num,n;
	scanf("%d",&len_list1);
	
	ListNode a,ans;
	ListNode head_list1 = NULL;
	ListNode temp_list1 = NULL;
	ListNode head_list2 = NULL;
	ListNode temp_list2 = NULL;
	
	
	for(i=0; i<len_list1; i++){
		printf("輸入 list1 第 %d 數字 : ",i+1);
		scanf("%d",&num);
		a = (ListNode)malloc(sizeof(node));
		a->val = num;
		a->next = NULL;
		if(head_list1 != NULL){	
			head_list1-> next = a;	
		}
		else{
			temp_list1 = a;
		}		
		head_list1 = a;
		
	}
	printf("輸入要建立多長的 list1: ");
	scanf("%d",&len_list2);
	
	for(i=0; i<len_list2; i++){
		printf("輸入 list2 第 %d 數字 : ",i+1);
		scanf("%d",&num);
		a = (ListNode) malloc(sizeof(node));
		a->val = num;
		a->next = NULL;
		if(head_list2 != NULL){	
			head_list2-> next = a;	
		}
		else{
			temp_list2 = a;
		}		
		head_list2 = a;
		
	}
	ans = mergeTwoLists(temp_list1,temp_list2);
	printf("\n合併後的linked-list : ");
	while(ans != NULL){
		printf("%d ",ans->val);
		ans = ans->next;
	}
	
}
