pipe.c

This C program demonstrates how to use a pipe to pass messages within a single process.

It defines three fixed-length messages (msg1, msg2, msg3) of 16 bytes.

A pipe is created using pipe(p), giving two file descriptors:

p[1] for writing

p[0] for reading

All three messages are written to the pipe using write().

A loop is used to read the messages from the pipe using read(), and each message is printed with printf().

Although pipes are usually used between parent and child processes, this code demonstrates basic pipe usage within the same process.


## pipe.c
![image](https://github.com/user-attachments/assets/c3f1fa83-5bb4-4582-b470-d16596a2321d)

## exercise.c
![image](https://github.com/user-attachments/assets/2e2c381c-46ed-4abe-a8db-1ff24ac43012)

## ex.c


[2021ict126@fedora ~]$ vi exl.c
[2021ict126@fedora ~]$ gcc exl.c -o exl
[2021ict126@fedora ~]$ ./exl
Area Calculation Program
Choose a shape:
1. Circle
2. Rectangle
3. Square
4. Triangle
Enter your choice (1-4): 1
Enter radius: 4
Area of Circle = 50.27
[2021ict126@fedora ~]$ ./exl
Area Calculation Program
Choose a shape:
1. Circle
2. Rectangle
3. Square
4. Triangle
Enter your choice (1-4): 2
Enter length: 3
Enter width: 6
Area of Rectangle = 18.00
[2021ict126@fedora ~]$ ./exl
Area Calculation Program
Choose a shape:
1. Circle
2. Rectangle
3. Square
4. Triangle
Enter your choice (1-4): 3
Enter side length: 7
Area of Square = 49.00
[2021ict126@fedora ~]$ ./exl
Area Calculation Program
Choose a shape:
1. Circle
2. Rectangle
3. Square
4. Triangle
Enter your choice (1-4): 4
Enter base: 6
Enter height: 2
Area of Triangle = 6.00


