///////////////////////////////////////////////////////////////////////
// SemiExpression.cpp - collect tokens for analysis                  //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 2015                              //
// Application: Parser component, CSE687 - Object Oriented Design    //
// Author:      Sushant Garg, Syracuse University,                   //
//              sugarg@syr.edu                                       //
// Source:      Jim Fawcett, Syracuse University, CST 4-187          //
//              jfawcett@twcny.rr.com                                //
///////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <exception>
#include "SemiExp.h"
#include "../Tokenizer/Tokenizer.h"
#include <algorithm>

using namespace Scanner;

SemiExp::SemiExp(Toker* pToker) : _pToker(pToker) {}

bool SemiExp::get()
{
  if (_pToker == nullptr)
    throw(std::logic_error("no Toker reference"));
  _tokens.clear();
  bool isFor = false;
  while (true)
  {
	  std::string token = _pToker->getTok();
	  std::string temp;

	  if (token == "")
		  break;

	  if (token == "for") {
		  isFor = true;
	  }

	  

	  if (!isFor) {
		  _tokens.push_back(token);
		  
		  if (token == "\n" || token == ";") {
			  if (token == "\n") {
				 _tokens.pop_back();
			  }

			  //for dealing with public,protected,private
			  if (token == "public" || token == "private" || token == "protected") {
				  temp = _pToker->getTok();
				  
				  do
				  {
					  _tokens.push_back(temp);
					//  temp = _pToker->getTok();

				  } while (temp!=":");

				  
				  
			  }
			  //

			  return true;
		  }
	  }
	  else {
		  _tokens.push_back(token);
		  if (token == ")") {
			  return true;
		  }
		}
	//For dealing with public,private,protected
	  if (token==":")
	  {
		  temp = _pToker->getTok();
		  if (temp == "public" || temp == "private" || temp == "protected") {
			  _tokens.push_back(temp);
			  temp = _pToker->getTok();

			  do
			  {
				  _tokens.push_back(temp);
				  temp = _pToker->getTok();
			  } while (temp!="\n");
			 

		  }
		  return true;
	  }
   //
  }

  

  return false;
}

Token SemiExp::operator[](size_t n)
{
  if (n < 0 || n >= _tokens.size())
    throw(std::invalid_argument("index out of range"));
  return _tokens[n];
}

bool Scanner::SemiExp::get(bool clear)
{
	return false;
}

size_t SemiExp::length()
{
  return _tokens.size();
}



size_t Scanner::SemiExp::find(const std::string & tok)
{

	return size_t();

}

void Scanner::SemiExp::push_back(const std::string & tok)
{

}

bool Scanner::SemiExp::merge(const std::string & firstTok, const std::string & secondTok)
{
	return false;
}

bool Scanner::SemiExp::remove(const std::string & tok)
{
	
	return false;
}

bool Scanner::SemiExp::remove(size_t i)
{

	//remmove index position string in token

	if (_tokens.size() != 0) {
		std::cout << "\n  -- Remove string at index 0 in semiExpression --";
		std::cout << "\n ";

	
		
		_tokens.erase(_tokens.begin()+i);
		for (unsigned i = 0; i<_tokens.size(); ++i)
			std::cout << " " <<_tokens[i];
		
		std::cout << "\n";
	}
	return true;
}

void Scanner::SemiExp::toLower()
{
	//turn token to lowercase
	if (_tokens.size() != 0) {
		std::cout << "\n  -- semiExpression in Lowercase --";
		std::cout << "\n  ";

		for (auto token : _tokens)
		{
			if (token != "\n")
			{
				std::transform(token.begin(), token.end(), token.begin(), ::tolower);
				std::cout << token << " ";

			}
			else
			{
				std::cout << "\n";
				break;
			}

		}
		std::cout << "\n";
	}
	
}

void Scanner::SemiExp::trimFront()
{

	//remove whitespace
	if (_tokens.size() != 0) {
		std::cout << "\n  -- Trimmed semiExpression --";
		std::cout << "\n  ";

		for (auto token : _tokens)
		{
			if (token != "\n")
			{
				std::remove(token.begin(),token.end(), ' ');
				std::cout << token;

			}
			else
			{
				std::cout << "\n";
				break;
			}

		}
		std::cout << "\n";
	}
}

void Scanner::SemiExp::clear()
{
}

std::string Scanner::SemiExp::show(bool showNewLines)
{
	return std::string();
}

void SemiExp::show()
{
	if (_tokens.size() != 0) {
		std::cout << "\n  -- semiExpression --";
		std::cout << "\n  ";

		for (auto token : _tokens)
		{
			if (token != "\n")
			{
				std::cout << token << " ";

				
			}
			else
			{
				std::cout << "\n";
				break;
			}

		}
		std::cout << "\n";
	}
		 
}

//----< test stub >--------------------------------------------------

#ifdef TEST_SEMIEXP

int main()
{
  Toker toker;
 // std::string fileSpec = "../Tokenizer/Tokenizer.cpp";
  std::string fileSpec = "../Tokenizer/SemiExpTest.txt";
  std::fstream in(fileSpec);
  if (!in.good())
  {
    std::cout << "\n  can't open file " << fileSpec << "\n\n";
    return 1;
  }
  toker.attach(&in);

  SemiExp semi(&toker);
  while(semi.get())
  {
    semi.show();
	semi.toLower();
	//semi.trimFront();
	//semi.remove(0);
  }
  /*
     May have collected tokens, but reached end of stream
     before finding SemiExp terminator.
   */
  if (semi.length() > 0)
  {
    std::cout << "\n  -- semiExpression --";
    semi.show();
    std::cout << "\n\n";
  }
  return 0;
}

#endif