1. I structured my player with an integer indentifier and a number of chips. 
This had a defult constructor that set chips to 3 and the player number to 1. 
Most functions for the players was just changing the number of chips.

2. I structured my game as a class that contained a pointer to the current player. 
It also stored which direction the game is moving in along with functions to change and get the values.
The game was a CircularlyLinkedList of course, so moving clockwise was the next player,
and counterclockwise is the previous.

3. I used the classes to make functions for a CircularlyLinkedList, but specific to the game structure.
There was linked lists of the players in number order, as well as the number of turns. 
The number of turns was passed by reference, while the game and player lists were not.
This was because I wanted new lists of players for each simulation instead of adding more 
players to the original player list. Another way I could have done this is with an explicit 
destructor but the stack handles it well.

Extra Credit Simulation Table:

(Each used 1000 simulations, # of turns is the average)
# of Players | # of Turns
-------------|------------
    2        |      8.309 turns
    3        |      25.152 turns
    4        |      40.361 turns
    5        |      54.93 turns
    10       |      124.896 turns
    20       |      262.33 turns

1. Even after simulating 100 games for 2 players, the average did change by up to 1 unit
each time. Im sure 1000 is not where the average stablizes, and a guess within 1 turn of
the actual average is not too bad. However, running 1000 trials will give you a value that
changes by only a few tenths from different excecutions.

2. The number of turns compared to players seems to be something else than exponential or linear.
If it was linear, the differences in turn values would all be the same for 1 unit increases in players.
If it was exponential, the ratios between the differences turns will be the same which they are not.
The ratios rage from 3x to 1.6x in some cases which is not close to constant.
Last, if it was quadratic, the second differences between the turns would be the same.
However they are not in the case of 3, 4, and 5, where the first differences are the same.