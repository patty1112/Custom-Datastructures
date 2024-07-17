First, refactor the code to place function prototypes in a separate header file named calculator_functions.h.
Then, place the corresponding function definitinos in a separate source file named calculator_functions.cpp.
Finally, modify your Makefile to build the calculator_functions.cpp source file.

Build your program.

Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1a. Add a breakpoint inside the print_result() function.
breakpoint set -f calculator_functions.cpp -l 13

1b. What different in how we need to specify the breakpoint compared to L2D?
We need to specify both the file and the line number since we have multiple cpp files. 

2. Run the program, requesting to add 4 and 5
COMMANDS: run 
            4
            5
            a 


3a. Print the stack trace
COMMAND: bt

3b. What's different in how the stack trace is formed compared to L2D?
It specifies which frame you are in and the order, but it also lists the file that was used.

4. Print the current stack frame
COMMAND: frame info

5. Print all local variables and arguments within the scope of the current stack frame
COMMAND: frame variable (I think prints all, on OSX)

6. Move up one level in the stack frame
COMMAND: up

7. Print all local variables and arguments within the scope of the current stack frame
COMMAND: frame variable
8. Continue the program, requesting to subtract the values
COMMANDS: continue 
            s

9. Print the stack trace again
COMMANDS: bt

10. Step through the program until we have moved out of the two lower stack frames
COMMANDS: step 
            step
            step

11. Print the stack trace again
COMMAND: bt

12. Kill the program
COMMAND: kill