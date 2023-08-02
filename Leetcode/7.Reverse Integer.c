#include<stdio.h>
#include<stdlib.h>
//INT_MAX = 2147483647 
//INT_MIN = -2147483648
int reverse(int x){
    int answer =0;
    
    while(x != 0){

        if(answer > 2147483647/10 || answer < INT_MIN/10){
            return 0;
        }
//        避免出現相反後為2147483648、 2147483649、-2147483649
        else if(answer == INT_MAX/10 || answer == INT_MIN/10){
            if(x%10>7||x%10<-8){
            	return 0;
			}
        }
        answer = answer*10 + x%10;
        x = x/10;
    }

    
    return answer;
}

int main(void){
	printf("相反輸入的數字-> 請輸入一個數字:");
	int x;
	scanf("%d",&x);
	int ans = reverse(x);
	printf("%d 相反後為 %d",x,ans);
}
