#include "analyzer.h"

using namespace std;

bool isVariable(const string &str) {
    int counter = 0;
    if (str[0] == '_') {
        counter++;
    }

    for (; counter < str.size(); counter++) {
        if (!(isalpha(str[counter]))) {
            return false;
        }
    }
    return true;
}

bool isString(const string &str)
{
    return str[0] == '"' && str[str.size() - 1] == '"';
}

bool isLiteral(const string &str)
{
    return isString(str);
}

bool isKeyword(const string &str)
{
    const vector<string> keywords{"int", "float", "auto", "double", "do", "switch", "return"};
    for (const auto &keyword : keywords)
        if (keyword == str)
            return true;

    return false;
}

bool isStatement(const string &str)
{
    const vector<string> statements{"for", "while"};
    for (const auto &statement : statements)
        if (statement == str)
            return true;

    return false;
}

bool isOperator(const string &str)
{
    const vector<string> operators{"<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
    //add block to name each lexeme with different token type ("(" = right_paren, ")" = left_paren, etc.)
    for (const auto &op : operators)
        if (op == str)
            return true;

    return false;
}

bool isSeparator(const string &str)
{
    const vector<string> Separators{"{", "}", ",", "(", ")", ";"};
    for (const auto &separate : Separators)
        if (separate == str)
            return true;

    return false;
}

bool isNotLegal(const string &str)
{
    return str == " " || str == "\n";
}

//reformat output, table?
void printRoleOfToken(const string &token)
{
    if (isOperator(token))
        cout << "(operator, " << token << ")\n";
    else if (isSeparator(token))
        cout << "(separator, " << token << ")\n";
    else if (isKeyword(token))
        cout << "(keyword, " << token << ")\n";
    else if (isStatement(token))
        cout << "(statement, " << token << ")\n";
    else if (isLiteral(token))
        cout << "(literal, " << token << ")\n";
    else if (isVariable(token))
        cout << "(variable, " << token << ")\n";
    else
        throw runtime_error("Invalid token: " + token);
}

void lexicalAnalyze(const string &nameOfFile)
{
    char ch;
    string buffer;
    fstream file(nameOfFile, fstream::in);

    if (!file.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    while (file >> noskipws >> ch)
    {
        if (isNotLegal(string(1, ch)))
        {
            if (!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            continue;
        }

        if (isOperator(string(1, ch)) && !isOperator(buffer))
        {
            if (!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
        }

        if (!isOperator(string(1, ch)) && isOperator(buffer))
        {
            printRoleOfToken(buffer);
            buffer = "";
        }

        if (isSeparator(string(1, ch)))
        {
            if (!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            if (isSeparator(string(1, ch)))
            {
                printRoleOfToken(string(1, ch));
                continue;
            }
        }
        buffer += ch;
    }
    file.close();
}