#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVariable(const string &str);
bool isString(const string &str);
bool isLiteral(const string &str);
bool isKeyword(const string &str);
bool isStatement(const string &str);
bool isOperator(const string &str);
bool isSeparator(const string &str);
bool isNotLegal(const string &str);
void printRoleOfToken(const vector<string> &tokens);
void lexicalAnalyze(const string &nameOfFile);

#endif /*ANALYZER_H*/