Deriving an FSM abstraction from a given FSM with timeouts (TFSM)

The application works with .fsm files (More information are given in the link http://www.fsmtestonline.ru/ ). 
An example of an FSM with timeouts in the .fsm format is in the repository (file 0.fsm). 
In addition to classical FSM transitions, for a TFSM we also specify timeout transitions at states in the form “s1 t s2”, where 
s1 is a starting state of the transition, 
t is timeout value, 
s2 is an end state of the transition.

The application has a single parameter with the name of the given TFSM file.
The application returns the FSM abstraction of the given TFSM as a .fsm file which is created in the same directory as the input file. 
The obtained FSM abstraction file contains a postfix “Abs” in the filename.

Example of running an application:
fsm_abs.exe D:\0.fsm
where 
file 0.fsm contains FSM with timeouts
FSM abstraction file 0Abs.fsm is created in D:\ .

Note: We also provide the code of the tool which is written in C++ and can run under operating system Windows.