# Simple-Shell

A shell is a program that users use to communicate with non user friendly machines.
The shells that are comonly used on Unix are sophisticated interactive programs with several
facilities for customization and speed up. In this assignment you will write a simplified
shell, loosely modeled after sh. The BNF of the language is:
command: list NEWLINE
        | list ’<’ <FNAME> <NEWLINE>
        | list ’>’ <FNAME> <NEWLINE>
        | list ’<’ <FNAME> ’>’ <FNAME> <NEWLINE>
        | list ’>’ <FNAME> ’<’ <FNAME> <NEWLINE>
;
list: expr ’;’ list
        | expr ’&’ list
        | expr
;
expr: pipe AND expr
        | pipe OR expr
        | pipe
;
pipe: simple ’|’ pipe
        | simple
;
simple: cd <FNAME>
        | ’exit’
        | fnamelist
        | <nothing>
        | ’(’ list ’)’
;
fnamelist: <FNAME fnamelist
        | <FNAME>
;
where < and > is redirection, | is pipe, & is asynchronous execution (the second process
starts before the first is done), ; is synchronous execution, || is “or” (the second command
is executed only if the first returns non zero status) and && is “and”. The parser for
this language is given as well as a main program and a routine that prints out the
evaluation tree. You have to write the eval routine that will create the processes, set up
the pipes and do the synchronization. The cd and exit commands will not be executed
in a separate process. Start by reading the following manual pages: fork, execvp, wait,
kill, malloc, open, close, dup, dup2, pipe, strchr, chdir.
  
  
![alt text](screenshots/Diag.png "Description goes here")
