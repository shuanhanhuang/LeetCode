package Leetcode;

import java.util.Scanner;

public class Divide_Two_Integers {
	public static void main(String[] args) {
		System.out.printf("列印 被除數除以除數的商 不可以使用乘法、除法、取餘數\n");
		System.out.printf("輸入被除數 : ");
		Scanner input  = new Scanner(System.in);
		int dividend = input.nextInt();
		System.out.printf("輸入被除數 : ");
		int divisor = input.nextInt();
		int ans = divide(dividend, divisor);
		System.out.printf("%d", ans);
	}
	
	public static int divide(int dividend, int divisor) {
        int ans = 0;
        if(dividend == 0){
            ans = 0;
        }
        else if(divisor == 1){
            ans = dividend;
        }
        else if(divisor == -1){
            if(dividend > 0){
                ans = dividend - (dividend+dividend);
            }
            else if(dividend == -2147483648 || dividend == -2147483647){
                ans = 2147483647;
            }
            else{
                ans = dividend - (dividend+dividend);
            }
        }
        else if(dividend < 0 && divisor > 0){

            while(dividend + divisor <= 0){
                dividend = dividend + divisor;
                ans = ans + 1;
            }
            ans = ans - (ans + ans);
            
        }
        else if(dividend > 0 && divisor < 0){
            
            while(dividend + divisor >= 0){
                dividend = dividend + divisor;
                ans = ans + 1;
            }
            ans = ans - (ans + ans);
            
            
        }
        else if(dividend > 0 && divisor > 0){
            while(dividend >= divisor){
                dividend = dividend - divisor;
                ans = ans + 1;
            }
        }
        else{
            while(dividend <= divisor ){
                dividend = dividend - divisor; 
                ans = ans + 1; 
            }
        }
        
        return ans;

    }
	
}
