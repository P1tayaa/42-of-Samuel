#!/bin/sh
# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "${GREEN}Value should be 42${NC}"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "${GREEN}Value should be 42${NC}"
./RPN "7 7 * 7 -"
echo "${GREEN}Value should be 0${NC}"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "${RED}Should Error${NC}"
./RPN "(1 + 1)"
echo "${GREEN}Value should be 2${NC}"
./RPN "1 1 +"
echo "${GREEN}Value should be -4${NC}"
./RPN "-2 2 *"
echo "${GREEN}Value should be 4${NC}"
./RPN "3 1 +"
echo "${GREEN}Value should be 6${NC}"
./RPN "2 3 *"
echo "${GREEN}Value should be 10${NC}"
./RPN "20 2 /"
echo "${GREEN}Value should be 7${NC}"
./RPN "3 4 +"
echo "${GREEN}Value should be -1${NC}"
./RPN "1 2 -"
echo "${GREEN}Value should be 0${NC}"
./RPN "1 1 -"
echo "${GREEN}Value should be 1${NC}"
./RPN "1 1 /"
echo "${GREEN}Value should be -2${NC}"
./RPN "2 2 - 1 - 1 -"
echo "${GREEN}Value should be 10${NC}"
./RPN "2 3 + 2 *"
echo "${GREEN}Value should be 1${NC}"
./RPN "10 3 / 2 -"

echo "${RED}Should Error${NC}"
./RPN "1 2 + +" # Two consecutive operators
echo "${RED}Should Error${NC}"
./RPN "1 +" # Insufficient operands for addition
echo "${RED}Should Error${NC}"
./RPN "+ 1" # Invalid syntax at the beginning
echo "${RED}Should Error${NC}"
./RPN "1 0 /" # Division by zero
echo "${RED}Should Error${NC}"
./RPN "1 2 * * 3 4 / +" # Multiple consecutive operators
echo "${RED}Should Error${NC}"
./RPN "1 2 + 3" # Excessive operands at the end
echo "${RED}Should Error${NC}"
./RPN "1 + 2" # Excessive operators at the end
echo "${RED}Should Error${NC}"
./RPN "1 a +" # Invalid operand
echo "${RED}Should Error${NC}"
./RPN "1 2 3 +" # Excessive operands in the middle