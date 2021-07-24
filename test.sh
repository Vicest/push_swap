#!/bin/sh

ARG=$(./randomize $1)
echo $ARG
./push_swap $ARG
