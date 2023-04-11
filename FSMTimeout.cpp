
#include "FSMTimeout.h"
FSMTimeout::FSMTimeout(const FSMTimeout& m)
{
	flag = m.flag;
	number_of_states = m.number_of_states;
	number_of_inputs = m.number_of_inputs;
	number_of_outputs = m.number_of_outputs;
	number_of_transitions = m.number_of_transitions;
	initial_state = m.initial_state;
	timeoutsystem = new timeout[number_of_states];
	transitionsystem = new transitionTime[number_of_transitions];

	for (unsigned int i = 0; i < number_of_transitions; i++)
		transitionsystem[i] = m.transitionsystem[i];

	for (unsigned int i = 0; i < number_of_states; i++)
		timeoutsystem[i] = m.timeoutsystem[i];
}
FSMTimeout& FSMTimeout::operator=(const FSMTimeout& m)
{
	if (transitionsystem != NULL) delete[] transitionsystem;
	if (timeoutsystem != NULL) delete[] timeoutsystem;
	flag = m.flag;
	number_of_states = m.number_of_states;
	number_of_inputs = m.number_of_inputs;
	number_of_outputs = m.number_of_outputs;
	number_of_transitions = m.number_of_transitions;
	initial_state = m.initial_state;
	timeoutsystem = new timeout[number_of_states];
	transitionsystem = new transitionTime[number_of_transitions];

	for (unsigned int i = 0; i < number_of_transitions; i++)
		transitionsystem[i] = m.transitionsystem[i];

	for (unsigned int i = 0; i < number_of_states; i++)
		timeoutsystem[i] = m.timeoutsystem[i];
	return *this;
}
void FSMTimeout::In(istream &f)
{
	if (transitionsystem != NULL) delete[]transitionsystem;
	if (timeoutsystem != NULL) delete[]timeoutsystem;
	char c;
	unsigned int cn = 0;
	f >> c >> this->flag;
	f >> c >> this->number_of_states;
	f >> c >> this->number_of_inputs;
	f >> c >> this->number_of_outputs;
	f >> c >> c >> this->initial_state;
	f >> c >> this->number_of_transitions;
	transitionsystem = new transitionTime[this->number_of_transitions];
	timeoutsystem = new timeout[number_of_states];
	for (unsigned int i = 0; i < this->number_of_transitions; i++)
	{
		f >> transitionsystem[i].state1;
		f >> transitionsystem[i].input;
		f >> transitionsystem[i].state2;
		f >> transitionsystem[i].output;
		f >> cn;
	}
	int n=0;
	for (unsigned int i = 0; i < this->number_of_states; i++)
	{
		f >> cn;
		f >> n;
		timeoutsystem[i].t = n;
		f >> timeoutsystem[i].state2;
	}
};
void FSMTimeout::Out(ostream& f)
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
		f << transitionsystem[i].output << " ";
		f << 0;
		f << endl;
	}
	for (unsigned int i = 0; i < this->number_of_states; i++)
	{
		f << i << " ";
		f << timeoutsystem[i].t << " ";
		f << timeoutsystem[i].state2 << " ";
		f << endl;
	}
};
void FSMTimeout::Print()
{
	cout << number_of_inputs << endl;
	cout << number_of_outputs << endl;
	cout << number_of_states << endl;
	cout << number_of_transitions << endl;
	cout << initial_state << endl;
	for (unsigned int i = 0; i < number_of_transitions; i++)
	{
		cout << transitionsystem[i].state1 << " " << transitionsystem[i].input << " " << transitionsystem[i].state2 << " " << transitionsystem[i].output << endl;
	}
	for (unsigned int i = 0; i < number_of_states; i++)
	{
		cout << i << " " << timeoutsystem[i].t << " " << timeoutsystem[i].state2 << endl;
	}
}

FSM FSMTimeout::FSMTimeoutToFSM()
{
	unsigned int* instates = new unsigned int[number_of_states];
	unsigned int timesumm = 0, numt = 0;
	for (unsigned int st = 0; st < number_of_states; st++)
	{
		instates[st] = timesumm;
		timesumm = timesumm + timeoutsystem[st].t;
	}
	transition* tmptransitions = new transition[timesumm*(number_of_inputs + 1)];

	for (unsigned int s = 0; s < number_of_states; s++)
	{
		for (int st = 0; st < timeoutsystem[s].t; st++)
		{
			for (unsigned int i = 0; i < number_of_inputs; i++)
			{
				tmptransitions[numt].input = transitionsystem[s*number_of_inputs + i].input;
				tmptransitions[numt].output = transitionsystem[s*number_of_inputs + i].output;
				tmptransitions[numt].state1 = instates[s] + st;
				tmptransitions[numt].state2 = instates[transitionsystem[s*number_of_inputs + i].state2];
				numt++;
			}
			tmptransitions[numt].input = number_of_inputs;
			tmptransitions[numt].output = number_of_outputs;
			tmptransitions[numt].state1 = instates[s] + st;
			if (timeoutsystem[s].t > (st + 1))
			{
				tmptransitions[numt].state2 = instates[s] + st + 1;
			}
			else
			{
				tmptransitions[numt].state2 = instates[timeoutsystem[s].state2];
			}
			numt++;
			
		}
	}
	FSM Abs = FSM(number_of_inputs + 1, number_of_outputs + 1, timesumm, numt, initial_state, 0, tmptransitions);
	delete []tmptransitions;
	return Abs;
}