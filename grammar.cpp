//http://www.pltgames.com/competition/2012/12

#include "grammar.h"
#include "system.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<bool> systape;
vector<string> program;
size_t programCounter;

// CFG

void consume(string& in) {in=in.substr(1);}

unsigned long number(string& in) {
	unsigned long ret=0;
	while (in[0]>='0' && in[0]<='9') {ret*=10;ret+=(int)(in[0]-'0');consume(in);}
	return ret;
}

Interval inter(string& in) {
	Interval error={-1,-1};	
	Interval i={0,0};
	if (in[0]=='[') {consume(in);}
	else {i.end=systape.size()-1;return i;}
	i.start=number(in);
	if (in[0]==',') {consume(in);}
	else {return error;}
	i.end=number(in);
	if (i.end<i.start) {return error;}
	if (in[0]==']') {consume(in);}
	else {return error;}
	return i;
}

bool tape(string& in) {
	unsigned int start=number(in);
	string binary_string;
	if (in[0]==',') {consume(in);}
	else {return false;}
	if (start>systape.size()) {systape.resize(start);}
	for (size_t i=start;in.size()>0;++i) {
		if (in[0]=='0' || in[0]=='1') {
			bool val=(bool)(in[0]-'0');			
			consume(in);
			if (i>=systape.size()) {systape.push_back(val);}
			else {systape[i]=val;}
		}
		else if (in.size()>0 && in[0]!='\n' && in[0]!='\r') {return false;}
	}
	return true;
}

bool t(string& in) {
	if (in[0]=='T') {consume(in);}
	else {return false;}
	if (tape(in)) {return true;}
	else {return false;}
}

bool x(string& in) {
	if (in[0]=='X') {consume(in);}
	else {return false;}
	systape.resize(0);
	return true;
}

bool r(string& in) {
	if (in[0]=='R') {consume(in);}
	else {return false;}
	string rule;
	while(in[0]=='0' || in[0]=='1') {rule+=in[0];consume(in);}
	float range=log(rule.length())/log(2);
	if (range!=(int) range) {return false;}
	Interval interv=inter(in);
	if (interv.start<0 || interv.end<0) {return false;}
	vector <bool> newTape=systape;
	for (size_t i=interv.start;i<=interv.end;++i) {
		unsigned long long val=0;
		for (int j=-(range/2);j<=range/2;++j) {
			int pos=(int) i+j;
			if (pos<0) {pos=systape.size()+pos;}
			else if (pos>=systape.size()) {pos=(pos-systape.size());}
			val=val<<1;			
			val+=systape[pos];
		}
		newTape[i]=rule[rule.size()-1-val]-'0';
	}
	systape=newTape;
	return true;
}

bool j(string& in) {
	if (in[0]=='J') {consume(in);}
	else {return false;}
	int newLine=number(in);
	Interval interv=inter(in);
	if (interv.start<0 || interv.end<0) {return false;}
	for (size_t i=interv.start;i<=interv.end;++i) {
		if (systape[i]) {programCounter=newLine-1;return true;}
	}
	return true;
}

bool c(string& in) { // TODO
	if (in[0]=='C') {consume(in);}
	else {return false;}
	return false;
}

bool p(string& in) { // TODO
	if (in[0]=='P') {consume(in);}
	else {return false;}
	return false;
}

bool o(string& in) {
	if (in[0]=='O') {consume(in);}
	else {return false;}
	Interval interval=inter(in);
	if (interval.start<0 || interval.end<0) {return false;}
	cout << "[";
	for (size_t i=interval.start;i<systape.size() && i<=interval.end;++i) {
		cout << systape[i] << ((i==systape.size()-1 || i==interval.end)?"":",");
	}
	cout << "]" << endl;
	return true;
}

bool s(string& in) {
	if (in[0]=='S') {consume(in);}
	else {return false;}
	Interval interval=inter(in);
	if (interval.start<0 || interval.end<0) {return false;}
	cout << "[";
	char accum=0;
	for (size_t i=interval.start;i<systape.size() && i<=interval.end;++i) {
		accum=accum<<1;
		if (systape[i]) {accum|=1;}
		if ((i-interval.start)%8==7) {
			cout << accum << ((i>=systape.size()-8 || i>=interval.end-7)?"":",");
			accum=0;
		}
	}
	cout << "]" << endl;
	return true;
}

bool i(string& in) {
	if (in[0]=='I') {consume(in);}
	else {return false;}
	Interval i=inter(in);
	if (i.start<0 || i.end<0) {return false;}
	cout << "BINARY INPUT:";
	string input;
	getline(cin,input);
	for (size_t j=0;j<input.size();++j) {
		size_t cur_pos=i.start+j;
		if (cur_pos>systape.size()) {break;}
		if (cur_pos>(size_t)i.end) {break;}
		if (input[j]!='0' && input[j]!='1') {break;}
		systape[cur_pos]=(bool)(input[j]-'0');
	}
	return true;
}

bool f(string& in) {
	if (in[0]=='F') {consume(in);}
	else {return false;}
	Interval i=inter(in);
	if (i.start<0 || i.end<0) {return false;}
	cout << "STRING INPUT:";
	string input;
	cin >> input;

	string converted_input;
	for (size_t x=0;x<input.size();++x) {
		for (int y=7;y>=0;--y) {
			converted_input+=((input[x]&(1<<y))!=0?'1':'0');
		}
	}
	for (size_t j=0;j<converted_input.size();++j) {
		size_t cur_pos=i.start+j;
		if (cur_pos>systape.size()) {break;}
		if (cur_pos>(size_t)i.end) {break;}
		if (converted_input[j]!='0' && converted_input[j]!='1') {break;}
		systape[cur_pos]=(bool)(converted_input[j]-'0');
	}
	return true;
}

// Normal line
bool line(string& in) {
	if (t(in) || r(in) || j(in) || c(in) || p(in) || o(in) || s(in) || i(in) || f(in)) {return true;}
	else {return false;}
}
