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
//        �קK�X�{�ۤϫᬰ2147483648�B 2147483649�B-2147483649
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
	printf("�ۤϿ�J���Ʀr-> �п�J�@�ӼƦr:");
	int x;
	scanf("%d",&x);
	int ans = reverse(x);
	printf("%d �ۤϫᬰ %d",x,ans);
}
