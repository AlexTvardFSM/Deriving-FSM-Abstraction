#include "FSM.h"
using namespace std;

void FSM::Print()
{
	cout << "F " << this->flag;
	cout << "\ns " << this->number_of_states << "\ni " << this->number_of_inputs << "\no " << this->number_of_outputs;
	cout << "\nn0 " << this->initial_state << "\np " << this->number_of_transitions;
	cout << endl;
	for (unsigned int i = 0; i < this->number_of_transitions; i++)
	{
		cout << transitionsystem[i].state1 << " ";
		cout << transitionsystem[i].input << " ";
		cout << transitionsystem[i].state2 << " ";
		cout << transitionsystem[i].output;
		cout << endl;
	}
};
FSM::FSM(const FSM& m)
{
	flag = m.flag;
	number_of_states = m.number_of_states;
	number_of_inputs = m.number_of_inputs;
	number_of_outputs = m.number_of_outputs;
	number_of_transitions = m.number_of_transitions;
	initial_state = m.initial_state;

	transitionsystem = new transition[number_of_transitions];
	for (unsigned int i = 0; i<number_of_transitions; i++)
		transitionsystem[i] = m.transitionsystem[i];

}
FSM& FSM::operator = (const FSM& pFSM)
{
	if (number_of_states>0)
	{
		if (number_of_transitions>0) delete[] transitionsystem;
	}

	flag = pFSM.flag;
	number_of_states = pFSM.number_of_states;
	number_of_inputs = pFSM.number_of_inputs;
	number_of_outputs = pFSM.number_of_outputs;
	number_of_transitions = pFSM.number_of_transitions;
	initial_state = pFSM.initial_state;

	transitionsystem = new transition[number_of_transitions];

	for (int i = 0; i<number_of_transitions; i++)
		transitionsystem[i] = pFSM.transitionsystem[i];

	return *this;
};
void FSM::In(istream &f)
{
	if (transitionsystem != NULL) delete[]transitionsystem;
	char c;
	f >> c >> this->flag;
	f >> c >> this->number_of_states;
	f >> c >> this->number_of_inputs;
	f >> c >> this->number_of_outputs;
	f >> c >> c >> this->initial_state;
	f >> c >> this->number_of_transitions;
	transitionsystem = new transition[this->number_of_transitions];
	for (unsigned int i = 0; i < this->number_of_transitions; i++)
	{
		f >> transitionsystem[i].state1;
		f >> transitionsystem[i].input;
		f >> transitionsystem[i].state2;
		f >> transitionsystem[i].output;
	}
};
void FSM::Out(ostream& f)
{
	f << "F " << this->flag;
	f << "\ns " << this->number_of_states << "\ni " << this->number_of_inputs << "\no " << this->number_of_outputs;
	f << "\nn0 " << this->initial_state << "\np " << this->number_of_transitions;
	f << endl;
	for (unsigned int i = 0; i < this->number_of_transitions; i++)
	{
		f << transitionsystem[i].state1 << " ";
		f << transitionsystem[i].input << " ";
		f << transitionsystem[i].state2 << " ";
		f << transitionsystem[i].output;
		f << endl;
	}
};