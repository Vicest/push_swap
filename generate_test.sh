#!/bin/sh

LANG=C

if [ $(($#)) != 3 ]
then
	echo "Usage:	./generate_tesy.sh <range_size> <range_min> <range_max>
	
	range_size: Number of elements to generate.
	range_min: Minimum value in the number set.
	range_max: Maximum value in the number set.
	"
	exit 1
elif [ $(($1 < $(($3 - $2)) )) ]
then
	echo "Error: Range size too big for min and max provided."
	exit 1
fi

NUM=`tr -cd 0-9 < /dev/urandom | head -c 12`
echo $NUM
