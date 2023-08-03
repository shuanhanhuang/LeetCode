#include<stdio.h>
#include<stdlib.h>
//int index = 0;
//void transfer(int* temp,int** returnColumnSizes){
//	printf("returnColumnSizes11: %d\n",**returnColumnSizes);
//    returnColumnSizes[index] = (int*)malloc(sizeof(int)*3);
//    returnColumnSizes[index] = temp;
//    index ++;
//}
 int cmp(int *a, int *b)
 {
//     printf("%d,%d\n",*a,*b);
     return *a - *b;
 }
int** threeSum(int *nums, int numsSize, int *returnSize)
{
//    int **rst;
    int rst[][3]={};
    int rstSize = 0;
    int basicSize = 8;
    int i, j, k, sum;

    qsort(nums, numsSize, sizeof(int), cmp);
//    for(i=0; i<6; i++){
//    	printf("%d",*(nums+i));
//	}
	
    for (i = 0; i < numsSize - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        j = i + 1;
        printf("j: %d\n",j);

        k = numsSize - 1;
        printf("k: %d\n",k);
        while (j < k) {
        	printf("j: %d,k: %d",j,k);
            sum = nums[i] + nums[j] + nums[k];
            printf("sum: %d\n",sum);
            if (sum == 0) {
//            	printf("aaa1");
//                rst[0] = (int *)malloc(sizeof(int) * 3);
                rst[rstSize][0] = nums[i];
                rst[rstSize][1] = nums[j];
                rst[rstSize][2] = nums[k];
				printf("aaa");
                rstSize++;
//				printf("%d",rstSize);
                while (j < k && nums[j] == nums[j + 1]) {
                    j++;
                }
                j++;
                k--;

//                if (rstSize == basicSize) {
//                    basicSize *= 2;
//                    rst = (int **)realloc(rst, sizeof(int *) * basicSize);
//				}

            } 
			else if (sum > 0) {
				printf("sum>0\n");
                k--;
            } 
			else {
				printf("sum<0\n");
                j++;
            }
        }
    }

    *returnSize = rstSize;
    return rst;
}
int main(void){
	int nums[] = {-1,0,1,2,-1,-4};
	int numsSize = 6;
	int index1,tempindex;
	int size = 0;
	int* returnSize = &size;
//	int **returnColumnSizes;
	int** answer = threeSum(nums, numsSize, returnSize);

	printf("answer \n");
	for(tempindex=0; tempindex< *returnSize; tempindex++){
		for(index1 =0; index1<3; index1++){
 			printf("%d   ",answer[tempindex][index1]);
		}
		printf("\n");
	}
}
