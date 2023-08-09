package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class FourSum {
	public static void main(String[] args) {
		System.out.printf("請輸入陣列大小 : ");
		Scanner input = new Scanner(System.in);
		int len = input.nextInt();
		int[] nums = new int[len];
		System.out.printf("請輸入 %d 個數字: ",len);
		for(int i=0; i<len; i++) {
			nums[i] = input.nextInt();
		}
		System.out.printf("請輸入加總的目標總和 : ");
		int target = input.nextInt();
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
		ans = fourSum(nums,target);
		for(int i=0; i<ans.size(); i++) {
			System.out.println(Arrays.toString(ans.get(i).toArray()));
		}
		
	}
	public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
        if(nums==null|| nums.length<4){
            return ans;
        }
            
        Arrays.sort(nums);
    
        for(int i=0; i<nums.length-3; i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            } 
            for(int j=i+1; j<nums.length-2; j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                } 
                int k=j+1;
                int l=nums.length-1;
                while(k<l){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else if(sum == target){
                        List<Integer> t = new ArrayList<Integer>();
                        t.add(nums[i]);
                        t.add(nums[j]);
                        t.add(nums[k]);
                        t.add(nums[l]);
                        ans.add(t);
    
                        k++;
                        l--;
    
                        while(k<l && nums[l]==nums[l+1] ){
                            l--;
                        }
    
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                    }

                }
            }
        }
    
        return ans;
    } 
}
