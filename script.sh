#!/bin/bash



random_string=""
for i in {1..500}; do
  # Generate a random number between 0 and 499
  random_number=$((RANDOM % 500))

  # Check if the number has already been generated
  while [[ ${generated_numbers["$random_number"]} -eq 1 ]]; do
    # Generate a new number if it has
    random_number=$((RANDOM % 500))
  done

  # Mark the number as generated
  generated_numbers["$random_number"]=1

  # Append the number to the string
  random_string="$random_string $random_number"
done
# printf '%s\n' "$random_string"
# ./push_swap $rand_num | wc -l
# ./push_swap 2 5 1 3 4 | wc -l
printf "\n"
./push_swap $random_string | wc -l
./push_swap $random_string | ./checker_Mac $random_string