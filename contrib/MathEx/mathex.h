///////////////////////////////////////////////////////////////////////////
// mathex 0.2.3 (beta) - Copyright (C) 2000-2003, by Sadao Massago       //
// file: mathex.h (math expression evaluator header file)                //
// requires: none                                                        //
// project web page: http://sscilib.sourceforge.net/                     //
//-----------------------------------------------------------------------//
// The mathex library and related files is licensed under the term of    //
// GNU LGPL (Lesser General Public License) version 2.1 or latter        //
// with exceptions that allow for static linking.                        //
// See license.txt for detail.                                           //
// For GNU LGPL, see lesser.txt.                                         //
// For information over GNU or GNU compatible license, visit the site    //
// http://www.gnu.org.                                                   //
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// references:
//-------------------------------------------------------------------------
// title: Algoritms and Data Structures
// author: Niklaus Wirth
// publisher: Prentice-Hall
// year: 1989
//-------------------------------------------------------------------------
// title: The C++ programming language
// edition: thrird
// author: Bjarne Stroustrup
// publisher: Addilson-Wesley
// year: 1997
//-------------------------------------------------------------------------
// title: building your own C interpreter
// author: Schildt, Helbert
// journal: Dr. Dobb's Jornal (http://www.ddj.com)
// number: August/1989
// pages: 38-49, 110-122
///////////////////////////////////////////////////////////////////////////

// example file listing for doxygen

/// \example inttest.cpp
/// integration test using Trapezoidal rule

/// \example userfunctest.cpp
/// user defined function testing

/// \example tabletest.cpp
/// making table of function
 
/// \example curvetest.cpp
/// making table of parametric curve

// #define _DEBUG_

#ifndef _MATHEX_H
 #define _MATHEX_H

#include <string>
#include <vector>
#include <cmath>
// #include <cctype>
// debug purpose
#ifdef _DEBUG_
  #include <iostream>
#endif

namespace smlib {

using namespace std;

/////////////////////////////////////
// mathex main class
// it contain several sub classes
// to handle expressions
/////////////////////////////////////

    class mathex {
   /////////////////////////
   // private sub calsses
   ////////////////////////
   
     // code token used by evaluator
       class CODETOKEN {
      public:
         // token type (code token type)
         enum type {
         VALUE=0, // numerical value stack
         VARIABLE, // variable stack
         FUNCTION, // internal C function with one parameters (include unary operators)
         BINOP, // internal C binary opeartors (function with two parameters)
         USERFUNC, // user defined functions
         LASTTYPE=USERFUNC};
      
         type state;  // state of Token
         unsigned numargs;
         // The user defined function use it to pop values from stack
			// In the undefined number of arguments case, it will not eliminated
			double value; // numerical value
         unsigned idx; // index of variable, function or user defined function on table
          CODETOKEN(double x=0.0) // construct VALUE token
         {
            state = VALUE;
            value = x;
         }
          CODETOKEN(type toktype, unsigned index, unsigned NumArgs=1) // construct token except VALUE
          // in the used defined function case, num args need to set
         {
            state = toktype;
            idx = index;
				numargs = NumArgs;
         }
      }; // CODETOKEN
   
      // parse token used by parser
       class PARSERTOKEN {
      public:
         enum type {
         VALUE, VARIABLE, FUNCTION, USERFUNC,
         PLUS, MINUS, TIMES, DIVIDE, MODULE, POWER, 
         OPAREN, CPAREN, COMMA, END, INVALID, // invalid character on token
         LASTTYPE=INVALID
         };
      
         type state;
         int numargs; // number of parameters of functions
         double value;
         int idx; // it are signed because receive func/var search index that will be -1
      	         // atom parsing cede optimization
      };  // parsetoken
   
   
   // function record
   
   //  Record for user defined functions
       class FUNCREC {
      public:
         string name;
         double  (*f)(vector<double> const &x); // generic number of parameters
         int numargs; // number of arguments
          FUNCREC() // only for table (vector) operation
         {name = ""; f = 0;}
          FUNCREC(string const &funcname, double (*func)(vector<double> const &), int NumArgs)
         {name = funcname; f = func; numargs = NumArgs; }
      }; // FUNCREC
   
   
   // variable record
       class VARREC {
      public:
         string name;
         double *var;
          VARREC()
         {name = ""; var = 0;}
          VARREC(string const &varname, double *x)
         {
            if(x == NULL) throw error("Error [VARREC()]: variable without reference");
            name = varname; var = x; }
      }; // VARREC
   
