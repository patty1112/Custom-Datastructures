For this lab, your tasks are as follows.  Provide the answers after each number.  Show your work for each step.

Patrick Maes
Section E
1/19/22


1a. Convert the decimal number 1,904,803,840 to 32-bit two's complement binary representation.

Steps: find the base 2 log of the number and round down. Subtract that magnitude from the previous and repeat until log is even. Then place bits in those place values.

log_2(1,904,803,840) = 30
1,904,803,840 - 2^30 = 831,062,016
log_2(831,062,016) = 29
831,062,016 - 2^29 = 294,191,104
log_2(294,191,104) = 28
294,191,104 - 2^28 = 25,755,648
log_2(25,755,648) = 24
25,755,648 - 2^24 = 8,978,432
log_2(8,978,432) = 23
8,978,432 - 2^23 = 589,824
log_2(589,824) = 19
589,824 - 2^19 = 65,536
log_2(65,536) = 16 (EXACTLY 16)

Bits are placed in the 30, 29, 28, 24, 23, 19, and 16th places.
1A ANSWER: 0011 1000 1100 0100 1000 0000 0000 0000

1b. Represent the value in hexadecimal. 

Steps: Change each group of four to hex
1B ANSWER: 38C4 8000

2a. Convert the decimal number -1,047,986,176 to 32-bit two's complement binary representation.

Steps: First bit is filled since its negative. Find the difference between 2^32 and the given number to find the needed positive part in decimal. Then change the result to binary using the above method.

2^32 - 1,047,986,176 = 3,246,981,120
log_2(3,246,981,120) = 31
3,246,981,120 - 2^31 = 1,099,497,472
log_2(1,099,497,472) = 30
1,099,497,472 - 2^30 = 25,755,648
log_2(25,755,648) = 24
25,755,648 - 2^24 = 8,978,432
log_2(8,978,432) = 23
8,978,432 - 2^23 = 589,824
log_2(589,824) = 19
589,824 - 2^19 = 65,536
log_2(65,536) = 16 (EXACTLY 16)

Bits are placed in the 32, 31, 30, 24, 23, 19, and 16th places
2A ANSWER: 1110 0000 1100 0100 1000 0000 0000 0000

2b. Represent the value in hexadecimal.

Steps: Change each group to hex
2B ANSWER: E0C4 8000

3a. Convert the decimal number 17.125 to 32-bit floating point precsision.

17.125 in binary is   1 0001.001
In scientific notation:  1.0001001 x 2^4
Sign: 0
Exponent: 127+4 = 131 = 1000 0011
Mantissa: 0001001

3A ANSWER: 0100 0001 1000 1001 0000 0000 0000 0000

3b. Represent the value in hexadecimal.

3B ANSWER: 4189 0000


4a. Convert the decimal number -17.125 to 32-bit floating point precision.

Same process as 3a, sign is now negative
Sign: 1
Exponent: 131 = 1000 0011
Mantissa: 0001001

4A ANSWER: 1100 0001 1000 1001 0000 0000 0000 0000 

4b. Represent the value in hexadecimal.

4B ANSWER: C189 0000

5a. Convert the hexadecimal value 0xC3890000 to binary.

12 1 8 9 0 0 0 0 

5A ANSWER: 1100 0011 1000 1001 0000 0000 0000 0000

5b. Convert the binary to a signed decimal integer value using two's complement.

-2^32 + 2^31 + 2^26 + 2^25 + 2^24 + 2^20 + 2^17 =

5B ANSWER: -2,028,863,488

5c. Convert the binary to a floating point decimal value.

1100 0011 1000 1001 0000 0000 0000 0000 

Sign: 1
Exponent: 10000111 - 127= 135 - 127 = 8
Mantissa: 0001001

1.0001001 x 2^8 = 100010010

5C ANSWER: -274


6.  Using a terminal, perform the following steps.  List the commands used to perform the tasks:

- print the current directory you are in when the terminal opens

COMMAND: pwd


- move into the lab1b_folder directory

COMMAND: cd .\lab1b_folder\

- list the contents of the directory

COMMAND: ls

- move into the data directory

COMMAND: cd.\data\

- rename the misspelled file fil2.txt to be file2.txt

COMMAND: mv .\fil2.txt .\file2.txt 

- copy file1.txt to be file3.txt

COMMAND: cp .\file1.txt .\file3.txt

- make a new file named file4.txt

COMMAND: ni .\file4.txt


- move to the parent directory

COMMAND: cd..

- make a directory named bin

COMMAND: mkdir .\bin

- compile main.cpp into an executable

COMMAND: g++ main.cpp

- move the generated executable into the bin folder and rename it to be lab1b

COMMANDS: mv .\a.exe .\bin\
          cd bin  
          mv .\a.exe .\lab1b.exe

- print the current directory you are currently in

COMMAND: pwd


- run the new executable from your current directory

COMMAND: .\lab1b.exe

What to submit?
Submit this README.txt with the completed responses.
