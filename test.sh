#!/bin/zsh

if [ "$1" = "" ]
then
	exit 1;
fi

FILENAME=logfile

pstest()
{
	ARG=$(./randomize $1)
	SOLUTION=$(./push_swap $ARG)
	TOTAL_MOVES=$(echo $SOLUTION | wc -l | tr -s ' ' | cut -d ' ' -f 2)
	echo "$ARG,--->,"$(echo $SOLUTION | ./checker_Mac $ARG)",$TOTAL_MOVES"
}

echo "" > $FILENAME
while true
do
	sleep 0.75
	pstest $1
done

MAX=$(cut -d, -f4 $FILENAME | sort -ru | head -n1)
echo "Max instr: $MAX"
