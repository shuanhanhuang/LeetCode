#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char* intToRoman(int num){
	int temp = num, c, num_temp = num;
	int len = 0,i;

	int ans_index = 0;
	char* ans1 = (char*) malloc (sizeof(char)*20);
	while(num_temp > 0){
		len = len + 1;
		num_temp = num_temp / 10; 
	}

	int count = len;
	int size = 4 - len;
	while(size < 4){
		c = temp / (int)pow(10,count-1);
		printf("c: %d\n",c);
		temp = temp % (int)pow(10,count-1);
		printf("temp: %d\n",temp);
		printf("size: %d\n",size);
		if(size == 0){
			for(i=1; i<=c; i++){
				ans1[ans_index] = 'M';
				ans_index++;
			}
		}
		else if(size == 1){
			if(c >= 5){
                if(c == 9){
                    ans1[ans_index] = 'C';
                    ans_index++;
                    ans1[ans_index] = 'M';
                    ans_index++;
                }
                else{
                    ans1[ans_index] = 'D';
                    ans_index++;
                    for(i=0; i<c-5; i++){
                        ans1[ans_index] = 'C';
                        ans_index++;
                    }
                }
            }
            else{
                if(c == 4){
                    ans1[ans_index] = 'C';
                    ans_index++;
                    ans1[ans_index] = 'D';
                    ans_index++;
				}
                else{
                    for(i=0; i<c; i++){
                        ans1[ans_index] = 'C';
                    	ans_index++;
					}
                }
            }
		}
		else if(size == 2){
			if(c >= 5){
                if(c == 9){
                    ans1[ans_index] = 'X';
                    ans_index++;
                    ans1[ans_index] = 'C';
                    ans_index++;
                }
                else{
                    ans1[ans_index] = 'L';
                    ans_index++;
                    for(i=0; i<c-5; i++){
                        ans1[ans_index] = 'X';
                        ans_index++;
                    }
                }
            }
            else{
                if(c == 4){
                    ans1[ans_index] = 'X';
                    ans_index++;
                    ans1[ans_index] = 'L';
                    ans_index++;
				}
                else{
                    for(i=0; i<c; i++){
                        ans1[ans_index] = 'X';
                    	ans_index++;
					}
                }
            }
		}
		else{
			if(c >= 5){
                if(c == 9){
                    ans1[ans_index] = 'I';
                    ans_index++;
                    ans1[ans_index] = 'X';
                    ans_index++;
                }
                else{
                    ans1[ans_index] = 'V';
                    ans_index++;
                    for(i=0; i<c-5; i++){
                        ans1[ans_index] = 'I';
                        ans_index++;
                    }
                }
            }
            else{
                if(c == 4){
                    ans1[ans_index] = 'I';
                    ans_index++;
                    ans1[ans_index] = 'V';
                    ans_index++;
				}
                else{
                    for(i=0; i<c; i++){
                        ans1[ans_index] = 'I';
                    	ans_index++;
					}
                }
            }
            
		}
		size++;
        count--;
		
	}
	ans1[ans_index] = '\0';

	return ans1; 
}

int main(void){
	printf("盢┰计锣传霉皑计\n");
	printf("叫块┰计 (程3999) : ");
	int num,i;
	scanf("%d",&num);
	char* ans = intToRoman(num);

	for(i=0; i<strlen(ans); i++){
		printf("%c",*(ans+i));
	}
	
}
