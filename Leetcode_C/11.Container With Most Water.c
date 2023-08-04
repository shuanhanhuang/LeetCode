#include<stdio.h>
#include<stdlib.h> 
int maxArea(int* height, int heightSize){
    int left = 0 ,right = heightSize-1;
    int area = 0;
    while(left<right){
//        printf("%d,%d\n",left,right);
        if(height[left]<=height[right] ){
            if((right-left) * height[left]>area){
                area = (right-left) * height[left];
            }
            left = left + 1;
        }
        else if(height[left]>height[right] ){
            if((right-left) * height[right]>area){
                area = (right-left) * height[right];
            }
            right = right - 1;
        }

    }
    
    return area;
}

int main(void){
	printf("請輸入陣列數字：");
	int len;
	scanf("%d",&len);
	int height[len];
	int i,h;
	for(i=0; i<len; i++){
		scanf("%d",&h);
		height[i] = h;
	}
	int ans = maxArea(height,len);
	printf("最大面積 :　%d",ans);
}
