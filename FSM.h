#include <iostream>
#include "time.h"
#include "LongVector.h"
using namespace std;


struct transition
{
	unsigned int state1;
	unsigned int input;
	unsigned int output;
	unsigned int state2;
};
class FSM
{
private:
	unsigned int number_of_inputs;
	unsigned int number_of_outputs;
	unsigned int number_of_states;
	unsigned int number_of_transitions;
	unsigned int initial_state;
	transition* transitionsystem;
	unsigned int flag;
public:
	FSM() { flag = number_of_inputs = number_of_outputs = number_of_states = number_of_transitions = initial_state = 0; transitionsystem = NULL; };
	FSM(unsigned int i, unsigned int o, unsigned int s, unsigned int nt, unsigned int is, unsigned int f, transition* trsystem)
	{
		number_of_inputs = i;
		number_of_outputs = o;
		number_of_states = s;
		number_of_transitions = nt;
		initial_state = is;
		flag = f;
		transitionsystem = new transition[number_of_transitions];
		for (unsigned int i = 0; i < number_of_transitions; i++)
		{
			transitionsystem[i] = trsystem[i];
		}
	};

	FSM(const FSM& m);
	FSM& operator= (const FSM& pFSM);
	void In(istream& f);
	void Out(ostream& f);
	void Print();
	~FSM()
	{
			if (number_of_transitions>0) delete[] transitionsystem;
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

	
};