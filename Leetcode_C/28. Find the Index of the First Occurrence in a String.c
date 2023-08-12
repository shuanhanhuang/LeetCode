#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strStr(char * haystack, char * needle){
    int ans = -1,i;
    if(strlen(haystack) == strlen(needle)){
        for(i=0;i<strlen(haystack); i++){
            if(haystack[i] != needle[i]){        
                return ans;
            }
        }
        ans = 0;
    }
    else if(strlen(haystack) > strlen(needle)){
        for(i=0; i<=strlen(haystack)-strlen(needle); i++){
            char subtext[strlen(needle)+1];
            strncpy(subtext,&haystack[i],strlen(needle));
            subtext[strlen(needle)] = '\0';
            char *loc = strstr(subtext, needle);
            if(loc != NULL){
                ans = i;
                break;
            }
        }
    }
    
    return ans;
}
int main(void){
	char haystack[10000];
	char needle[10000];
	printf("輸入第一個字串 : ");
	scanf("%s",haystack);
	printf("輸入搜尋欲字串 : ");
	scanf("%s",needle);
	int ans = strStr(&haystack,&needle);
	if(ans == -1){
		printf("沒有搜尋到 %s",needle); 
	}
	else{
		printf("在 index%d 的地方有搜尋到 %s",ans,needle);
	}
}
