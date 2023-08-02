#include<stdio.h>
#include<stdlib.h>
int lengthOfLongestSubstring(char * s){
    int ht[127];
    int i;
    //int *ht=(int*)malloc(128*sizeof(int)),i;
    for(i=0;i<127;i++){
        ht[i]=-1; //������l�Ʀ�-1
    }
    int max=0,strsize=strlen(s),substring_start=0;
    for(i=0;i<strsize;i++){
        if((ht[s[i]])>=substring_start){ //�b�l�r��̤F
            substring_start=ht[s[i]]+1;
            ht[s[i]]=i;
        }
        else{  //���b�l�r���
            ht[s[i]]=i;
            if(i-substring_start+1>max)max=i-substring_start+1;
        }
    }
    return max;
}
int main(void){

	char s[]=""; 
	scanf("%s",&(s)); 

	int ans = lengthOfLongestSubstring(s);
	printf("%d",ans);
}
