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
	printf("��X�}�C�������ƪ��Ʀr : �}�C�j�p�O�h�� --> ");
	int len,i;
	scanf("%d",&len);
	int nums[len];
	printf("��J %d �ӼƦr: ",len);
	for(i=0; i<len; i++){
		scanf("%d",&nums[i]);
	}

	
	printf("nums : ");
	for(i=0; i<len; i++){
		printf("%d ",nums[i]);
	}
	
	int count = removeDuplicates(nums,len);
	printf("\nnums �D���ƭȦ�%d��",count);
	
	int j;
	printf("\nnums �D���ƪ��Ȭ� : ");
	for(j=0; j<count; j++){
		printf("%d ",nums[j]);
	}
}

