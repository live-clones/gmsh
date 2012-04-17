///////////////////////////////////////////////////////////////////////////
// mathex 0.2.3 (beta) - Copyright (C) 2000-2003, by Sadao Massago       //
// file: mathex.h (math expression evaluator header file)                //
// requires: none                                                        //
// project web page: http://sscilib.sourceforge.net/                     //
// ----------------------------------------------------------------------//
// The mathex library and related files is licenced under the term of    //
// GNU LGPL (Lesser General Public License) version 2.1 or latter        //
// with exceptions that allow for static linking.                        //
// See license.txt for detail.                                           //
// For GNU LGPL, see lesser.txt.                                         //
// For information over GNU or GNU compatible license, visit the site    //
// http://www.gnu.org.                                                   //
///////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// references:
//-------------------------------------------------------------------------
// title: Algoritms and Data Structures
// author: Niklaus Wirth
// publisher: Prentice-Hall
// year: 1989
//-------------------------------------------------------------------------
// title: The C++ Programming Language
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

// #define _DEBUG_

#include "mathex.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <cctype>
// debug purpose
#ifdef _DEBUG_
  #include <iostream>
#endif

   namespace smlib {
      using namespace std;
   
   
   ////////////////////////////////////
   // local variables, functions, etc
   ////////////////////////////////////
      namespace {
      
      //////////////////////////////////
      // C function with one parameter
      //--------------------------------
      
          double fac(double x)
         // Function return the factorial of integer belong to range 0..170.
         // in future, will implement aproximation for gamma function to evaluate for x > 170
         {
            double p;
            unsigned n;
         
            if((x <0) || (x>170)) // maximum admited where
               throw mathex::error("Error [fac()]: range error");
            else {
               n = static_cast<unsigned>(x+0.5);
               if(x < 2)
                  return 1;
               else if(n == 2)
                  return(2);
               for(p=1;1<n;n--)
                  p *= n;
               return p;
            }
         } // fac()
      
      // convert radian to degree
          double deg(double x)
         {
            return( x * 180.0 / M_PI);
         } // deg()
      
      // convert degree to radian
          double rad(double x)
         {
            return(x * M_PI / 180.0);
         } // rad()
      
      // return square
      /*    double sqr(double x)
      {
         return (x*x);
      } */
      // sqr()
      
      // return real part
          double trunc(double x)
         {
            return static_cast<long>(x);
         } // trunc()
      
      // return rounded value to int
          double round(double x)
         {
            return static_cast<long>(x+0.5);
         } // round
      
      // return 0 if x negative, 1 otherwise
          double step(double x)
         {
           if ( x < 0 ) return static_cast<long>(0.);
           return static_cast<long>(1.);
         } // step
      
      // return -1 if x negative, 1 otherwise
          double sign(double x)
         {
           if ( x < 0 ) return static_cast<long>(-1.);
           return static_cast<long>(1.);
         } // sign
      
      //////////////////////////////////////////////////////////
      // arithmetic operators
      //////////////////////////////////////////////////////////
      // operators was treated in Parsingr time, to check the
      //   operator level.
      //   unary operator is the function double op(double) and
      //   binary operator is function double op(double,double)
      //--------------------------------------------------------
      //   unary:
      //   "+" -> none
      //   "-" -> unary_minus
      //   binary:
      //   "+" -> binary_plus
      //   "-" -> binary_minus
      //   "*" -> binary_times
      //   "/" -> binary_divide
      //   "^" -> binary_power
      //   "%" -> fmod (defined in math.h)
      ///////////////////////////////////////////////////////////
      
      //////////////////////
      // C unary operator
      
          double unary_minus(double x)
         {
            return -x;
         } // unary_minus()
      
      //////////////////////////////////////////
      // C binary operators
      //----------------------------------------
      
          double binary_plus(double x, double y)
         {
            return x + y;
         } // binary_plus() 
      
          double binary_minus(double x, double y)
         {
            return x - y;
         } // binary_minus()
      
          double binary_times(double x, double y)
         {
            return x * y;
         } // binary_timess()
      
          double binary_divide(double x, double y)
         // in future, put more precisery checking, for overflow ?
         {
            if (y == 0)
               throw mathex::error("Error [binary_divide()]: divisin by zero");
            else
               return (x/y);
         } // binary_divide()
      
          double binary_power(double x, double y)
         {
            return pow(x,y);
         } // binary_power()
      
      /////////////////////////////////////////
      // pre-defined user defined functions
      //---------------------------------------
      
          double p_rand(vector <double> const &x)
         // rand() return value between [0,1)
         {
            if(x.size() != 0)
               throw mathex::error("Error [p_rand()]: can not use argument");
            return rand()/(RAND_MAX+1.0);
         } // p_rand()
      
      // maximum
          double p_max(vector <double> const & x)
         {
         
            double maxval=0;
         
            if(x.size() == 0)
               throw mathex::error("Error [p_max()]: No arguments");
            maxval = x[0];
            for(unsigned i=0; i<x.size(); i++)
               if(x[i] > maxval)
                  maxval = x[i];
         
            return maxval;
         } // p_max
      
      // minimum
          double p_min(vector <double> const & x)
         {
         
            double minval=0;
         
            if(x.size() == 0)
               throw mathex::error("Error [p_min()]: No arguments");
            minval = x[0];
            for(unsigned i=0; i<x.size(); i++)
               if(x[i] < minval)
                  minval = x[i];
         
            return minval;
         } // p_min
      
      // sum
          double p_sum(vector <double> const & x)
         {
         
            double sumval=0;
         
            if(x.size() == 0)
               throw mathex::error("Error [p_sum()]: No arguments");
            for(unsigned i=0; i<x.size(); i++)
               sumval += x[i];
         
            return sumval;
         } // p_sum
      
      // average
          double p_med(vector <double> const & x)
         {
            if(x.size() == 0)
               throw mathex::error("Error [p_med()]: No arguments");
            return p_sum(x)/x.size();
         } // p_med()
      
      ////////////////////////////////
      // function/constant tables
      ////////////////////////////////
      
      //////////////////////////////////
      // One parameter C function table
      
      // Record for one parameter C functions
         typedef 
             struct
            {
               const char *name;
               double  (*f)(double x); // one parameter function
            } CFUNCREC;
      	
      ///////////////////////////////////////////////////////////   
      // One parameter internal C defined functions
      // the unary operator are stored on first part of table
      //---------------------------------------------------------
      // CAUTION:
      // if add unary operator, adjust the definiftion of NUM_UNARY_OP 
      #define NUM_UNARY_OP 1
         CFUNCREC cfunctable[] =
         {
         // name and funtion pointer
         // first part of table is unary operators
         {"-", unary_minus}, // unary operator
         // seccond part of table is functions
         { "abs",     fabs },
         { "Abs",     fabs },
         { "fabs",     fabs },
         { "Fabs",     fabs },
         { "acos",    acos },
         { "Acos",    acos },
         { "asin",    asin },
         { "Asin",    asin },
         { "atan",    atan },
         { "Atan",    atan },
         { "cos",     cos },
         { "Cos",     cos },
         { "cosh",    cosh },
         { "Cosh",    cosh },
         { "deg",     deg },   // added
         { "Deg",     deg },
         { "exp",     exp },
         { "Exp",     exp },
         { "fac",     fac },   // added
         { "Fac",     fac },
         { "log",     log },
         { "Log",     log },
         { "log10",   log10 },
         { "Log10",   log10 },
         // { "pow10",   pow10 } // in future, add it?
         { "rad",     rad },   // added 
         { "Rad",     rad },
         { "round",   round }, // added
         { "Round",   round },
         { "sign",    sign },
         { "Sign",    sign },
         { "sin",     sin },
         { "Sin",     sin },
         { "sinh",    sinh },
         { "Sinh",    sinh },
         // { "sqr",     sqr }, // added
         { "sqrt",    sqrt },
         { "Sqrt",    sqrt },
         { "step",    step },
         { "Step",    step },
         { "tan",     tan },
         { "Tan",     tan },
         { "tanh",    tanh },
         { "Tanh",    tanh },
#if !defined(WIN32)
         { "atanh",   atanh },
         { "Atanh",   atanh },
#endif
         { "trunc",   trunc }, // added
         { "Trunc",   trunc },
         { "floor",   floor }, // largest integer not grather than x
         { "Floor",   floor },
         { "ceil",    ceil }, // smallest integer not less than x
         { "Ceil",    ceil },
         
         { 0, 0 } // 0 mark the end of table
         };
      
      /////////////////////
      // binary operators
      
      // binary operator's record
          class BINOPREC {
         public:
            char name;
            double (*f)(double, double);
         };
      
      ////////////////////
      // binary operators
         BINOPREC binoptable[] =
         {
         // name, value
         { '+',  binary_plus},
         { '-',  binary_minus},
         { '*',  binary_times},
         { '/',  binary_divide},
         { '^',  binary_power},
         { '%',  fmod},
         
         { '\0' , 0 } // '\0' mark the end of table
         };
      
      //////////////
      // constants
      
      // constants record
          class CONSTREC {
         public:
            const char *name;
            double value;
         };
      
      /////////////
      // constants
         CONSTREC consttable[] =
         {
         // name, value
         { "pi",  M_PI },
         { "e",   M_E },
         
         { NULL, 0 } // NULL mark the end of table
         };
      
      } // namespace {
   
   
   ////////////////////////////
   // implementations
   ///////////////////////////
   
   ///////////////
   // constatnts
   /// undefined number of arguments (for user defined functions
      const int mathex::UNDEFARGS = -1; // for user function arguments   
   
   ////////////////
   // methods
       void mathex::addstdfunc()
      {
         addfunc("rand", p_rand, 0);
         addfunc("Rand", p_rand, 0);
         addfunc("sum", p_sum, UNDEFARGS);
         addfunc("Sum", p_sum, UNDEFARGS);
         addfunc("max", p_max, UNDEFARGS);
         addfunc("Max", p_max, UNDEFARGS);
         addfunc("min", p_min, UNDEFARGS);
         addfunc("Min", p_min, UNDEFARGS);
         addfunc("med", p_med, UNDEFARGS);
         addfunc("Med", p_med, UNDEFARGS);
      } // addstdfunc()
   
       void mathex::reset()
      {
         delvar();
         delfunc();
         status = notparsed;
         expr = "";
         bytecode.clear();
         pos = 0;
         addstdfunc();  
      } // reset
   
   /////////////////////////////////
   // varibles table manipulations
   
       bool mathex::addvar(string const &name, double *var)
      // register the program internal variable
      {
         unsigned i;
      
         for(i=0; (i<vartable.size()) && (vartable[i].name != name);i++);
         if(i<vartable.size()) { // found! overwrite
            vartable[i].var = var;
            return true;
         }
         else if(!isnewvalidname(name))
            return false;
         vartable.push_back(VARREC(name, var));
         return true;
      } // addvar()
   
       bool mathex::delvar(string const &name)
      // delete one variable
      {
         unsigned i;
      
         for(i=0; (i<vartable.size()) && (vartable[i].name != name);i++);
         if(i < vartable.size())  {
         // how to use erase?
         // vartable.erase(&vartable[i],&vartable[i+1]);
            for(unsigned j=0; j<vartable.size()-1; j++)
               vartable[j] = vartable[j+1];
            vartable.pop_back(); // delete last
            status = notparsed;
            return true;
         }
         else
            return false;
      } // delvar()
   
   //////////////////////////////////////////////
   // user defined function table manipulation
   //////////////////////////////////////////////
   
       bool mathex::addfunc(string const &name, double (*f)(vector<double> const &), int NumArgs)
      // register the user defined function
      {
         unsigned i;
      
         for(i=0; (i<functable.size()) && (functable[i].name != name);i++);
         if(i<functable.size()) { // found! overwrite
            functable[i].f = f;
            functable[i].numargs = NumArgs;
            return true;
         }
         else if(!isnewvalidname(name))
            return false;
         functable.push_back(FUNCREC(name, f, NumArgs));
         return true;
      } // addfunc()
   
       bool mathex::delfunc(string const &name)
      // delete the user defined function
      {
         unsigned i;
      
         for(i=0; (i<functable.size()) && (functable[i].name != name);i++);
         if(i < functable.size())  {
         // how to use erase?
         // functable.erase(&vartable[i],&vartable[i+1]);
            for(unsigned j=0; j<vartable.size()-1; j++)
               functable[j] = functable[j+1];
            functable.pop_back(); // delete last
            return true;
         }
         else
            return false;
      } // delfunc()
   
   ////////////////////////////////////////////////////
   // get the index of variables/constants/functions/
   //     binary operator/user defined functions
   //--------------------------------------------------
   // return -1 if not found
   ////////////////////////////////////////////////////
   
       int mathex::getconst(string const &name)
      // get index of const
      // return -1 if not found
      {
         unsigned i;
      // look up the constants
         for(i=0;consttable[i].name && strcmp(name.c_str(), consttable[i].name);i++);
         if(consttable[i].name != NULL) // if found
            return i;
         else
            return -1;
      } // getconst
   
   
       int mathex::getvar(string const &name)
      // get index of variable
      // return -1 if not found
      {
         unsigned i;
      
      // look up the table
         for(i=0;(i<vartable.size()) && strcmp(name.c_str(), vartable[i].name.c_str());i++);
         if(i<vartable.size()) // if found
            return i;
         else
            return -1;
      } // getvar
   
   
       int mathex::getcfunc(string const &name)
      // get index of one parameter function
      // return -1 if not found
      {
         unsigned i;
      // look up the constants
         for(i=NUM_UNARY_OP;cfunctable[i].name && strcmp(name.c_str(), cfunctable[i].name);i++);
         if(cfunctable[i].name != NULL) // if found
            return i;
         else
            return -1;
      } // getcfunc
   
       int mathex::getunaryop(string const &name)
      // get index of unary operator
      // return -1 if not found
      {
         unsigned i;
      // look up the constants
         for(i=0; cfunctable[i].name && strcmp(name.c_str(), cfunctable[i].name);i++);
         if(cfunctable[i].name != NULL) // if found
            return i;
         else
            return -1;
      } // getunaryop
   
       int mathex::getbinop(char name)
      // get index of one parameter function
      // return -1 if not found
      {
         unsigned i;
      // look up the constants
         for(i=0;binoptable[i].name && (name != binoptable[i].name);i++);
         if(binoptable[i].name != '\0') // if found
            return i;
         else
            return -1;
      } // getbinop
   
   
       int mathex::getuserfunc(string const &name)
      // get index of variable
      // return -1 if not found
      {
         unsigned i;
      // look up the constants
         for(i=0;(i<functable.size()) && strcmp(name.c_str(), functable[i].name.c_str());i++);
         if(i<functable.size()) // if found
            return i;
         else
            return -1;
      } // getuserfunc
   
   
       bool mathex::isnewvalidname(string const &name)
      // Name validation.
      {
         if(name.empty() || (!isalpha(name[0]) && (name[0] != '_')))
            return false;
      // check for rest of characters
         for(unsigned j=0; j<name.size(); j++)
            if(!isalnum(name[j]) && (name[j] != '-'))
               return false;
         return (getcfunc(name) < 0) && (getconst(name) < 0) 
            && (getuserfunc(name) < 0) && (getvar(name) < 0);
      } // isnewvalidname
   
   
   //////////////////
   //  Evaluation 
   
   // main evaluator: internal use only
   
   // main evaluation function
       double mathex::eval()
      //  Eval the parsed stack and return
      {
         static vector <double> x; // suppose that eval does not eval
         evalstack.clear();
      
         if(status == notparsed) parse();
         if(status == invalid) throw error("eval()", "invalid expression");
      
         for(unsigned i=0; i<bytecode.size(); i++)
         {
            switch(bytecode[i].state) {
               case CODETOKEN::VALUE: evalstack.push_back(bytecode[i].value);
                  break;
               case CODETOKEN::VARIABLE:
               // get value of variable as value
                  evalstack.push_back(*vartable[bytecode[i].idx].var);
                  break;
               case CODETOKEN::FUNCTION: // Call the C internal functions with one parameter
               #ifdef _DEBUG_
               if(evalstack.size()<1) // error: It does not to occur if currect parsed.
                  throw error("eval()", "stack error");
               #endif
                  evalstack.back() = cfunctable[bytecode[i].idx].f(evalstack.back());
                  break;
               case CODETOKEN::BINOP: // Call the intern C function with two parameters
               #ifdef _DEBUG_
               if(evalstack.size() < 2) // error: It does not to occur if currect parsed.
                  throw error("eval()", "stack error");
               #endif
                  evalstack[evalstack.size()-2] = binoptable[bytecode[i].idx].f
                     (evalstack[evalstack.size()-2], evalstack.back());
                  evalstack.pop_back(); // delete last
                  break;				
               case CODETOKEN::USERFUNC: // Call the user defined functions
               #ifdef _DEBUG_
               if(bytecode[i].numargs > evalstack.size())
                  throw error("eval()", "stack error");
               #endif
                  if(bytecode[i].numargs > 0) {
                     x.resize(bytecode[i].numargs);
                     for(unsigned j=0; j<static_cast<unsigned>(bytecode[i].numargs); j++)
                        x[bytecode[i].numargs-1-j] = evalstack[evalstack.size()-1-j];
                     evalstack.resize(evalstack.size()-bytecode[i].numargs+1);
							
                     evalstack.back() = functable[bytecode[i].idx].f(x);
                  }
						else // Fixing bug pointed by  Hugh Denman <denmanh@tcd.ie> November 06, 2003
						   evalstack.push_back(functable[bytecode[i].idx].f(x));
                  break;         
               default: // invarid stack. It does not occur if currect parsed
                  throw  error("eval()", "invalid code token");
            }
         } // for(i=0; ByteCode[i].state != EMPTY;i++);
      
      #ifdef _DEBUG_
      if(evalstack.size() != 1)
         throw error("eval()", "stack error");  
      #endif
         return evalstack[0];
      } // eval()
   
   /////////////////
   // parser
   //---------------
   
   /////////////////
   // get the token
   
   // get the number token
       bool mathex::getnumber(double &x)
      {
         unsigned long i = pos;
         bool decimal;
      
      // is a number?
         if((i >= expr.size()) || !strchr("0123456789.", expr[i])) // not a number
            return false;
      
      // getting the number
         for(decimal=false; i<expr.size(); i++) {
            if(!isdigit(expr[i]) && ((expr[i] != '.') || decimal) )
               break;
            if(expr[i] == '.') decimal = true;
         }
      
         if((i==(pos+1)) && (expr[i]=='.')) // is not a number
            return false;
      
      // if scientific notation
         if((toupper(expr[i])=='E') && (i<expr.size())) { // cientific notation 
         // decimal = true; // turn on to detect that are double
            i++; // skip this
            if((i<expr.size()) && ((expr[i]=='+') || (expr[i]=='-')) ) { // if sign
               i++;
            }
         // get the expoent
            while((i<expr.size()) && isdigit(expr[i]))
               i++;
         }
      // now, copy the token and conter to number
      // if decimal is true, the number is double. otherwise, number is integer
      // for this detection, cientific notation need to enable decimal too.
      // The integer value are not used for this package
      
         x = strtod(expr.substr(pos, i-pos).c_str(), 0);
         pos = i;
         return true;
      } // getnumber()
   
       bool mathex::getidentifier(string &name)
      {
         unsigned i = pos;
      
         name.erase();
         if((i>=expr.size()) || (!isalpha(expr[i]) && (expr[i] != '_'))) // not a identifier
            return false;
      
      // identifier
         for(;(i<expr.size()) &&(isalnum(expr[i]) || (expr[i] == '_')); i++);
      
         name = expr.substr(pos, i-pos);
         pos = i; // advance the input
      
         return true;
      } // getidentifier()
   
   
       mathex::PARSERTOKEN::type mathex::nexttoken()
      // Gets the next token from the expr
      {
         string identifier;
      
         while((pos<expr.size()) && isspace(expr[pos]) )
            pos++;
      
         if(pos == expr.size()) {
            curtok.state = PARSERTOKEN::END;
            return curtok.state;
         }
      
         if(getnumber(curtok.value)) {
            curtok.state = PARSERTOKEN::VALUE;
            return curtok.state;
         }
         else if(getidentifier(identifier)) { // if identifier
         // checking the identifier type
            if((curtok.idx = getcfunc(identifier))>=0) // internal C functions
               curtok.state = PARSERTOKEN::FUNCTION;
            else if((curtok.idx=getuserfunc(identifier))>=0) { // user defined functions
               curtok.numargs = functable[curtok.idx].numargs;
               curtok.state = PARSERTOKEN::USERFUNC;
            }
            else if((curtok.idx=getvar(identifier))>=0) // variable
               curtok.state = PARSERTOKEN::VARIABLE;
            else if((curtok.idx=getconst(identifier))>=0) {  // constant are treated as NUMBER
               curtok.state = PARSERTOKEN::VALUE;
               curtok.value = consttable[curtok.idx].value;
            }
            else { // new identifier: not supported
               curtok.state = PARSERTOKEN::INVALID;
            }
         }
         else { // will be operators or delimiters
            switch(expr[pos]) {
               case '+' : curtok.state = PARSERTOKEN::PLUS;
                  break;
               case '-' : curtok.state = PARSERTOKEN::MINUS;
                  break;
               case '*' : curtok.state = PARSERTOKEN::TIMES;
                  break;
               case '/' : curtok.state = PARSERTOKEN::DIVIDE;
                  break;
               case '%' : curtok.state = PARSERTOKEN::MODULE;
                  break;
               case '^' : curtok.state = PARSERTOKEN::POWER;
                  break;
               case ',' : curtok.state = PARSERTOKEN::COMMA;
                  break;
               case '(' : curtok.state = PARSERTOKEN::OPAREN;
                  break;
               case ')' : curtok.state = PARSERTOKEN::CPAREN;
                  break;
               default  : curtok.state = PARSERTOKEN::INVALID;
            } // switch 
            if(curtok.state != PARSERTOKEN::INVALID) {
               curtok.idx = getbinop(expr[pos]);
               pos++;
            }
         } // else
      
         return curtok.state;
      } // nexttoken()
   
   ////////////////////////////
   // CodeStack operations 
   ////////////////////////////
   #ifdef _DEBUG_
    void mathex::printcoderec(CODETOKEN const &token)
   // print the Code Stack status
   {
      switch(token.state) {
      // case CODETOKEN::EMPTY: cout << "EMPTY\n";
      //  break;
         case CODETOKEN::VALUE:
            cout << "VALUE: " << token.value << endl;
            break;
         case CODETOKEN::VARIABLE:
            cout << "VARIABLE: " << vartable[token.idx].name << endl;
            break;
         case CODETOKEN::FUNCTION:
            if(token.idx <NUM_UNARY_OP) 
               cout << "unary operator: " << cfunctable[token.idx].name << endl;
            else
               cout << "FUNCTION: " << cfunctable[token.idx].name << endl;
            break;
         case CODETOKEN::BINOP:
            cout << "binary operator: " << binoptable[token.idx].name << endl;
            break;
         case CODETOKEN::USERFUNC:
            cout << "USERFUNC: " << functable[token.idx].name << endl;
            break;
         default: printf("INVALID\n");
      }
   
   } // printcoderec()
   
    void mathex::printbytecode()
   {
      cout << "codesize = "<< bytecode.size() << endl;
      for(unsigned i=0; i<bytecode.size(); i++)
         printcoderec(bytecode[i]);
   }
   #endif
   
       void mathex::parse()
      // Parse the expression
      {
      // parserstatus = true;
         bytecode.clear();
         status = invalid;
         pos=0;
         nexttoken();
         parsearithmetic1();
      #ifdef _DEBUG_
        printbytecode();
      #endif
         if(curtok.state != PARSERTOKEN::END) // if remain token
            throw error("parse()", "End of expression expected");
         status = parsed;
      } // parse()
   
       void mathex::parsearithmetic1(void)
      // level 1 arithmetic operator: binary plus/minus
      {
         unsigned savedidx; 
         parsearithmetic2();
         while((curtok.state == PARSERTOKEN::PLUS) || (curtok.state == PARSERTOKEN::MINUS)) {
            savedidx = curtok.idx;
            nexttoken();
            if((curtok.state == PARSERTOKEN::PLUS) || (curtok.state == PARSERTOKEN::MINUS)) 
               throw error("parse()", "Invalid expression");
            parsearithmetic2();      
            bytecode.push_back(CODETOKEN(CODETOKEN::BINOP, savedidx));
         } // while
      } // parsearithmetic1
   
   
       void mathex::parsearithmetic2(void)
      // level 2 arithmetic operator: multiplication, division, module
      {
         unsigned savedidx;
         parsearithmetic3();   
         while( (curtok.state == PARSERTOKEN::TIMES) || (curtok.state == PARSERTOKEN::DIVIDE)
           || (curtok.state == PARSERTOKEN::MODULE) ) {
            savedidx = curtok.idx;
            nexttoken();
            if((curtok.state == PARSERTOKEN::PLUS) || (curtok.state == PARSERTOKEN::MINUS)) 
               throw error("parse()", "Invalid expression");
            parsearithmetic3();
            bytecode.push_back(CODETOKEN(CODETOKEN::BINOP, savedidx));
         }
      } // parsearithmetic3
   
       void mathex::parsearithmetic3(void)
      // level 3 arithmetic operator: power
      {
         unsigned savedidx;
         parsearithmetic4();
         if(curtok.state == PARSERTOKEN::POWER) {
            savedidx = curtok.idx;
            nexttoken();
            if((curtok.state == PARSERTOKEN::PLUS) || (curtok.state == PARSERTOKEN::MINUS)) 
               throw error("parse()", "Invalid expression");
            parsearithmetic4();
            bytecode.push_back(CODETOKEN(CODETOKEN::BINOP, savedidx));
         }
      } // parsearithmetic3()
   
       void mathex::parsearithmetic4(void)
      // level 4 arithmetic operator: unary plus/minus
      {
         PARSERTOKEN::type state;
         if(((state=curtok.state) == PARSERTOKEN::PLUS) || (state == PARSERTOKEN::MINUS))
            nexttoken();
         if((curtok.state == PARSERTOKEN::PLUS) || (curtok.state == PARSERTOKEN::MINUS)) 
            throw error("parse()", "Invalid expression");
         parseatom();
      
         if(state == PARSERTOKEN::MINUS) // stored index are for binary operator. Get correct index
            bytecode.push_back(CODETOKEN(CODETOKEN::FUNCTION, getunaryop("-"))); 
      	// unary minus are on function table
      } // parsearithmetic5()
   
       void mathex::parseatom(void)
      // level 6: literal numbers, variables and functions
      {
         unsigned i;
      
      // parentesis expression
         if(curtok.state == PARSERTOKEN::OPAREN) {
            nexttoken();
            if(curtok.state == PARSERTOKEN::CPAREN)
               throw error("parseatom()", "No expression inside parentesis");
            parsearithmetic1();
         
            if(curtok.state != PARSERTOKEN::CPAREN)
               throw error("parseatom()", "\")\" expected");
            nexttoken();  // Added by Hugh Denman (<denmanh@tcd.ie> or hdenman@cantab.net) Oct/03/2003     
         }
         // Number
         else if(curtok.state == PARSERTOKEN::VALUE) { // numbers
            bytecode.push_back(CODETOKEN(curtok.value));
            nexttoken();
         }
         // variables
         else if(curtok.state == PARSERTOKEN::VARIABLE) { // variables
            bytecode.push_back(CODETOKEN(CODETOKEN::VARIABLE, curtok.idx));
            nexttoken();
         }
         // internal C function with one parameters
         else if(curtok.state == PARSERTOKEN::FUNCTION) { // one parameter C functions
            parserstack.push_back(curtok);
            nexttoken();
            if(curtok.state != PARSERTOKEN::OPAREN)
               throw error("parseatom()", "\"(\" expected");
            nexttoken();
            if(curtok.state == PARSERTOKEN::CPAREN) 
               throw error("parseatom()", "invalid number of arguments");
            parsearithmetic1();
            if(curtok.state != PARSERTOKEN::CPAREN)
               throw error("parseatom()", "\")\" expected");
            curtok = parserstack.back();
            parserstack.pop_back();
            bytecode.push_back(CODETOKEN(CODETOKEN::FUNCTION, curtok.idx));
            nexttoken();
         }
         // user defined functions
         else if(curtok.state == PARSERTOKEN::USERFUNC) { // user defined function
            parserstack.push_back(curtok);
            nexttoken();
            if(curtok.state != PARSERTOKEN::OPAREN)
               throw error("parseatom()", "\"(\" expected");
            nexttoken();
            if(curtok.state == PARSERTOKEN::CPAREN)
               i = 0;
            else { // arguments exist
               parsearithmetic1();
               i = 1;
            // while(parserstatus && (curtok.state != PARSERTOKEN::END)
            //        &&(curtok.state != PARSERTOKEN::CPAREN)) {
               while((curtok.state != PARSERTOKEN::END) && (curtok.state != PARSERTOKEN::CPAREN)) {
                  if(curtok.state == PARSERTOKEN::COMMA) {
                     nexttoken();
                     i++;
                  }
                  else 
                     throw error("parseatom()", "unknow error");
                  parsearithmetic1();
               } // while
               if(curtok.state != PARSERTOKEN::CPAREN)
                  throw error("parseatom()", "\")\" expected");
            } // else
            curtok = parserstack.back();
            parserstack.pop_back();
         
            if ((curtok.numargs != UNDEFARGS) && (i != static_cast<unsigned>(curtok.numargs)))
            // i is current number of parameters
               throw error("parseatom()", "invalid number of arguments");
         
         // number of parameters is correct. Now, put the function
         // i is number of arguments    
            bytecode.push_back(CODETOKEN(CODETOKEN::USERFUNC, curtok.idx, i));
         
            nexttoken();
         } // user defined functions
         // End of buffer
         else if (curtok.state == PARSERTOKEN::END)
            throw error("parseatom()", "unexpected end of expression");
         // invalid
         else if (curtok.state == PARSERTOKEN::INVALID)
            throw error("parseatom()", "invalid token on expression");
         // unknow error
         else // it not occur
            throw error("parseatom()", "unknow error");  
      } // parseatom()
   
   
   
   } // namespace smlib {


// end of mathex.c
