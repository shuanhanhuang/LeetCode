#include<stdio.h>
#include<stdlib.h>
int removeDuplicates(int* nums, int numsSize){
    int i,j;
    int count = 1;
    for(i=0; i<numsSize-1; i++){
        if(nums[i] != nums[i+1]){
            nums[count] = nums[i+1];
            count++;
        }
    }
    return count;
    
}
int main(void){
	printf("找出陣列中不重複的數字 : 陣列大小是多少 --> ");
	int len,i;
	scanf("%d",&len);
	int nums[len];
	printf("輸入 %d 個數字: ",len);
	for(i=0; i<len; i++){
		scanf("%d",&nums[i]);
	}

	
	printf("nums : ");
	for(i=0; i<len; i++){
		printf("%d ",nums[i]);
	}
	
	int count = removeDuplicates(nums,len);
	printf("\nnums 非重複值有%d個",count);
	
	int j;
	printf("\nnums 非重複的值為 : ");
	for(j=0; j<count; j++){
		printf("%d ",nums[j]);
	}
}

