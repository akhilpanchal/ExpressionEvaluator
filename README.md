# ExpressionEvaluator
Evaluates Post-fix Expression. Mainly focused on making the design extensible.

Author:	Akhil Panchal
Email: 	akhilpanchal@gmail.com

Number of files submitted: 2
	PostfixCalculator.h
	PostfixCalculator.cpp

The Postfix Calculator package provides a PostfixCalculator class that
supports calculation of postfix expression. 4 operations are currently
supported: +, -, *, /.

Build command:
	g++ -std=c++0x PostFixCalulator.cpp -D TEST_EXEC

I have tested this with g++ version 4.6.3.

This utility can be extended easily to support more operations, by doing the 
following steps:

1. Create a class that implements the IOperation interface given in Operations.h
2. In the calculate function, perform the neccessary operation and return the float result.
3. In your Client code, add an entry to the PostifixCaluclator by calling the method
	addOperation(char, IOperation*);
The IOperation* for the operation will be generated by calling the Factory method:
	IOperation* createOperation(char);

This design makes the PostfixCalculator independent of the concrete implementation of 
the operations as it depends only on the IOperation interface and the clients only 
depend on the OperationFactory.
Any change to the concrete implementation, will not affect the PostfixCalculator.

Note:
	Interface(IOperation) and the ObjectFactory (OperationFactory) should be in separte files.
	But for ease, I have put the interface in PostFixCalculator.h and the Factory in Operations.h


Please let me know if you have any further question regarding my design or implementation.
