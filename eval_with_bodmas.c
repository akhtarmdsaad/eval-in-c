//Program for evaluating function in c language
#include<stdio.h>
#include<math.h>

void printFloat(float arr[],int size){
	//Debugging
	return;
	int i = 0;
	printf("Printing int array ----\n");
	for(i=0;i<size;i++){
		printf("%.5f ",arr[i]);
	}
	printf("\nPrinting int array --ended\n");
}

void printChar(char arr[],int size){
	//Debugging
	return;
	int i = 0;
	printf("Printing char array ----\n");
	for(i=0;i<size;i++){
		printf("%c ",arr[i]);
	}
	printf("\nPrinting char array --ended\n");
}
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

void delFloat(float nos[], float toDelete,int size){
	int i,deleted=0;
	for(i = 0; i < size; i++){
		
		if(deleted==1){
			nos[i] = nos[i+1];
		}
		else if(nos[i]==toDelete){
			deleted=1;
			nos[i] = nos[i+1];
		}
		
	}
	nos[i] = '\0';
}
void delFloatIndex(float nos[], int index,int size){
	int i;
	for(i = index; i < size; i++){
		nos[i] = nos[i+1];
		
	}
	nos[i] = '\0';
}
void delChar(char nos[], char toDelete,int size){
	int i,deleted=0;
	for(i = 0; i < size; i++){
		
		if(deleted==1){
			nos[i] = nos[i+1];
		}
		else if(nos[i]==toDelete){
			deleted=1;
			nos[i] = nos[i+1];
		}
		
	}
	nos[i] = '\0';
}
void delCharIndex(char nos[], int index,int size){
	int i;
	for(i = index; i < size; i++){
		nos[i] = nos[i+1];
		
	}
	nos[i] = '\0';
}
void printExpression(float nos[], char ops[],int size){
	
	//Debugging
	return;
	int i;
	printf("Expression:");
	for(i=0;i<size;i++){
		printf("%0.5f %c ",nos[i],ops[i]);
	}
	printf("%0.5f\n",nos[i]);
}


float bodmas_calculator(float nos[], char ops[],int size){
	int i=0;
	float result;
	float calc(float result,float temp_no,char op);
	printChar(ops,size);
//	printf("\nSize-%d",size);
	//Divide
	for(i=0;i<size;i++){
		if(ops[i] == '/'){
			result = calc(nos[i],nos[i+1],'/');
			delFloatIndex(nos,i,size);
			delCharIndex(ops,i,size);
			nos[i] = result;
// 			printf("\n--------\n");
			printFloat(nos,size);
			printChar(ops,size);
			printExpression(nos,ops,size);
			i--;
		}
		else {
			continue;
		}
		
	}
	
	//Multiply
	for(i=0;i<size;i++){
		if(ops[i] == '*'){
			result = calc(nos[i],nos[i+1],'*');
			delFloatIndex(nos,i,size);
			delCharIndex(ops,i,size);
			nos[i] = result;
// 			printf("\n--------\n");
			printFloat(nos,size);
			printChar(ops,size);
			printExpression(nos,ops,size);
			i--;
		}
		else {
			continue;
		}
	}
	
	//Subtraction
	for(i=0;i<size;i++){
		if(ops[i] == '-'){
			result = calc(nos[i],nos[i+1],'-');
			delFloatIndex(nos,i,size);
			delCharIndex(ops,i,size);
			nos[i] = result;
// 			printf("\n--------\n");
			printFloat(nos,size);
			printChar(ops,size);
			printExpression(nos,ops,size);
			i--;
		}
		else {
			continue;
		}
	}
	
	//Addition
	for(i=0;i<size;i++){
		if(ops[i] == '+'){
			result = calc(nos[i],nos[i+1],'+');
			delFloatIndex(nos,i,size);
			delCharIndex(ops,i,size);
			nos[i] = result;
// 			printf("\n--------\n");
			printFloat(nos,size);
			printChar(ops,size);
			printExpression(nos,ops,size);
			i--;
		}
		else {
			continue;
		}
	}
	
	
	
	return result;
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
	int i , index=0, first_no=1, counter=0;float operands[100];
	char get_no[100],last_op;
	char operators[100];
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
				operands[counter] = temp_no;
				first_no = 0;
				last_op = toCalc[i];
				operators[counter] = last_op;
				counter++;
			}
			else{
//				result = calc(result,temp_no,last_op);
				operands[counter] = temp_no;
				last_op = toCalc[i];
				operators[counter] = last_op;
				counter++;
			}
			
		}
		
		
		
		
	}
	get_no[index] = 'e';
	temp_no = charToInt(get_no);
	operands[counter] = temp_no;
	
	printExpression(operands,operators,counter);
	result = bodmas_calculator(operands,operators,counter);
	
	

	return result;
}




int main(){
	int i,n=15;
	char arr[100];// = "5*6/9-68+58/74";
	char no_check[] = "126058e";
	
	puts("Enter the question:");
	gets(arr);
	
	//finding length of arr
	for(n=0;arr[n]!='\0';n++);
	
	
	printf("Question:");
	for(i=0;i<n;i++) printf("%c",arr[i]);
	printf("\n\n");

	printf("\nResult:%.13f",eval(arr,n));
	
	
	return 0;
}
