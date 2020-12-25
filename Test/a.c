#include<stdio.h>

int main(){
	char a[100] = {0,};
	char an[26] = {0,};
	scanf("%s",a);
	int i=0;
	while(1){
		if(a[i] == 0)
			break;
		int num = a[i]-97;
		if(an[num] == 0)
			an[num] = i;
		
		i++;
	}
	for(int i=0;i<26;i++){
		printf("%d ",an[i]);
	}
	printf("\n");
}