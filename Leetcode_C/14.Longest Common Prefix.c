#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char * longestCommonPrefix(char ** strs, int strsSize){
    int min=strlen(strs[0]);
    int index=0;
    char* temp;
    int i,j;
    for(i=1;i<strsSize;i++)
    {
        if(strlen(strs[i])<min)
        {
            min=strlen(strs[i]);
            index=i;
        }
    }
    temp = strs[index];
    for(i=0;i<min;i++)
    {
        char word=temp[i];      
        for(j=0;j<strsSize;j++)
        {
            if(strs[j][i]!=word)
            {
            	
                temp[i]='\0';
            }
        }
    }
    return temp;
}
int main(void){
	printf("輸入一個字串陣列的長度 : ");
	int len;
	scanf("%d",&len);
	
	char* strs[len];
	char temp[len][200];
	int i;

	for(i=0; i<len; i++){
		printf("輸入字串 : ");
		scanf("%s",temp[i]);
		strs[i] = temp[i];
	}

	
	char * ans = longestCommonPrefix(strs,len);
	for(i=0; i<strlen(ans); i++){
		printf("%c",*(ans+i));
	}
}

