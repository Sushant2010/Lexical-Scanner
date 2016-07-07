/////////////////////////////////////////////////////////////////////
// Main.cpp - Test Executive for Tokenizer & Semi-Expression       //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2015                            //
// Application: Parser component, CSE687 - Object Oriented Design  //
// Author:      Sushant Garg, Syracuse University,                 //
//              sugarg@syr.edu                                     //
// Source:      Jim Fawcett, Syracuse University, CST 4-187        //
//              jfawcett@twcny.rr.com                              //
/////////////////////////////////////////////////////////////////////




#include "../Tokenizer/Tokenizer.h"
#include "../SemiExp/SemiExp.h"
#include <iostream>
#include <fstream>

using namespace Scanner;

	class Test {

	public:
		Test() :sem(&toker) {}
		Toker toker;
		SemiExp sem;
		void ToTerm();
		void SemTerm();
		void ForLoopCond();
	};

	//For Tokenizer output
	void Test::ToTerm()
	{
		toker.ccpp(true);
		std::string fileSpec = "TokenTerm.txt";
			std::fstream in(fileSpec);
			if (!in.good())
			{
				std::cout << "\n  can't open file " << fileSpec << "\n\n";
				
			}
			toker.attach(&in);
			
			    while (in.good())
				{
					std::string toke = toker.getTok();
					if (toke == "\n")
						toke = "newline";
					std::cout << "\n -- " << toke;
				}
				in.close();
	}

	//For Semi-Expression output
	void Test::SemTerm()
	{
		toker.ccpp(false);
		std::string fileSpec = "SemiExp.txt";
			std::fstream in(fileSpec);
			if (!in.good())
			{
				std::cout << "\n  can't open file " << fileSpec << "\n\n";
		
			}
		
			
			toker.attach(&in);
		
		    SemiExp semi(&toker);
			while (semi.get()) {
				semi.show();
			}
		
			if (semi.length() > 0)
			{
				std::cout << "\n  -- semiExpression --";
				semi.show();
				std::cout << "\n\n";
			}
			in.close();
	}

	//For loop condition check
	void Test::ForLoopCond()
	{
		toker.ccpp(false);
		std::string fileSpec = "ForLoopCondition.txt";
		std::fstream in(fileSpec);
		if (!in.good())
		{
			std::cout << "\n  can't open file " << fileSpec << "\n\n";

		}


		toker.attach(&in);

		SemiExp semi(&toker);
		while (semi.get()) {
			semi.show();
		}

		if (semi.length() > 0)
		{
			std::cout << "\n  -- semiExpression --";
			semi.show();
			std::cout << "\n\n";
		}
		in.close();

	}








int main() {

	

	    std::cout << "Project I - TestExecutive" << std::endl;
	    
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
	
		std::cout << "\n" << std::endl;
	
		std::cout << "Requirement 1 : Shall use Visual Studio 2015 and its C++ Windows Console Projects, as provided in the ECS computer labs " << std::endl;
	
		std::cout << "Requirement Met" << std::endl;
	
		std::cout << "---------------------------------------------------------------------------------" << std::endl;

		std::cout << "\n" << std::endl;
	
		std::cout << "Requirement 2 : Shall use the C++ standard library's streams for all I/O and new and delete for all heap-based memory management " << std::endl;
	
		std::cout << "Requirement Met" << std::endl;

		std::cout << "---------------------------------------------------------------------------------" << std::endl;
	
		std::cout << "\n" << std::endl;
	
		std::cout << "Requirement 3 : Shall provide C++ packages for Tokenizing, collecting SemiExpressions, and a scanner interface, ITokCollection " << std::endl;
	
		std::cout << "Requirement Met" << std::endl;

		std::cout << "---------------------------------------------------------------------------------" << std::endl;
	
		std::cout << "\n" << std::endl;

		std::cout << "Requirement 4 : Shall provide a Tokenizer package that declares and defines a Toker class that implements the State Pattern2 with an abstract ConsumeState class and derived classes for collecting the following token types :  " << std::endl;

		std::cout << "\n" << std::endl;
			
		std::cout << " - Alphanumeric tokens - " << std::endl;
		std::cout << " - Punctuator tokens - " << std::endl;
		std::cout << " - Special one and two character tokens with defaults that may be changed by calling setSpecialSingleChars(string ssc) and/or setSpecialCharPairs(string scp) - " << std::endl;
		std::cout << " - C style comments returned as a single token - " << std::endl;
		std::cout << " - C++ style comments returned as a single token - " << std::endl;
		std::cout << " - Quoted strings - " << std::endl;
		std::cout << "\n" << std::endl;
		
		std::cout << " INPUT : " << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << " cout << \"My name is Sushant\";" << std::endl;
		std::cout << " public ConsumeState();" << std::endl;
		std::cout << " if (currChar == '\"' && temp != '; ') {" << std::endl;
		std::cout << " prevChar = currChar;" << std::endl;
		std::cout << " currChar = _pIn->get();" << std::endl;
		std::cout << " break;" << std::endl;
		std::cout << " }" << std::endl;
		std::cout << " \n" << std::endl;
		
	

		std::cout << " OUTPUT : " << std::endl;

        Test t;
		
	    t.ToTerm();
		
		std::cout << "\n" << std::endl;

		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		
		std::cout << "\n" << std::endl;
		
		std::cout << "Requirement 5 : The Toker class, contained in the Tokenizer package, shall produce one token for each call to a member function getTok() " << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Requirement 5 met" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Requirement 6 : Shall provide a SemiExpression package that contains a class SemiExp used to retrieve collections of tokens by calling Toker::getTok() repeatedly until one of the SemiExpression termination conditions, below, is satisfied " << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Requirement 6 met" << std::endl;
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;
		
		std::cout << "Requirement 7 : Shall terminate a token collection after extracting any of the single character tokens: semicolon, open brace, closed brace. Also on extracting newline if a # is the first character on that line. Also, the extraction of a single character token consisting of : if immediately preceeded by one of the tokens: public, protected, or private"<< std::endl;
		std::cout << "\n" << std::endl;
		std::cout << " INPUT : " << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << " #include <iostream>" << std::endl;
		std::cout << " class EatSpecialSingleChars : public ConsumeState" << std::endl;
		std::cout << " {" << std::endl;
		std::cout << " public:" << std::endl;
		std::cout << " int temp;" << std::endl;
		std::cout << " }" << std::endl;
		std::cout << "\n" << std::endl;

        std::cout << " OUTPUT : " << std::endl;
        t.SemTerm();
		std::cout << "\n" << std::endl;
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "Requirement 8 : Shall provide a facility providing rules to ignore certain termination characters under special circumstances. You are required to provide a rule to ignore the (two) semicolons within parentheses in a for(;;) expression" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << " INPUT : " << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << " for(i=0;i<1;i++)" << std::endl;
		std::cout << " {" << std::endl;
		std::cout << " cout << \"This is a test for FOR\" << endl;" << std::endl;
		std::cout << " }" << std::endl;

		std::cout << "\n" << std::endl;
		std::cout << " OUTPUT : " << std::endl;
		std::cout << "\n" << std::endl;
		t.ForLoopCond();
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "Requirement 9 : The SemiExp class Shall implement the interface ITokenCollection with a declared method get()" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "The implementation can be found starting from Line No. 23 in SemiExpp.cpp" << std::endl;
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "Requirement 10 : Shall include an automated unit test suite that exercises all of the special cases that seem appropriate for these two packages" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Implemented the test suite in TestExec project" << std::endl;
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "\n" << std::endl;

    	return 0;
	
}


