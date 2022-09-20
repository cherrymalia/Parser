#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVariable(const string &str);
bool isKeyword(const string &str);
bool isOperator(const string &str);
string getOperator(const string &str);
string getSeparator(const string &str);
bool isSeparator(const string &str);
bool isNotLegal(const string &str);
void printRoleOfToken(const vector<string> &list);
void lexicalAnalyze(const string &nameOfFile);

bool expression(vector<string> &list);
bool assignment(vector<string> &list);
bool statement (vector<string> &list);
bool declaration (vector<string> &list);
void printPass(bool &pass);
bool isProgram (vector<string> &list);
#endif /*ANALYZER_H*/