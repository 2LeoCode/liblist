#!/bin/bash

bar_total=25 #needs to be a multiple of 100
suffix=$(cat Makefile | grep -h "\.SUFFIXES =" | awk '{print $3}')
srcd=$(cat Makefile | grep -h "SRCD =" | awk '{print $3}')

total=$(ls $srcd/*$suffix | wc -l | tr -d ' ')
count=$(($total - `cat file.count`))
percent=$((100 * $count / $total))
bar_count=0

printf "\r\033[2KCompiling ["
while [[ $percent -gt 0 ]]
do
	printf "-"
	bar_count=$(($bar_count + 1))
	percent=$(($percent - 100 / $bar_total))
done
while [[ $bar_count -lt $bar_total ]]
do
	printf " "
	bar_count=$(($bar_count + 1))
done
printf "]"
cat file.count > tmp.txt
rm -f file.count
echo $((`cat tmp.txt` - 1)) > file.count
rm -f tmp.txt
