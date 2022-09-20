# Parser
A simple c++ program that takes a file as input and after tokenizing the file it finds what each token name is(identifier, keyword, separator, operator, literal or comment).

## Author
* [Malia Cherry](https://github.com/cherrymalia)


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

2. There are two test files, you can change which one you use by changing the code in main.cpp

test1.txt
```
float test (){
float m;
float q;
float data;
data = m * q / data;
}
```

test2.txt
```
float sub (float x, float y ) {
float z;
z = x * y;
}
```
3. Compile it with:

```
g++ main.cpp analyzer.h analyzer.cpp -std=c++11
```

4. Run it with:
```
./a
```