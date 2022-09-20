# Parser
A C++ program that takes a file as input, identifies what token type the lexeme in the file are, and prints them out. It then uses the EBNF Demo Language to check if the file is a syntaxically correct program.

## Author
* [Malia Cherry](https://github.com/cherrymalia)

## The EBNF Demo Language
```
<program>   ->    <keyword><ident>() {<declares><stmts>}
<declares>  ->    <keyword><ident> ;
            |     <keyword><ident> ; <declares>
<stmts>     ->    <assign> ; <stmts>
            |     <assign> ;
<assign>    ->    <ident> = <expr>
<expr>      ->    <ident> {*|/} <expr>
            |     <ident> 
            |     (<expr>)
keyword     ->    float
ident       ->    a<ident>|b<ident>...|z<ident>
```
### Get Started

Use the following to compile the code
```
sudo apt-get install g++
```

### Running

1. Clone the repository:
```
git@github.com:cherrymalia/Parser.git
```

2. There are two test files. You can change which one you use by changing the code in main.cpp

3. Compile it with:

```
g++ main.cpp analyzer.h analyzer.cpp -std=c++11
```

4. Run it with:
```
./a
```