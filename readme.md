C- Shell

To run:
make clean
make
./shell

Files:

1) main.c -> Contains the main loop of the Shell.
2) launch.c -> Contains function for directing the functions for each command
3) parse_line -> Breaks the line into words taking space as delimiter.
4) built.c -> Functions for builtin commands.
5) execute.c -> function to execute all commands except specified in the assignment.
6) func_ls.c -> function for executing ls command.
7) pinfo.c -> function for pinfo command
8) read_line.c -> read the input line character by character.
9) remindme.c -> function for remindme(BONUS)
10) semicolon.c ->function that separate command using semicolon as delimiter.
11) shell_clock.c -> displays the current time and date.(BONUS)
12)shell_prompt.c -> prompt function.
13)check_back.c -> checks if the background process has terminated or not. 
14)jobs -> functions for jobs and kjobs
15) piping.c -> function for pipe command
16) redirection.c -> function for redirection command
17)env_var.c -> conatins function for setting and unsetting environmnet variable.
18)fg_bg.c -> function for fg and bg command.

