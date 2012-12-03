//http://www.pltgames.com/competition/2012/12

#include "grammar.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void showHelp() {
	cout << "Wolf: A Cellular Automata based Language" << endl;
	cout << "._______." << endl;
	cout << "| Usage |________________________________________________________________ " << endl;
	cout << "|                                                                        |" << endl;
	cout << "| wolf -i       - Starts the interpreter                                 |" << endl;
	cout << "| wolf <source> - Compiles and executes the file <source>                |" << endl;
	cout << "|________________________________________________________________________|" << endl;
	cout << ".________." << endl;
	cout << "| Syntax |___________________________________________________________________ " << endl;
	cout << "|                                                                            |" << endl;
	cout << "| T<start>,<tape>            - Saves the binary string <tape> on the tape    |" << endl;
	cout << "|                              starting on <start>                           |" << endl;
	cout << "| X                          - Clears the tape                               |" << endl;
	cout << "| R<rule>[<start>,<end>]     - Executes rule <rule> to all elements from     |" << endl;
	cout << "|                              <start> to <end>. <rule> must be in binary.   |" << endl;
	cout << "| J<line>[<start>,<end>]     - Jumps to <line> if every element from <start> |" << endl;
	cout << "|                              to <end> is equal to 0                        |" << endl;
	cout << "| C<line>[<start>,<end>]     - Same as J, but puts the next line on the top  |" << endl;
	cout << "|                              of the call stack                             |" << endl;
	cout << "| P                          - Pops the call stack and goes to that line     |" << endl;
	cout << "| O[<start>,<end>]           - Outputs the contents from <start> to <end>    |" << endl;
	cout << "| S[<start>,<end>]           - Outputs the contents from <start> to <end> as |" << endl;
	cout << "|                              a string                                      |" << endl;
	cout << "| I[<start>,<end>]           - Binary input (saved from <start> to <end>)    |" << endl;
	cout << "| F[<start>,<end>]           - String input (saved from <start> to <end>)    |" << endl;
	cout << "|____________________________________________________________________________|" << endl;
}


// Main
int main(int argc,char* argv[]) { // TODO
	int curLine=0;
	if (argc!=1) {showHelp();return 1;}
	else {
		string temp;
		while (true) {
			cout << curLine << ": ";
			cin >> temp;
			if (!line(temp)) {cerr << "Error on line " << curLine << endl;}
			curLine++;
		}
	}
	return 0;
}
