//Program for evaluating function in c language
#include<stdio.h>
#include<math.h>

float charToInt(char cno[]){
	int i,point=0;
	float no=0,s_no;
	for(i=0; cno[i] != 'e'; i++){
		if(cno[i] >= 48 && cno[i] <= 57){
			s_no = cno[i] - 48;
			no = no*10 + s_no;
			if(point!=0){
				point++;
			}
		}
		else if(cno[i] == '.'){
			point = 1;
		}
		
	}
	no = no / pow(10,point);
	return no;
}

float calc(float result,float temp_no,char op){
	if(op == '+'){
		result = result + temp_no;
	}
	
	else if(op == '-'){
		result = result - temp_no;
	}
	
	else if(op == '*'){
		result = result * temp_no;
		
	}
	
	else if(op == '/'){
		result = result / temp_no;
		
	}
	
	else{
		printf("Invalid Operator:%c",op);
		return 0;
	
	}
	return result;
}

float eval(char toCalc[] ,int length){
	int i , index=0, first_no=1;
	char get_no[100],last_op;
	float result,temp_no;
	for(i=0 ; i < length ; i++){
		if(toCalc[i] == ' ') continue;
		if( (toCalc[i] >= 48 && toCalc[i] <= 57) || toCalc[i] == '.' ) {
			get_no[index] = toCalc[i];
			index++;	
		}
		
		else{
			
			get_no[index] = 'e';
			index = 0;
			temp_no = charToInt(get_no);
			if(first_no == 1){
				result=temp_no;
				first_no = 0;
				last_op = toCalc[i];
			}
			else{
				result = calc(result,temp_no,last_op);
				last_op = toCalc[i];
			}
			
		}
		
		
		
		
	}
	get_no[index] = 'e';
	temp_no = charToInt(get_no);
	result = calc(result,temp_no,last_op);

	return result;
}


int main(){
	int i,n=15;
	float a=15.5,b=20.9;
	char arr[100];// = "5*6/9-68+58/74";
	char no_check[] = "126058e";
	
	puts("Enter the question:");
	gets(arr);
	
	//finding length of arr
	for(n=0;arr[n]!='\0';n++);
	
	
	printf("Question:");
	for(i=0;i<n;i++) printf("%c",arr[i]);
	printf("\n\n");
	
	
	printf("\nResult:%.6f",eval(arr,n));
	
	return 0;
}
