# Chain-Reaction-Simulation
A C++ program to illustrate the chain reactions involved in a nuclear fission like simulation experiment. 
The description of the experiment is as follows:
The setting for the experiment is a large cubical box, the bottom of which is completely covered with 625 mousetraps 
arranged to form a square with GRID_SIZE = 25 mousetraps on a side. Each of the mousetraps is initially loaded with 
two ping-pong balls. At the beginning of the simulation, an additional ping-pong is released from the top of the box 
and falls on one of the mousetraps. That mousetrap springs and shoots its two ping-pong balls into the air. 
The ping-pong balls bounce around the sides of the box and eventually land on the floor, where they are likely to set off more mousetraps.
In this simulation, the following assumptions have been made:
• Every ping-pong ball that falls always ands on a mousetrap, chosen randomly by selecting a random row and column in the grid. 
If the trap is loaded, its balls are released into the air. If the trap has already been sprung, having a ball on it has no effect.
• Once a ball falls on a mousetrap, that ball stops and takes no further role in the simulation.
• Balls launched from a mousetrap bounce around the room and land again after a random number of simulation cycles have gone by. 
That random interval is chosen independently for each ball is always between MIN_CYCLES = 1 and MAX_CYCLES = 4 cycles.
The simulation runs until there are no balls in the air.
At that point, the program reports how many time units have elapsed since the beginning, 
what percentage of the traps have been sprung, and the maximum number of balls in the air at any time in the simulation.
