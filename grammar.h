//http://www.pltgames.com/competition/2012/12

#ifndef _CFG_
#define _CFG_
#include <string>
using namespace std;

struct Interval {
	int start;
	int end;
};

// CFG
void consume(string& in);
unsigned long number(string& in);
Interval inter(string& in);
string binaryString(string& in);
void write(string bin,int start, int end=-1);
bool line(string& in);

bool t(string& in); // T<start>,<tape>            - Saves the binary string <tape> on the tape starting on <start>
bool x(string& in); // X                          - Clears the tape
bool r(string& in); // R<rule>[<start>,<end>]     - Executes rule <rule> to all elements from <start> to <end>. <rule> must be in binary.
bool j(string& in); // J<line>[<start>,<end>]     - Jumps to <line> if every element from <start> to <end> is equal to 0
bool c(string& in); // C<line>[<start>,<end>]     - Same as J, but puts the next line on the top of the call stack
bool p(string& in); // P                          - Pops the call stack and goes to that line
bool o(string& in); // O[<start>,<end>]           - Outputs the contents from <start> to <end>
bool s(string& in); // S[<start>,<end>]           - Outputs the contents from <start> to <end> as a string
bool i(string& in); // I[<start>,<end>]           - Binary input (saved from <start> to <end>)
bool f(string& in); // F[<start>,<end>]           - String input (saved from <start> to <end>)


#endif
