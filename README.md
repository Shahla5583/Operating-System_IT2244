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

## d20_HW.c
![image](https://github.com/user-attachments/assets/e22065e2-1cab-4a5e-bf3c-7be30e3eda04)
