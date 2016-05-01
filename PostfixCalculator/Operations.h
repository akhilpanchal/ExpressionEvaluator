#ifndef OPERATIONS_H
#define OPERATIONS_H

#include"PostFixCalulator.h"

class AddOperation : public IOperation {
public:
	float calculate(float op1, float op2) {
		return op1 + op2;
	}
};

class SubtractOperation : public IOperation {
public:
	float calculate(float op1, float op2) {
		return op1 - op2;
	}
};

class MultiplyOperation : public IOperation {
public:
	float calculate(float op1, float op2) {
		return op1 * op2;
	}
};

class DivideOperation : public IOperation {
public:
	float calculate(float op1, float op2) {
		return op1 / op2;
	}
};


class OperationFactory {
public:
	IOperation* createOperation(char op) {
		IOperation* operation;
		switch (op) {
		case '+':
			operation = new AddOperation;
			break;
		case '-':
			operation = new SubtractOperation;
			break;
		case '*':
			operation = new MultiplyOperation;
			break;
		case '/':
			operation = new DivideOperation;
			break;
		default:
			operation = nullptr;
			break;
		}
		return operation;
	}
};

#endif