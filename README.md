# AoC
Advent of Code 2022 using C. I have solved both part 1 and 2 of day 1 to 10. I used GCC as compiler for all parts except day 10, where I used Clang. For all parts, Bazel was used as building block. Additionally, a unit test was conducted on day 10 part 1, where Make was used as building block. 

To run the files with Bazel, use the following commands:
```bash
bazel run src/DayXY/DayXYPartZ
```
To run the unit test (with Linux), first compile the C files along with the Unity testing framework and create an executable file:
```bash
gcc -o test_Day10Part1 src/Day10/Day10Part1.c test/TestDay10Part1.c unity/src/unity.c -Isrc/Day10 -Iunity/src
```
Then run the executable file and display the result:
```bash
./test_Day10Part1
```
