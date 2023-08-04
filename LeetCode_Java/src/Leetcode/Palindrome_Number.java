package Leetcode;

import java.util.Scanner;

public class Palindrome_Number {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("請輸入一個數字(判斷此數字是否回文) : ");
		int x = input.nextInt();
		boolean ans = isPalindrome(x);
		System.out.printf("%b",ans);
	}
    public static void push(int x,int[] array, int count){
        array[count] = x;
    }
    public static int pop(int[] array, int count){
        int temp = array[count];
        return temp;
    }
    public static boolean isPalindrome(int x) {
        boolean ans = false;

        if(x == 0){
            ans = true;
        }
        else if(x>0 || x<= 2147483637 && x>0){
            int temp = x, k = 0;
            int len = (int)Math.log10(x) + 1;
            int[] array = new int[len];
            int[] array_x = new int[len];

            for(int i=len-1; i>=0; i--){
                int t = temp % 10;
                array_x[i] = t;
                temp = temp / 10;
            }
            for(int i=0; i<len/2; i++){
                push(array_x[i],array,i);
            }
            k = len/2-1;

            if(len % 2 != 0){
                k++;
            }

            for(int i=k+1; i<len; i++){
                int top;
                if(len % 2 != 0){
                    top = pop(array, --k);
                }
                else{
                    top = pop (array, k--);
                }
                if(top != array_x[i]){
                    return false;
                }
            }
            ans = true;
        }
        return ans;
    }

}
