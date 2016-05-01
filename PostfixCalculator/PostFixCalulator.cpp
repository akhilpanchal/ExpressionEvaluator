#include"PostFixCalulator.h"

PostFixCalulator::PostFixCalulator() {

}

float PostFixCalulator::calculate(string input) {
	errorFlag = false;
	string token = "";
	for (auto c : input) {
		if (isOperand(c) || c =='.') {
			token += c;
		}
		else if (c == ' ') {
			operands.push(stof(token));
			token = "";
		}
		else if(isOperator(c) && operands.size() > 1) {
			float temp = performOperation(c);
			operands.push(temp);

		}
		else {
			errorFlag = true;
			return 0;
		}
	}
	float answer = (operands.empty()) ? 0 : operands.top();
	
	// Empty the Stack
	stack<float> emptyFloatStack;
	operands = emptyFloatStack;
	return answer;
}

float PostFixCalulator::performOperation(char c) {
	float operand2 = operands.top();
	operands.pop();
	float operand1 = operands.top();
	operands.pop();
	float temp = calculate(operand1, operand2, c);
	if (errorFlag) {
		return 0;
	}
	return temp;
}

float PostFixCalulator::calculate(float operand1, float operand2, char op) {
	if (supportedOperations.find(op) == supportedOperations.end())
	{
		errorFlag = true;
		return 0;
	}
	return supportedOperations[op]->calculate(operand1, operand2);
}

bool PostFixCalulator::isOperator(char token) {
	if (supportedOperations.find(token) == supportedOperations.end())
		return false;
	return true;
}

bool PostFixCalulator::isOperand(char token) {
	int value = token - '0';
	if (value >= 0 && value < 10)
		return true;
	return false;	
}



#ifdef TEST_EXEC

#include<iostream>
#include"Operations.h"
using namespace std;

int main(int argc, const char* args[]) {
	PostFixCalulator calculator;
	OperationFactory factory;
	calculator.addOperation('+', factory.createOperation('+'));
	calculator.addOperation('-', factory.createOperation('-'));
	calculator.addOperation('*', factory.createOperation('*'));
	calculator.addOperation('/', factory.createOperation('/'));

	string input = "";
	cout << "Enter post-fix expression: ";
	getline(cin, input);
	while (input != "exit") {
		try {
			float result = calculator.calculate(input);
			if (!calculator.error())
				cout << "Result: " << result << endl;
			else
				cout << "Invalid Input" << endl;
		}
		catch (exception e) {
			cout << e.what();
		}
		cout << "Enter post-fix expression: ";
		getline(cin, input);
	}
}
#endif