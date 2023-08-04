package Leetcode;

import java.util.Scanner;

public class Integer_to_Roman {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("將阿拉伯數字轉換為羅馬數字");
		System.out.print("請輸入一個數字(最大為3999) : ");
		int num = input.nextInt();
		String ans = intToRoman(num);
		System.out.print("轉換成羅馬數字 : ");
		System.out.printf("%s",ans);
	}
	public static String intToRoman(int num) {
        String ans = "";
        int temp = num, c;
        int len = (int)Math.log10(num) + 1;
        int count = len;
        int size = 4 - len;
        while(size<4){
            c = temp / (int)Math.pow(10,count-1);

            temp = temp % (int)Math.pow(10,count-1);

            if(size == 0){
                for(int i=1; i<=c; i++){
                    ans = ans + "M";
                }
            }
            else if(size == 1){
                if(c >= 5){
                    if(c == 9){
                        ans = ans + "CM";
                    }
                    else{
                        ans = ans + "D";
                        for(int i=0; i<c-5; i++){
                            ans = ans + "C";
                        }
                    }
                }
                else{
                    if(c == 4){
                        ans = ans +"CD";
                    }
                    else{
                        for(int i=0; i<c; i++){
                            ans = ans + "C";
                        }
                    }
                }
            }
            else if(size == 2){
                if(c >= 5){
                    if(c == 9){
                        ans = ans + "XC";
                    }
                    else{
                        ans = ans + "L";
                        for(int i=0; i<c-5; i++){
                            ans = ans + "X";
                        }
                    }
                }
                else{
                    if(c == 4){
                        ans = ans +"XL";
                    }
                    else{
                        for(int i=0; i<c; i++){
                            ans = ans + "X";
                        }
                    }
                }

            }
            else{
                if(c >= 5){
                    if(c == 9){
                        ans = ans + "IX";
                    }
                    else{
                        ans = ans + "V";
                        for(int i=0; i<c-5; i++){
                            ans = ans + "I";
                        }
                    }
                }
                else{
                    if(c == 4){
                        ans = ans +"IV";
                    }
                    else{
                        for(int i=0; i<c; i++){
                            ans = ans + "I";
                        }
                    }
                }
            }
            size ++;
            count --;
        }
        return ans;
    }

}
