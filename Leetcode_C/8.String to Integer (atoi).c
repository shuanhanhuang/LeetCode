#include<stdio.h>
#include<stdlib.h>
int myAtoi(char * s){
    if(strlen(s) == 0){
        return 0;
    }
    int index = 0;
    int y = 0;
    int some = 0;
    char *word = (char*)malloc((strlen(s)+1)*sizeof(char));
    int i;
    for(i=0;i<strlen(s);i++){
        
        if((int)s[i] >=48 && (int)s[i]<=57){
            word[index] = s[i];
            index = index + 1;
        }
        
        else if((int)s[i] == 32 && index == 0 && some ==0){
            index = index + 0;
        }
        else if((int)s[i] == 45 && some == 0 && index ==0){
            some = -1;
        }
        else if((int)s[i] == 43 && some == 0 && index ==0){
            some = 1;
        }
        else{
            if(index == 0){
                return 0;
            }
            else{
                i=strlen(s);
            }
        }
    }
    if(some == 0){
        some = 1;
    }
    word[index] = '\0';
    int j = 0 ;
    int first = 0;
    while(j<index){
        
        first = some*((int)word[j]-48);
        if(y > INT_MAX/10){
            return INT_MAX;
        }
        else if(y< INT_MIN/10){
            return INT_MIN;
        }
        else if(y == INT_MAX/10 || y == INT_MIN/10){
            if(first >7){
                return INT_MAX;
            }
            else if(first<-8){
                return INT_MIN;
            }
        }
        
        y = y*10 + first ;
        
        j = j + 1;
    }
    return y;
}
int main(void){
	printf("�N��J���r���ഫ���Ʀr -> ��J�@�Ӧr��:");
//	1. �ھ� + �� - �M�w�Ʀr�̫�O�����٬O�t��
//  2. ��r��J��D�Ʀr�h����᭱���r��
//  3. �p�G�r�곣�S���Ʀr�h��X0
//  4. �j�� INT_MAX(2147483647) �h��X 2147483647  �A �p��INT_MIN(-2147483648) �h��X -2147483648
	char s[80] = "";
	
	scanf("%s",&s);
	
//	int i;
//	for(i=0; i<len; i++){
//		printf("%c",*(s+i));
//	}
	int ans = myAtoi(s);
	printf("%s �ഫ���Ʀr�ܦ� --> %d",s,ans);
}
