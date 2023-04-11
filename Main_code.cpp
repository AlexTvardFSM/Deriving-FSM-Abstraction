#include <iostream>
#include <fstream>
#include <string>
#include "FSMTimeout.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <sstream> 

using namespace std;
void main()
{
	//example
	FSMTimeout TFSM;
	FSM Abstraction;
	ifstream in("0.fsm");
	TFSM.In(in);
	in.close();
	Abstraction = TFSM.FSMTimeoutToFSM();
	ofstream out("1.fsm");
	Abstraction.Out(out);
	out.close();
}