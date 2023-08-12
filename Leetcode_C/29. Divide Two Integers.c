#include<stdio.h>
#include<stdlib.h>
int divide(int dividend, int divisor){
    int ans = 0;
    if(dividend == 0){
        ans = 0;
        return ans;
    }
    else if(divisor == 1){
        ans = dividend;
        return ans;
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
        return ans;
    }
    else if(dividend < 0 && divisor > 0){

        while(dividend + divisor <= 0){
            dividend = dividend + divisor;
            ans = ans + 1;
        }
        ans = ans - (ans + ans);
        return ans;
    }
    else if(dividend > 0 && divisor < 0){
        
        while(dividend + divisor >= 0){
            dividend = dividend + divisor;
            ans = ans + 1;
        }
        ans = ans - (ans + ans);
        
        return ans;
    }
    else if(dividend > 0 && divisor > 0){
        while(dividend >= divisor){
            dividend = dividend - divisor;
            ans = ans + 1;
        }
        return ans;
    }
    else{
        while(dividend <= divisor ){
            dividend = dividend - divisor; 
            ans = ans + 1; 
        }
        return ans;
    }
  
}
int main(void){
	printf("不使用乘法、除法、取餘數的運算元的前提下列印出商數 \n");
	printf("請輸入被除數 : ");
	int dividend, divisor;
	scanf("%d",&dividend);
	printf("請輸入除數 : ");
	scanf("%d",&divisor);
	int ans = divide(dividend, divisor);
	printf("%d",ans);
}
