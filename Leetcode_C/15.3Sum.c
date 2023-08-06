#include<stdio.h>
#include<stdlib.h>

 int cmp(int *a, int *b)
 {
     return *a - *b;
 }
int** threeSum(int *nums, int numsSize, int *returnSize, int**returnColumnSizes)
{
	int rstSize = 0;
    int basicSize = 8;
    
//	�����ܼ� = (�����ܼƩҫ��V�����A *) malloc(�һݪ��O�ЪŶ�)
//	(�����ܼƩҫ��V�����A *) �N���N�q�O�Nmalloc()�ҶǦ^����}�j���ഫ�������ܼƩҫ��V�����A	
    returnColumnSizes = (int **)malloc(sizeof(int*) * basicSize);
    
    int i, j, k, sum;
    
	// qsort �Ϊk : http://tw.gitbook.net/c_standard_library/c_function_qsort.html
    qsort(nums, numsSize, sizeof(int), cmp);
	
    for (i = 0; i < numsSize - 1; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
  
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
//				�ʺA�t�m�s��int���c�B�T�Ӿ�ƪ��Ŷ��A��O�����}�O���breturnColumnSizes[rstSize]
                returnColumnSizes[rstSize] = (int *)malloc(sizeof(int) * 3);
                returnColumnSizes[rstSize][0] = nums[i];
                returnColumnSizes[rstSize][1] = nums[j];
                returnColumnSizes[rstSize][2] = nums[k];
                rstSize++;

                while (j < k && nums[j] == nums[j + 1]) {
                    j++;
                }
                j++;
                k--;

                if (rstSize == basicSize) {
                    basicSize *= 2;
                    returnColumnSizes = (int **)realloc(returnColumnSizes, sizeof(int *) * basicSize);
				}

            } 
			else if (sum > 0) {
                k--;
            } 
			else {
                j++;
            }
        }
    }

    *returnSize = rstSize;

    return returnColumnSizes;

}
int main(void){
	
//	���Ыإ� -- �ʺA�t�m(malloc): https://edisonshih.pixnet.net/blog/post/27974938
//	https://ithelp.ithome.com.tw/questions/10197771
	printf("��J�n��J�X�ӼƦr(�}�C�j�p) : ");
	int numsSize;
	scanf("%d",&numsSize);
	printf("��J %d �ӼƦr : ",numsSize);
	int nums[numsSize];
	int i,j;
	for(i=0; i<numsSize; i++){
		scanf("%d",&nums[i]);
	}
	
	int size = 0;
	int* returnSize = &size;
	int **returnColumnSizes;
	int** answer = threeSum(nums, numsSize, returnSize,returnColumnSizes);

	printf("answer : \n");
	for(i=0; i<*returnSize; i++){
		printf("[");
    	for(j=0; j<3; j++){
    		printf("%d ", *(*(answer+i)+j)); 
		}
		printf("]");
		printf(" ");
	}
	free(returnColumnSizes);
	
}
