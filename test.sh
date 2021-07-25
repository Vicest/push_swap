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
	LOG_LINE=$ARG",--->,"$(echo $SOLUTION | ./checker_Mac $ARG)",$TOTAL_MOVES"
	echo $LOG_LINE >> $FILENAME
}

echo "" > $FILENAME
for i in {1..50}
do
	pstest $1
done

MAX=$(cut -d, -f4 $FILENAME | sort -ru | head -n1)
echo "Max instr: $MAX"
