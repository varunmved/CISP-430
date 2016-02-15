#include <iostream>
#include <ctype.h>

using namespace std;
 
/*
	The program will evaluate a postfix expression that contains digits and operators.
	The program tries to simulate the microprocessor execution stack or evaluation
	of expression.
 */
 
//The class performing the evaluation
class Evaluation {
	public:
		int st[50];
		int top;
		char str[50];
		Evaluation() {
			top = -1;
		}
 
		//function to push the item
		void push(int item) {
			top++;
			st[top] = item;
		}
 
		//function to pop an item
		int pop() {
			int item = st[top];
			top--;
			return item;
		}
 
		//function to perform the operation depending on the operator.
		int operation(int a,int b,char opr) {
			switch(opr) {
				case '+':return a+b;
				case '-':return a-b;
				case '*':return a*b;
				case '/':return a/b;
				default: return 0;
			}
		}
 
		int calculatePostfix();
};
void push(int item) {
			top++;
			st[top] = item;
		}
 
		//function to pop an item
int pop() {
	int item = st[top];
	top--;
	return item;
	}

int operation(int a,int b,char opr) {
			switch(opr) {
				case '+':return a+b;
				case '-':return a-b;
				case '*':return a*b;
				case '/':return a/b;
				default: return 0;
			}
		}

 
//This is the function that calculates the result of postfix expression.
int calculatePostfix() {
	int index = 0;
	while(str[index]!='\0') {
		if(isdigit(str[index])) {
			push(str[index]-'0');
		}
		else {
			int x = pop();
			int y = pop();
			int result = operation(x,y,str[index]);
			push(result);
		}
		index++;
	}
	return pop();
}
 
/*
	main function that reads the postfix expression and	that prints the result.
 
	The input expression should be ending with a number
	An example input expression would be:
	123*+
	Its output will be 7.
 
*/
int main() {
	void clrscr();
	Evaluation eval;
	cout << "Enter the postfix: ";
	//cin >> eval.str;
	int result = eval.calculatePostfix();
	cout << "the result is " << result;
	
}
 