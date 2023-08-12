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
	printf("�R���}�C�����w���Ʀr�A�ñN�ѤU���Ʀr�q Index0 �}�l��\n");
	printf("��J�}�C���j�p : ");
	int numsSize, i, a, val;
	
	scanf("%d",&numsSize);
	int nums[numsSize];
	printf("��J %d �ӼƦr : ",numsSize);
	for(i=0; i<numsSize; i++){
		scanf("%d",&a);
		nums[i] = a;
	}
	printf("��J�n�R�����Ʀr : ");
	scanf("%d",&val);
	removeElement(&nums, numsSize,val);
	for(i=0; i<numsSize; i++){
		printf("%d ",nums[i]);
	}
}
