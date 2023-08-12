int cmp(int* a,int* b){
    return *a - *b;
}
int removeElement(int* nums, int numsSize, int val){
    int count = 0, temp = 0, i;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(i=0; i<numsSize; i++){
        if(nums[i] == val){
            if(count == 0){
                temp = i;
            }
            count ++;
        }
        else if(nums[i] > val){
            break;
        }
    }
    // printf("temp:%d, temp+count:%d\n",temp,temp+count);
    for(i=temp; i<numsSize; i++){
        if(i+count < numsSize){
            nums[i] = nums[i+count];
        }
        else{
            break;
        }
    }

    return numsSize - count;
}
int main(void){
	printf("刪除陣列中指定的數字，並將剩下的數字從 Index0 開始排\n");
	printf("輸入陣列的大小 : ");
	int numsSize, i, a, val;
	
	scanf("%d",&numsSize);
	int nums[numsSize];
	printf("輸入 %d 個數字 : ",numsSize);
	for(i=0; i<numsSize; i++){
		scanf("%d",&a);
		nums[i] = a;
	}
	printf("輸入要刪除的數字 : ");
	scanf("%d",&val);
	removeElement(&nums, numsSize,val);
	for(i=0; i<numsSize; i++){
		printf("%d ",nums[i]);
	}
}
