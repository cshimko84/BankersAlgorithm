// Casey Shimko
// CS 33211


To compile

g++ bankers.cpp -o bankers

./bankers input.txt


// EXAMPLE OUTPUT

NP = 5, NR = 3

Allocation table
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 21952032

Max table
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 -858993460
-858993460 -858993460 0

Available resource list
3 3 2

System is safe.
Safe sequence is:
P1 to P3 to P4 to P0 to  P2

// Not sure why the negative numbers are printing or what they are. But the system is safe and prints the safe sequence.
