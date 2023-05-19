#!/bin/bash


NORM=$(norminette get_next_line*)
# echo "$NORM"

# if norminette get_next_line.h == KO then print the error
# if norminette get_next_line.h == OK then dont print anything
# here the if check is for all get_next_line files 

for file in $(ls get_next_line* | sort)
do
	output=$(norminette $file)
	if [[ "$output" == *"Error"* ]]; then
		# if "Error" is present in the output then print the file name and error
		echo "File: $file"
		echo "Errors:"
		echo "$output | grep Error"
		echo " " # print a blank line
	fi
done
