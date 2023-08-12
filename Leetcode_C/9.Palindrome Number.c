#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void push (int x,int array[], int count){
    array[count] = x;
}
int pop (int array[] ,int count){
    int temp = array[count];
    return temp;
}
bool isPalindrome(int x){
    bool ans = false;
    if(x == 0){
        return true;
    }
    else if(x>0 || x<= 2147483637 && x>0){
        int temp = x, k=0, i;
        int len = (int)log10(x) +1;
        int array[len];
        int array_x[len];

        for(i=len-1; i>=0; i--){
            int t = temp % 10;
            array_x[i] = t;
            temp = temp /10;
        }
        for(i=0; i<len/2; i++){
            push(array_x[i], array, i);
        }
        k = len/2-1;
        
        if(len % 2 != 0){
            k++;
        }

        for(i=k+1; i<len; i++){
            int top;
            if(len % 2 != 0){
                top = pop(array, --k);
            }
            else{
                top = pop(array, k--);
            }
            if(top != array_x[i]){
                return false;
            }
        }
        ans = true;
    }
    return ans;
}
int main(void){
	printf("判斷數字是否為回文 \n");
	printf("請輸入一個數字 : ");
	int x;
	scanf("%d",&x);
	int ans = isPalindrome(x);
	if(ans == 1){
		printf("true");
	}
	else{
		printf("false");
	} 
}
