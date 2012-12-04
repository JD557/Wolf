Wolf
====

Wolf is a programming language based mostly on cellular automata.

Why? Because turing machines and lambda-calculus are too mainstream.

Syntax and Semantics
--------------------

```
T<start>,<tape>            - Saves the binary string <tape> on the tape starting on <start>
X                          - Clears the tape (resizes it to 0)
R<rule>[<start>,<end>]     - Executes rule <rule> to all elements from <start> to <end>. <rule> must be in binary.
J<line>[<start>,<end>]     - Jumps to <line> unless every element from <start> to <end> is equal to 0
C<line>[<start>,<end>]     - Same as J, but puts the next line on the top of the call stack
P                          - Pops the call stack and goes to that line
O[<start>,<end>]           - Outputs the contents from <start> to <end>
S[<start>,<end>]           - Outputs the contents from <start> to <end> as a string
I[<start>,<end>]           - Binary input (saved from <start> to <end>)
F[<start>,<end>]           - String input (saved from <start> to <end>)
;<text>                    - Comment

Notes:
   All [<start>,<end>] intervals are optional. If an interval is not specified, the whole tape is used.
   You can use whitespaces at will, they will be ignored.
   You can use T<start>,0 to create a tape with <start>+1 elements
```

**Why so many commands? Isn't rule 110 Turing complete?**

You're right, rule 110 (in this case 0110 1110) is Turing complete (http://www.complex-systems.com/abstracts/v15_i01_a01.html).
So why not just have the T and R commands?

Well, first of all, Input/Output functions are always nice, so the O,S,I and F are needed.

Second, even though it's not necessary, you might want to clear/resize the tape (due to memory constraints and to avoid constantly writing intervals).

Lastly, without any kind of conditional jump, either two things could be done:
* You could apply a rule a finite number of times (and then you could argue that it was not turing complete anymore);
* You could run the rule in an infinite loop (which kind of sucks);
With the J command, this problem is solved.

What about the C and P commands? Thats just a bonus.

Example Code
------------

Examples are availible on the "examples" folder. Here's two of them:

### Hello world:

```
T0,01001000 01000101 01001100 01001100 01001111 00100000 01010111 01001111 01010010 01001100 01000100
S
```

### Sierpinski's Triangle (kind of)

```
T0,0000000000001000000000000 0 000000000000000000000 0 ; Initial tape (Notice the boundaries to avoid reading from the wrong places)
I[26,45] ; Number of iterations as a sequence of 1's (up to 20)
O[0,24] ; Shows a line of the triangle
R00010010[0,24] ; Applies rule 18
R10001000[26,46] ; Decrements the counter
J2[26,46] ; Jumps back to the tirth line (line number 2)
```
