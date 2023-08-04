#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode* Node;
struct ListNode{
	int val;
	Node next;
};
Node addTwoNumbers(Node l1, Node l2,Node l3){
//    ListNode Node;
    Node last, *head = 0;
    int count = 0;
    int num = 0;
    while(l1 !=NULL || l2 != NULL || count!= 0){ //count ¶i¦ì

        if(l1 !=NULL && l2 != NULL){
            num = l1->val + l2->val + count;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1 == NULL && l2 != NULL){
            num = l2->val + count;
            l2 = l2->next;
        }
        else if(l1 !=NULL && l2 == NULL){
            num = l1->val + count;
            l1 = l1->next;
        }
        else{
            num = count;
        }
        
        if(num>9){
            count = 1;
        }
        else{
            count = 0;
        }
//        Node l3;
//        l3 = (Node)malloc(sizeof(ListNode));
        l3-> val = num%10;
        l3-> next = NULL;
        if(head == NULL){
            head = l3;
        }
        else{
            last->next = l3;
        }
        last = l3;
    }

    l3 = head;

    return l3;
}
int main(void){
	Node l1;
	Node l2;
	Node l7;
	l1=(Node)malloc(sizeof(ListNode));
	l2=(Node)malloc(sizeof(ListNode));
	l7=(Node)malloc(sizeof(ListNode));
	l1->val = 2;
	l2->val = 4;
	l7->val = 3;
	l1->next = l2;
	l2->next = l3;
	l7->next = NULL;
	
	Node l4;
	Node l5;
	Node l6;
	l4=(Node)malloc(sizeof(ListNode));
	l5=(Node)malloc(sizeof(ListNode));
	l6=(Node)malloc(sizeof(ListNode));
	l4->val = 5;
	l5->val = 6;
	l6->val = 4;
	l4->next = l5;
	l5->next = l6;
	l6->next = NULL;
	
	Node first = l1;
	Node  second = l2;
	Node l3
	
	addTwoNumbers(&first,&second,l3);
}
