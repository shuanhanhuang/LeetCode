#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<stdbool.h>
bool isValid(char * s){
    char stack[5000];
    int top = 0,i;
    for(i = 0;i<strlen(s);i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            stack[top] = s[i];
            top++;
        }
        else if(s[i] == ')'){
            if(top==0)
                return false;
            else if(stack[top-1] == '('){
                top--;
            }
            else{
                return false;
            }
        }
        else if(s[i] == ']'){
            if(top==0)
                return false;
            else if(stack[top-1] == '['){
                top--;
            }
            else{
                return false;
            }
        }
        else if(s[i] == '}'){
            if(top == 0)
                return false;
            else if(stack[top-1] == '{'){
                top--;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    if(top != 0)
        return false;
    
    return true;
    
}
int main(void){
//	printf("�P�_�r��O�_�^�� : �п�J�@�Ӧr��(�ȭ���j�A���B�p�A���B���A��) --> ");
	char temp[80];
	char* s;
	scanf("%s",temp);
	s = temp;
	bool ans = isValid(s);
	printf("%d",ans);
}
