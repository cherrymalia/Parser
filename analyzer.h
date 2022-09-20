/**
 * @file analyzer.h
 *
 * @author Malia Cherry
 *
 * @date Sept. 2022
 */

#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/** Functions for lexical analysis
*
* Reads the input file and categorizes the tokens, then prints them
*
* @param str the string to be analyzed
* @param list list of tokens from the file
* @param nameOfFile name of file
*/
bool isVariable(const string &str);
bool isKeyword(const string &str);
bool isOperator(const string &str);
string getOperator(const string &str);
string getSeparator(const string &str);
bool isSeparator(const string &str);
bool isNotLegal(const string &str);
void printRoleOfToken(const vector<string> &list);
void lexicalAnalyze(const string &nameOfFile);

/** Functions for syntax analysis
*
* Checks that the program in the file is syntaxically correct, given the EBNF Demo Language
*
* @param list list of tokens from the file
* @param pass whether the program is syntaxically correct or not
*/
bool expression(vector<string> &list);
bool assignment(vector<string> &list);
bool statement(vector<string> &list);
bool declaration(vector<string> &list);
void printPass(bool pass);
bool isProgram (vector<string> &list);

#endif /*ANALYZER_H*/