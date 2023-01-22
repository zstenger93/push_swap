#!/bin/bash
random_string=""
for i in {1..500}; do
  random_number=$((RANDOM % 500))
  while [[ ${generated_numbers["$random_number"]} -eq 1 ]]; do
    random_number=$((RANDOM % 500))
  done
  generated_numbers["$random_number"]=1
  random_string="$random_string $random_number"
done

./push_swap $random_string | wc -l
./push_swap $random_string | ./checker_Mac $random_string


# printf '%s\n' "$random_string"
# ./push_swap $rand_num | wc -l
# ./push_swap 2 5 1 3 4 | wc -l