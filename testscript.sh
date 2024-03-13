#!/bin/bash

gcc maze.c -o maze

echo -e '--Testing Maze Game--'

#test for invalid user input
echo -n "Testing for invalid user input - "
echo "r" | ./maze > out
if grep -q "Error: Invalid input entered" out;
then
    echo "Pass"
else
    echo "Fail"
    cat out
fi

#test for success case through maze using upper case WASD
echo -n "Testing for succcess case through maze upper case - "
./maze "validMaze.txt" < validPathThroughMazeWASD.txt > out
if grep -q "Congratulations! You have won." out;
then
    echo "Pass"
else
    echo "Fail"
fi

#test for success case through maze using lower case wasd
echo -n "Testing for succcess case through maze lower case- "
./maze "validMaze.txt" < validPathThroughMazewasd.txt > out

if grep -q "Congratulations! You have won." out;
then
    echo "Pass"
else
    echo "Fail"
fi

#test for largest possible maze (100x100)
echo -n "Testing largest maze - "
./maze "largestMaze.txt" > out
if grep -q "Please start the game"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test for smallest possible maze (5x5)
echo -n "Testing smallest maze - "
./maze "smallestMaze.txt" > out
if grep -q "Please start the game"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test for a maze too large
echo -n "Testing too large maze - "
./maze "tooLargeMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test for a maze too small
echo -n "Testing too small maze - "
./maze "tooSmallMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test a maze with no start
echo -n "Testing maze with no start - "
./maze "noStartMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test a maze with no end
echo -n "Testing maze with no end - "
./maze "noEndMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#testing an empty maze
echo -n "Testing an empty maze - "
./maze "emptyMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test if maze contains incorrect characters
echo -n "Testing maze with invalid characters - "
./maze "wrongCharacterMaze.txt" > out
if grep -q "Error: Maze not valid"
then
    echo "PASS"
else
    echo "FAIL"
    cat out
fi

#test user can not move through maze walls
echo -n "Testing for user not being able to move through walls - "
./maze "validMaze.txt" < pathThroughWalls.txt > out
if grep -q "Error: Move not valid" out;
then
    echo "Pass"
else
    echo "Fail"
fi

#test user can not fall off edge of maze
echo -n "Testing for user not being able to fall off edge of maze - "
./maze "validMaze.txt" < pathOffEdge.txt > out
if grep -q "Error: Move not valid" out;
then
    echo "Pass"
else
    echo "Fail"
fi

#test if M shows map
echo -n "Testing for M showing map - "
echo "M" | ./maze > out
if grep -q "Here is the map." out;
then
    echo "Pass"
else
    echo "Fail"
    cat out
fi

rm -f out
rm -f maze