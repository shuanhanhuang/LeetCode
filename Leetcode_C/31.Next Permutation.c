#include<stdio.h>
#include<stdlib.h>
int cmp(int *a, int *b)
{
    return *a - *b;
}
void nextPermutation(int* nums, int numsSize){
    int max = -1,i;

    for(i=0; i<numsSize-1; i++){
        if(nums[i] < nums[i+1]){
            if(max != -1){
                max = i + 1;
            }
        }
        else{
            if(max == -1){
                max = i;
            }
        }
    }

    if(max == -1){
        max = numsSize-1;
    }
    if(max == 0){
        qsort(nums, numsSize, sizeof(int), cmp);

    }
    else if(max == numsSize-1){
        int temp = nums[max];
        nums[max] = nums[max-1];
        nums[max-1] = temp;
    }
    else{
        int close = nums[max] - nums[max-1];
        int t = max;
        for(i=max+1; i<numsSize; i++){
            if(nums[i] > nums[max-1]){
                if(nums[i] - nums[max-1] < close){
                    t = i;
                }
            }
        }
        int temp = nums[t];
        nums[t] = nums[max-1];
        nums[max-1] = temp;
        qsort(nums+max, numsSize-max, sizeof(int), cmp);

    }

}
int main(void){
	printf("輸入陣列的大小 : ");
	int numsSize, i, a;
	
	scanf("%d",&numsSize);
	int nums[numsSize];
	printf("輸入 %d 個數字 : ",numsSize);
	for(i=0; i<numsSize; i++){
		scanf("%d",&a);
		nums[i] = a;
	}
	nextPermutation(&nums,numsSize);
	for(i=0; i<numsSize; i++){
		printf("%d ",*(nums+i));
	}
}
