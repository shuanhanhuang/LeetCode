package Leetcode;

import java.util.*;
public class Zigzag_Conversion {
	public static void main(String[] args) {
	
		Scanner input = new Scanner(System.in);
		System.out.print("請輸入一個字串 : ");
		String s = input.nextLine();
		System.out.print("請輸入一個數字(要將字串分成幾列) : ");
		int numRows = input.nextInt();
		String ans = convert(s,numRows);
		System.out.printf("%s",ans);
	}
	public static String convert(String s, int numRows) {
        String ans = "";
        int input_len = s.length();
        if(numRows == 1 || input_len == 1 || input_len <= numRows){
            ans = s;
        }
        else{
            int sum = numRows + (numRows-2);
            int i,count=0;
            for(i=0; i<numRows; i++){
                ans = ans + s.substring(i,i+1);
                int j = i;
                if(i == numRows-1){
                    count = 0;
                }
                else{
                    count = i*2;
                }
                while(j+(sum-count) < input_len){
                    j = j + (sum-count);
                    ans = ans + s.substring(j,j+1);
                    if(i == 0 || i == numRows - 1){
                        count = 0;
                    }
                    else{
                        count = sum - count;
                    }
                }
            }
        }

        return ans;
    }
}
