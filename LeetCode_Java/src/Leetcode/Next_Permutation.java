package Leetcode;

import java.util.Arrays;
import java.util.Scanner;

public class Next_Permutation {
	public static void main(String[] args) {
		System.out.printf("請輸入陣列大小 : ");
		Scanner input = new Scanner(System.in);
		int len = input.nextInt();
		int[] nums = new int[len];
		System.out.printf("請輸入 %d 個數字: ",len);
		for(int i=0; i<len; i++) {
			nums[i] = input.nextInt();
		}
		int ans[] = nextPermutation(nums);
		for(int i=0; i<ans.length; i++) {
			System.out.printf("%d ", ans[i]);
		}
	}
	
	public static int[] nextPermutation(int[] nums) {
        int max = -1;
        for(int i=0; i<nums.length-1; i++){
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
            max = nums.length-1;
        }
        if(max == 0){
            Arrays.sort(nums);
        }
        else if(max == nums.length-1){
            int temp = nums[max];
            nums[max] = nums[max-1];
            nums[max-1] = temp;
        }
        else{
            int close = nums[max] - nums[max-1];
            int t = max;
            for(int i=max+1; i<nums.length; i++){
                if(nums[i] > nums[max-1]){
                    if(nums[i] - nums[max-1] < close){
                        t = i;
                    }
                }
            }
            int temp = nums[t];
            nums[t] = nums[max-1];
            nums[max-1] = temp;
            Arrays.sort(nums,max,nums.length);
        }
         return nums;
    }
}
