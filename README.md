pipe.c

This C program demonstrates how to use a pipe to pass messages within a single process.

It defines three fixed-length messages (msg1, msg2, msg3) of 16 bytes.

A pipe is created using pipe(p), giving two file descriptors:

p[1] for writing

p[0] for reading

All three messages are written to the pipe using write().

A loop is used to read the messages from the pipe using read(), and each message is printed with printf().

Although pipes are usually used between parent and child processes, this code demonstrates basic pipe usage within the same process.
