#ifndef SEMIEXPRESSION_H
#define SEMIEXPRESSION_H
///////////////////////////////////////////////////////////////////////
// SemiExpression.h - collect tokens for analysis                    //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 2015                              //
// Application: Parser component, CSE687 - Object Oriented Design    //
// Author:      Sushant Garg, Syracuse University,                   //
//              sugarg@syr.edu                                       //
// Source:      Jim Fawcett, Syracuse University, CST 4-187          //
//              jfawcett@twcny.rr.com                                //
///////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides a public SemiExp class that collects and makes
* available sequences of tokens.  SemiExp uses the services of a Toker
* class to acquire tokens.  Each call to SemiExp::get() returns a 
* sequence of tokens that ends in {.  This will be extended to use the
* full set of terminators: {, }, ;, and '\n' if the line begins with #.
*
* This is a new version for students in CSE687 - OOD, Spring 2016 to use
* for Project #1.
*
* Build Process:
* --------------
* Required Files: 
*   SemiExpression.h, SemiExpression.cpp, Tokenizer.h, Tokenizer.cpp
* 
* Build Command: devenv Project1.sln /rebuild debug
*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Feb 2016
*         - first release
*/

#include <vector>
#include "../Tokenizer/Tokenizer.h"

namespace Scanner
{
  using Token = std::string;

  class SemiExp
  {
  public:
    SemiExp(Toker* pToker = nullptr);
    SemiExp(const SemiExp&) = delete;
    SemiExp& operator=(const SemiExp&) = delete;
    bool get();
    Token operator[](size_t n);
    size_t length();
    void show();

	//itokcollection declarations
	bool get(bool clear);
	//std::string& operator[](int n);
	size_t find(const std::string& tok);
	void push_back(const std::string& tok);
	bool merge(const std::string& firstTok, const std::string& secondTok);
	bool remove(const std::string& tok);
	bool remove(size_t i);
	void toLower();
	void trimFront();
	void clear();
	std::string show(bool showNewLines);
	

  private:
    std::vector<Token> _tokens;
    Toker* _pToker;
  };
}
#endif
