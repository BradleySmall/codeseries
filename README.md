codeseries
==========
Lock Combination Generator
A lock combination manufacturer needs to maintain a database of all
possible combinations for their locks. You are tasked with writing a
program that generates all possible legal combinations within the rules
set by the manufacturer.

Rules
- Values for a position: A,B,C,D,E
- Number of positions: 6
- Adjacent positions cannot differ by more than 2 (AC and BD are
valid adjacent positions; AD is not)
- No more than 3 contiguous positions can have the same value (AAA is
OK, AAAA is not)
- No more than 4 of the same value can be in a combination (AABBAA is
OK, AAABAA is not)

The manufacturer wants to allow for future expansion, so the number and
values of positions must be configurable. (So, your program should be
able to handle values up to A-Z, and it should be able to handle 8
positions, or 10, or even more.) The manufacturer will assign a lookup
code (starting with 1 and incrementing) to each combination. However,
the collection of combinations needs to be randomly shuffled before
assigning the lookup codes to them. The output should look something
like this:

1: ABABAC
2: CDCDCA
3: ABCDEA
...

When writing your code, be sure to utilize proper object-oriented
techniques and design. Show appropriate use of class construction.
