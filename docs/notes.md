There is a scenario where we need to handle what the binary does for eg:
* cat will take input argument and print to stdout.
* tee will take input argument as well as stdin and write to file and stdout.

So depending on the binary we will need to handle inputs and outputs.
How do we get this information?

If we cannot use system but can use execvp, can't we just use excecvp to use
`/bin/sh` to execute the whole complex command.

We can but the point of the exercise is to teach us fork, dup2 etc. Also, the
professor said that a bash string cannot handle all the cases of using pipes. A
flow diagram can represent more complex flows. Not sure what he means by this as
I have yet to find a flow file that cannot be represented by a bash string.

I need to keep track of the names and the corresponding object.
In C, I will use arrays and a linear search instead of implementing a hash
table.



