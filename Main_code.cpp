#include <iostream>
#include <fstream>
#include <string>
#include "FSMTimeout.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <sstream> 

using namespace std;
bool main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 0;
	}
	else
	{
		FSMTimeout TFSM;
		FSM Abstraction;
		ifstream in(argv[1]);
		TFSM.In(in);
		in.close();
		Abstraction = TFSM.FSMTimeoutToFSM();
		string str = argv[1];
		str.erase(str.size()-4, str.size());
		str.append("Abs.fsm");
		ofstream out(str);
		Abstraction.Out(out);
		out.close();
		return 1;
	}
}