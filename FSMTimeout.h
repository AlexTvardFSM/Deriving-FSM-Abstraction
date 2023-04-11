#include "FSM.h"
using namespace std;

struct transitionTime
{
	unsigned int state1;
	unsigned int input;
	unsigned int output;
	unsigned int state2;
};

struct timeout
{
	int t; //еcли таймаут бесконечный, то состояния до и после совпадают и t=1
	unsigned int state2;
};

class FSMTimeout
{
private:
	unsigned int number_of_inputs;
	unsigned int number_of_outputs;
	unsigned int number_of_states;
	unsigned int number_of_transitions;
	unsigned int initial_state;
	transitionTime* transitionsystem;
	timeout* timeoutsystem;
	int flag;
public:
	FSMTimeout() { flag = number_of_inputs = number_of_outputs = number_of_states = number_of_transitions = initial_state = 0; timeoutsystem = NULL; transitionsystem = NULL; };
	FSMTimeout(const FSMTimeout& m);
	void Print();
	FSM FSMTimeoutToFSM();

	void In(istream& f);
	void Out(ostream& f);
	FSMTimeout& operator=(const FSMTimeout& m);
	~FSMTimeout()
	{
		if (transitionsystem != NULL) delete[] transitionsystem;
		if (timeoutsystem != NULL) delete[] timeoutsystem;
	};
	int Flag()
	{
		return flag;
	};
	int NumOfStates()
	{
		return number_of_states;
	};
	int NumOfInputs()
	{
		return number_of_inputs;
	};
	int NumOfOutputs()
	{
		return number_of_outputs;
	};
	int NumOfTransitions()
	{
		return number_of_transitions;
	};
	int Output_for_num(int num)
	{
		return transitionsystem[num].output;
	};
};