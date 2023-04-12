FSM abstraction synthesis applications for FSM with timeouts

The application works with .fsm files (More information on the link http://www.fsmtestonline.ru/ ). 
An example of an FSM with timeouts in the .fsm format is in the repository (file 0.fsm). 
Unlike the classical FSM, it contains 3-tuples in the form “s1 t s2”, where 
s1 is a starting state, 
t is timeout value, 
s2 is an end state.
The application has a single parameter with the name of the timed FSM file.
The application returns the result as a .fsm file which is created in the same directory as the input file. 
The file with abstraction contains a postfix “Abs” in the filename.
Example of running an application:
fsm_abs.exe D:\0.fsm
where 
file 0.fsm contains FSM with timeouts
FSM abstraction file 0Abs.fsm is created in D:\ .
