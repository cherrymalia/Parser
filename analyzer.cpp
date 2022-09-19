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

bool isKeyword(const string &str) {
    string keyword = "float";
    if (keyword == str) {
        return true;
    }
    return false;
}

bool isOperator(const string &str)
{
    const vector<string> operators{"*", "+", "-", "/", "="};
    
    for (const auto &op : operators)
        if (op == str) {
            return true;
        }
    return false;
}

string getOperator(const string &str)
{
    const vector<string> operators{"*", "+", "-", "/", "="};
    
    if (str == operators[0]) {
        return "multiply_op";
    } else if (str == operators[1]) {
        return "app_op";
    } else if (str == operators[2]) {
        return "subtract_op";
    } else if (str == operators[3]) {
        return "divide_op";
    } else if (str == operators[4]) {
        return "assignment_op";
    } else {
        return "not an operator";
    }
}

bool isSeparator(const string &str)
{
    //add block to name each lexeme with different token type ("(" = right_paren, ")" = left_paren, etc.)
    const vector<string> separators{"{", "}", ",", "(", ")", ";"};
    for (const auto &separate : separators)
        if (separate == str)
            return true;

    return false;
}

string getSeparator(const string &str)
{
    const vector<string> separators{"{", "}", ",", "(", ")", ";"};
    if (str == separators[0]) {
        return "left_brace";
    } else if (str == separators[1]) {
        return "right_brace";
    } else if (str == separators[2]) {
        return "comma";
    } else if (str == separators[3]) {
        return "left_paren";
    } else if (str == separators[4]) {
        return "right_paren";
    } else if (str == separators[5]) {
        return "semicolon";
    } else {
        return "not a separator";
    }
}

bool isNotLegal(const string &str)
{
    return str == " " || str == "\n";
}

//prints the lexeme and token type in a table format
void printRoleOfToken(const string &token)
{
    if (isOperator(token))
        cout << token << "                  " << getOperator(token) << "\n";
    else if (isSeparator(token))
        cout << token << "                  " << getSeparator(token) << "\n";
    else if (isKeyword(token))
        cout << token << "              keyword\n";
    else if (isVariable(token))
        cout << token << "                  variable\n";
    else
        throw runtime_error("Invalid token: " + token);
}

//lexical analyzer
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

    cout <<"Lexeme              Token" << endl;
    cout <<"-------------------------------" << endl;
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

/*     //add each token to a vector of tokens and check if it is a program using demo language    
bool isProgram()
{
    return true;
}
*/