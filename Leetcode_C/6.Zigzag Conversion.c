#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char * convert(char * s, int numRows){
	int input_len = strlen(s), c=0,i;
	char* ans = (char*) malloc (sizeof(char) * input_len);

    if(numRows == 1 || input_len == 1 || input_len <= numRows){
        ans = s;
        return ans;
    }
    else{
        int sum = numRows + (numRows-2);
        int i,count=0;
        for(i=0; i<numRows; i++){
            ans[c] = s[i];
            c++;
            int j = i;
            if(i == numRows-1){
                count = 0;
            }
            else{
                count = i*2;
            }
            while(j+(sum-count) < input_len){
                j = j + (sum-count);
                ans[c] = s[j];
                c++;
                if(i == 0 || i == numRows - 1){
                    count = 0;
                }
                else{
                    count = sum - count;
                }
            }
        }
        ans[c] ='\0';
        return ans;
    }
}
int main(void){
	printf("字串排列轉換\n");
	printf("請輸入一個字串 : ");
	char temp[1000] = "";
	char* s;
	
	scanf("%s",temp);
	s = temp;
	printf("請輸入要轉換的排列數 : ");
	int numRows;
	scanf("%d",&numRows);
	char* ans = convert(s,numRows);
	int i;
	for(i=0; i<strlen(ans); i++){
		printf("%c",*(ans+i));
	}
	free(s);
	free(ans);
	
}
