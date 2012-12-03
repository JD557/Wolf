Wolf
====

Wolf is a programming language based mostly on cellular automata.

Why? Because turing machines and lambda-calculus are too mainstream.

**Syntax and Semantics**

```
T<start>,<tape>            - Saves the binary string <tape> on the tape starting on <start>
X                          - Clears the tape (resizes it to 0)
R<rule>[<start>,<end>]     - Executes rule <rule> to all elements from <start> to <end>. <rule> must be in binary.
J<line>[<start>,<end>]     - Jumps to <line> if every element from <start> to <end> is equal to 0
C<line>[<start>,<end>]     - Same as J, but puts the next line on the top of the call stack
P                          - Pops the call stack and goes to that line
O[<start>,<end>]           - Outputs the contents from <start> to <end>
S[<start>,<end>]           - Outputs the contents from <start> to <end> as a string
I[<start>,<end>]           - Binary input (saved from <start> to <end>)
F[<start>,<end>]           - String input (saved from <start> to <end>)

Note that all [<start>,<end>] intervals are optional. If an interval is not specified, the whole tape is used
```

**Example Code**

Soon...
