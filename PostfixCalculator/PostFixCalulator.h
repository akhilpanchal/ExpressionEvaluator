#ifndef POSTFIX_CALCULATOR
#define POSTFIX_CALCULATOR

#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

class IOperation {
public:
	virtual float calculate(float, float) = 0;
};

class PostFixCalulator {
public:
	PostFixCalulator();
	void addOperation(char op, IOperation* operation) {
		supportedOperations[op] = operation;
	}
	float calculate(string input);
	bool error() {	return errorFlag;	}
private:
	bool errorFlag;
	float performOperation(char);
	float calculate(float,float,char);
	bool isOperator(char token);
	bool isOperand(char token);
	stack<float> operands;
	unordered_map<char, IOperation*> supportedOperations;
};

#endif