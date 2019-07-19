# Counting and Roman's sort
A counting sort and it's variation called Roman's sort

## Roman's sort
Roman's sort is a variation of the counting sort that doesn't need the final array/structure in which we write sorted values as it writes back to the original array. While it doesn't improve the time complexity it can still improve the sorting process in real world situations because it reduces the need for additional memory, thus making the sorting faster.

This change however makes the algorithm from stable to unstable meaning it shifts even the numbers with the same value.

It originated after a class of algorithms in which a professor finished teaching the Counting sort and a student named Roman came up to him and suggested he could do it in a better way

## Counting Sort

Counting sort is an algorithm in which we sort numbers from `array A` by counting the occurences of each one and saving those values on their respective index in a new `array B` and doing a prefix-sum of array C. We then start from the last `index` of `array C` and write the value of `A[index]` to the position of `C[A[index]]` of the final `array B` --- (`B[C[A[index] = A[index]`). 

Lastly we decrease the read value of `C[A[index]]` and move index one place down (`index--`).

## How to use

Compile the program with and run it with two arguments. First argument is the number 0 or 1 depending on which sort you want to use. Second arugment is the path to a text file with the numbers you want to sort.

`in.txt` and `out.txt` are included as the examples as input and output files
