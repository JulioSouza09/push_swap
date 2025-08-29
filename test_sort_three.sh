#!/bin/sh

echo "0 1 3"
ARG="0 1 3"; ./push_swap $ARG | ./checker_linux $ARG
echo ""

echo "0 3 1"
ARG="0 3 1"; ./push_swap $ARG | ./checker_linux $ARG
echo ""

echo "1 0 3"
ARG="1 0 3"; ./push_swap $ARG | ./checker_linux $ARG
echo ""

echo "1 3 0"
ARG="1 3 0"; ./push_swap $ARG | ./checker_linux $ARG
echo ""

echo "3 0 1"
ARG="3 0 1"; ./push_swap $ARG | ./checker_linux $ARG
echo ""

echo "3 1 0"
ARG="3 1 0"; ./push_swap $ARG | ./checker_linux $ARG
echo ""
