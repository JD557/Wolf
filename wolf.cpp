//http://www.pltgames.com/competition/2012/12

#include "system.h"
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
	cout << "|                              <start> to <end>. <rule> must be in binary    |" << endl;
	cout << "| J<line>[<start>,<end>]     - Jumps to <line> unless every element from     |" << endl;
	cout << "|                              <start> to <end> is equal to 0                |" << endl;
	cout << "| C<line>[<start>,<end>]     - Same as J, but puts the next line on the top  |" << endl;
	cout << "|                              of the call stack                             |" << endl;
	cout << "| P                          - Pops the call stack and goes to that line     |" << endl;
	cout << "| O[<start>,<end>]           - Outputs the contents from <start> to <end>    |" << endl;
	cout << "| S[<start>,<end>]           - Outputs the contents from <start> to <end> as |" << endl;
	cout << "|                              a string                                      |" << endl;
	cout << "| I[<start>,<end>]           - Binary input (saved from <start> to <end>)    |" << endl;
	cout << "| F[<start>,<end>]           - String input (saved from <start> to <end>)    |" << endl;
	cout << "| ;<text>                    - Comment                                       |" << endl;
	cout << "|____________________________________________________________________________|" << endl;
}

string cleanInput(string s) {
	string ret="";
	for (size_t i=0;i<s.size();++i) {
		if (s[i]==';') {break;}
		if (s[i]!=' ') {ret+=s[i];}
	}
	return ret;
}

// Main
int main(int argc,char* argv[]) {
	programCounter=0;
	bool interpreter;
	if (argc!=2) {showHelp();return 1;}
	else if (argv[1][0]=='-' && argv[1][1]=='i') {interpreter=true;}
	else {
		interpreter=false;
		ifstream file(argv[1]);
		string tempstring="";
		while (getline(file,tempstring)) {program.push_back(tempstring);}
	}
	string command;
	while (true) {
		if (interpreter) {cout << programCounter << ": ";}
		if (interpreter && programCounter==program.size()) {
			getline(cin,command);
			program.push_back(command);
		}
		else if (programCounter<program.size()) {
			command=program[programCounter];
			if (interpreter) {cout << command << endl;}
		}
		else {cout << "TERMINATED" << endl;break;}
		command=cleanInput(command);
		if (!line(command)) {cerr << "Error on line " << programCounter << endl;}
		programCounter++;
	}
	return 0;
}