   /////////////////////
   // evalmath start here
   /////////////////////
      
      vector<FUNCREC> functable; // used defined function table
      vector<VARREC> vartable; // used defined variable table
      vector<CODETOKEN> bytecode; // parsed code
      vector<double> evalstack; // stack memory used by evaluator
      string expr; // expression string
      enum {invalid, notparsed, parsed} status; // prse status
   
      // used by addvar/addfunc to validate new variable/functions name
      bool isnewvalidname(string const &name); // check if new valid name
   
      // table look up
      int getconst(string const &name); // get index of constant
      int getvar(string const &name); // get index of variable
      int getcfunc(string const &name); // get index of one parameter internal C function
      int getunaryop(string const &name); // get index of unary operator
      int getbinop(char name); // get index of binary operator
      int getuserfunc(string const &name); // get index of user defined functions
      void addstdfunc(); // add standard user defined functions to table
   
      // token operators
      bool getnumber(double &x); // get number from input string
      bool getidentifier(string &name); // get identifier from input string
      PARSERTOKEN::type nexttoken(); // get next token from input string
      vector<PARSERTOKEN> parserstack; // stack used by parser
      PARSERTOKEN curtok; // current token. Used by parser
      unsigned long pos; // expression parsing position
   
      #ifdef _DEBUG_
      void printcoderec(CODETOKEN const &token); // used by printbytecode()
      #endif
      // parser methods
      // aritmethic operators
      void parsearithmetic1(void);  // binary plus/minus 
      void parsearithmetic2(void);  // timed, divide, modulo
      void parsearithmetic3(void);  // power
      void parsearithmetic4(void);  // unary minus 
      void parseatom(void);  // atom: functions, variables, numbers...
      
   public:
       ///////////////////////
   	 // public sub classes
   	 ///////////////////////
   	 
         /// error class to hamdle exceptions
     class error : public std::exception {
        private:
         string msg;
         public:
            /// with message only
          error(string const &message)
         { msg = "Error [eval]: " + message; }
			/// error with identifier and messages
          error(string const &id, string const &message)
         { msg = "Error [mathex::" + id + "]: " + message; }
          /// unkone error
          error()
         { msg = "Error [mathex]: unkonw error"; }
          /// return error message
          const char * what() const throw()
         { 
            return msg.c_str(); }            
          ~error() throw() {}
       }; // error		
   	 
   	////////////////////////////////////////////////////
      // mathex public constants, variables and methods
   
      #ifdef _DEBUG_
      void printbytecode(); // output byte code to cout
      #endif
   
   
    // add/delete variables
      bool addvar(string const &name, double *x); /// < add new variable
      bool delvar(string const &name); /// < delete variable
       void delvar() /// < delete all variables
      {vartable.clear(); status = notparsed; }
   
       /// undefined number of arguments (for user defined functions
      static const int UNDEFARGS; // for user function arguments   
      // add/delete used defined functions
      bool addfunc(string const &name, double (*f)(vector<double> const &), int NumArgs); /// < add new function
      bool delfunc(string const &name); /// < delete variable
       void delfunc() /// < delete all variable
      {functable.clear(); addstdfunc(); status=notparsed; }
    // expression string
       string const &expression() /// < return expression string
      {
         return expr;}
       void expression(string const &formula) /// < set expression string
      { expr = formula; status = notparsed; pos=0; }
       unsigned long stopposition() /// < return parser stoped position
      { 
         return pos; }
      void parse(); /// < parse expression 
      double eval(); /// < eval expression
      void reset(); /// < reset all
       mathex() /// < default constructor
      {reset();}
       mathex(string const &formula) /// < constructor that assign expression string
      {reset(); expr = formula;}
   }; /// mathex


} // namespace smlib {

#endif // #ifndef _MATHEX_H

// end of mathex.c
