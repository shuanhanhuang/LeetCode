#include<stdio.h>
#include<stdlib.h>
int cmp(int *a, int* b)
{ 
    return *a-*b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 4)
    {
        *returnSize = 0;
        return NULL;
    }
    int MALLOC_SIZE_UNIT = 8;
    qsort(nums, numsSize, sizeof(int), cmp);

    returnColumnSizes = (int **)malloc(sizeof(int*) * MALLOC_SIZE_UNIT);
    int ansSize = 0,i,j; 
    long tmpTarget, sum;
	
    for(i=0; i<numsSize-3; i++)
    {
        if (i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        
        tmpTarget = target - nums[i];
         
        for(j=i+1; j<=numsSize-3; j++)
        {
            if (j > (i+1) && nums[j] == nums[j-1])
            {
                continue; 
            }
            
            sum = tmpTarget - nums[j];

            int k = j+1;
            int l = numsSize-1;
            while (k < l)
            {
                if (nums[k] + nums[l] == sum)
                {
                    returnColumnSizes[ansSize] = (int *)malloc(sizeof(int) * 4);
                    returnColumnSizes[ansSize][0] = nums[i];
                    returnColumnSizes[ansSize][1] = nums[j];
                    returnColumnSizes[ansSize][2] = nums[k];
                    returnColumnSizes[ansSize][3] = nums[l];
                    ansSize++;
                    if (ansSize == MALLOC_SIZE_UNIT)
                    {
                        MALLOC_SIZE_UNIT = MALLOC_SIZE_UNIT  * 2;
                        returnColumnSizes = (int **)realloc(returnColumnSizes, sizeof(int *) * MALLOC_SIZE_UNIT);
                    }
                    k++;
                    l--;
                    while(k<l && nums[l]==nums[l+1] ){
                        l--;
                    }
    
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                } 
                else if (nums[k] + nums[l] < sum)
                {
                    k++;
                } 
                else
                {
                    l--;
                }
            }
        }
    }
	
    *returnSize = ansSize;
    return returnColumnSizes;
}
int main(void){
	
//	指標建立 -- 動態配置(malloc): https://edisonshih.pixnet.net/blog/post/27974938
//	https://ithelp.ithome.com.tw/questions/10197771

	printf("輸入要輸入幾個數字(陣列大小) : ");
	int numsSize;
	scanf("%d",&numsSize);
	printf("輸入 %d 個數字 : ",numsSize);
	int nums[numsSize];
	int i,j;
	for(i=0; i<numsSize; i++){
		scanf("%d",&nums[i]);
	}
	
	printf("輸入目標數字 : ");
	int target;
	scanf("%d",&target);
	
	int size = 0;
	int **returnColumnSizes;
	int** answer = fourSum(nums, numsSize, target, &size,returnColumnSizes);

	printf("answer : \n");
	for(i=0; i<size; i++){
		printf("[");
    	for(j=0; j<4; j++){
    		printf("%d ", *(*(answer+i)+j)); 
		}
		printf("]");
		printf(" ");
	}
	free(returnColumnSizes);
	
}
