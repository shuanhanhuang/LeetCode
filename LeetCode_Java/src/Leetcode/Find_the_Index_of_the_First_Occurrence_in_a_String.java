package Leetcode;

import java.util.Scanner;

public class Find_the_Index_of_the_First_Occurrence_in_a_String {
	public static void main(String[] args) {
		System.out.printf("請輸入第一個字串 : ");
		Scanner input = new Scanner(System.in);
		String haystack = input.nextLine();
		System.out.printf("請輸入想查詢的字串 : ");
		String needle = input.nextLine();
		int ans = strStr(haystack,needle);
		if(ans != -1) {
			System.out.printf("can find , index from %d to %d",ans,ans+needle.length()-1 );
		}
		else {
			System.out.printf("can't find");
		}
		
		
	}
	public static int strStr(String haystack, String needle) {
        int ans = -1;
        if(haystack.equals(needle)){
            ans = 0;
        }
        for(int i=0; i<=haystack.length()-needle.length(); i++){
            if(haystack.substring(i, i+needle.length()).equals(needle)){
                ans = i;
                break;
            }
        }
        return ans;
    }
}
