#!/bin/zsh

if [ "$1" = "" ]
then
	exit 1;
fi
LINES=$(wc -l $1 | tr -s ' ' | cut -d ' ' -f 2)

echo "" > result
for i in $(seq 1 $LINES)
do
	TEST_SEQ=$(awk "NR==$i {print;}" $1)
	TEST_OUT=$TEST_SEQ"--->"$(./push_swap $TEST_SEQ | ./checker_Mac $TEST_SEQ)
	echo $TEST_OUT >> result
	echo $TEST_OUT
done

grep 'KO' result
