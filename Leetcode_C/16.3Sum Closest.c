int cmp(int *a, int *b){
    return *a - *b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 99999;
    int sum = 0;
    int i;
    for(i=0; i<numsSize-2; i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        else{
            int j = i+1;
            int k = numsSize-1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(ans-target)){
                    ans = sum;
                }
                if(sum > target){
                    // printf("bbb\n");
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    break;
                }
            }
        }
        
    }

    return ans;
}
int main(void){
	printf("找出陣列中和目標數字最接近的總和 : 陣列大小是多少 --> ");
	int len,i;
	scanf("%d",&len);
	int nums[len];
	printf("輸入 %d 個數字: ",len);
	for(i=0; i<len; i++){
		scanf("%d",&nums[i]);
	}
	
	printf("輸入一個目標數字 : ");
	int targets;
	scanf("%d",&targets);
	int ans = threeSumClosest(nums, len, targets);
	printf("ans: %d",ans);
	
	
}
