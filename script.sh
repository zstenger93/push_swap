#!/bin/bash

# Create an empty file to store the numbers


# Use a for loop to generate 500 random numbers
for i in {1..500}
do
#   # Generate a random number between 0 and 1000
  
  rand_num=$((RANDOM % 500))


#   # Append the number to the file

done

# ./push_swap $rand_num | wc -l
# ./push_swap 2 5 1 3 4 | wc -l
ARG=shuf; ./push_swap $ARG | ./checker_Mac $ARG 
