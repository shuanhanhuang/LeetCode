#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int index1;
char** ans;
void recurFun(char* temp, int index, int n, int close, int open, int max){

	if(close == n){
		temp[index] = '\0'; 
		ans = realloc(ans,sizeof(char*)* (index1+1));
		ans[index1] = (char*)malloc(sizeof(char)* (max+1));
		strcpy(ans[index1],temp);
		index1++;
		
	}
	else{
		if(open > close){
			temp[index] = ')';
			recurFun(temp, index+1,n, close+1, open, max);
		}
		if(open<n){
			temp[index] = '(';
			recurFun(temp, index+1,n, close, open+1, max); 
		}
		
	}
	
	
}
char** middleFun(int n,int* returnsize){
	int close = 0;
	int open = 0;
	int max = 2*n;
	int index = 0,i,j;
	index1 = 0;

	
	ans = (char**)malloc(sizeof(char*)* 2);
	char* temp = (char*)malloc(sizeof(char)* (max+1));
	recurFun(temp, index, n, close, open, max);
	*returnsize = index1;
	
	return ans;
}
int main(void){
	int n;
	printf("要產生幾個回文的括弧 : 請輸入一個數字 --> ");
	scanf("%d",&n);
	int returnsize = 0,i,j;
	
	char** ans1 = middleFun(n,&returnsize);
	
	for(i=0; i<returnsize; i++){
		for(j=0; j<n*2; j++){
			printf("%c",ans1[i][j]);
		}
		printf("\n");
	}
	
}
