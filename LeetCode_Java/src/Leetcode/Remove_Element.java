package Leetcode;

import java.util.Arrays;
import java.util.Scanner;

public class Remove_Element {
	public static void main(String[] args) {
		System.out.printf("請輸入陣列大小 : ");
		Scanner input = new Scanner(System.in);
		int len = input.nextInt();
		int[] nums = new int[len];
		System.out.printf("請輸入 %d 個數字: ",len);
		for(int i=0; i<len; i++) {
			nums[i] = input.nextInt();
		}
		System.out.printf("請輸入想移除的數字 : ");
		int val = input.nextInt();
		int ans = removeElement(nums,val);
	}
	public static int removeElement(int[] nums, int val) {
		int count = 0, temp = 0;
        Arrays.sort(nums);
        for(int i=0; i<nums.length; i++){
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

        for(int i=temp; i<nums.length; i++){
            if(i+count < nums.length){
                nums[i] = nums[i+count];
            }
            else{
                break;
            }
        }
        
        for(int i=0; i<nums.length - count; i++) {
        	System.out.printf("%d ",nums[i]);
        }
        return nums.length - count;
	}

}
