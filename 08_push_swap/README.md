**run**

ARG=$(printf '%s ' `seq 0 100 | sort -R`); ./push_swap $ARG | ./checker $ARG
to get numbers from 0 to 100 in random order

**or**

bash push_swap_test.sh and follow the instructions

**Visualizer**

add -v (./checker -v $ARG) for minilibx visualizer
