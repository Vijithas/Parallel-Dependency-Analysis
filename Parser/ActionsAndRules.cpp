/////////////////////////////////////////////////////////////////////
//  ActionsAndRules.cpp - implements new parsing rules and actions //
//  ver 2.3                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron 5000 Windows 10				   //
//  Application:   CSE687 PROJECT 3, Sp16		                   //
//  Author:		   Vijitha SathyanarayanaMurthy, CS				   //
//				   Syracuse University, CST 4-187				   //
//				   vsathyan@syr.edu								   //
//  Source:        Jim Fawcett, CST 4-187, Syracuse University     //
//                 (315) 443-3948, jfawcett@twcny.rr.com           //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ActionsAndRules.h"
#include "../Tokenizer/Tokenizer.h"
#include "../SemiExp/SemiExp.h"

Repository* Repository::repository = nullptr;
#ifdef TEST_ACTIONSANDRULES
int main(int argc, char* argv[])
{
	std::cout << "\n  Testing ActionsAndRules class\n "
		<< std::string(30, '=') << std::endl;

	try
	{
		std::queue<std::string> resultsQ;
		PreprocToQ ppq(resultsQ);
		PreprocStatement pps;
		pps.addAction(&ppq);

		FunctionDefinition fnd;
		PrettyPrintToQ pprtQ(resultsQ);
		fnd.addAction(&pprtQ);

		Toker toker("../ActionsAndRules.h");
		SemiExp se(&toker);
		Parser parser(&se);
		parser.addRule(&pps);
		parser.addRule(&fnd);
		while (se.get())
			parser.parse();
		size_t len = resultsQ.size();
		for (size_t i = 0; i < len; ++i)
		{
			std::cout << "\n  " << resultsQ.front().c_str();
			resultsQ.pop();
		}
		std::cout << "\n\n";
	}
	catch (std::exception& ex)
	{
		std::cout << "\n\n  " << ex.what() << "\n\n";
	}
}
#endif
