shell: \
			main.o \
			launch.o \
			parse_line.o \
			built.o \
			execute.o \
			func_ls.o \
			pinfo.o \
			read_line.o \
			remindme.o \
			semicolon.o \
			shell_clock.o \
			shell_prompt.o \
			check_back.o \
			redirection.o \
			piping.o \
			env_var.o \
			jobs.o \
			fg_bg.o \
			overkill.o \
			exitHandler.o
	$(CC) -g -o shell $^

clean:
	@rm -f *.o shell

main.o: header.h main.c
	$(CC) -g -c main.c

launch.o: header.h launch.c
	$(CC) -g -c launch.c

parse_line.o: header.h parse_line.c
	$(CC) -g -c parse_line.c

built.o: header.h built.c
	$(CC) -g -c built.c

execute.o: header.h execute.c
	$(CC) -g -c execute.c

func_ls.o: header.h func_ls.c
	$(CC) -g -c func_ls.c

pinfo.o: header.h pinfo.c
	$(CC) -g -c pinfo.c

read_line.o: header.h read_line.c
	$(CC) -g -c read_line.c

remindme.o: header.h remindme.c
	$(CC) -g -c remindme.c

semicolon.o: header.h semicolon.c
	$(CC) -g -c semicolon.c

shell_clock.o: header.h shell_clock.c
	$(CC) -g -c shell_clock.c

shell_prompt.o: header.h shell_prompt.c
	$(CC) -g -c shell_prompt.c

check_back.o: header.h check_back.c
	$(CC) -g -c check_back.c

redirection.o: header.h redirection.c
	$(CC) -g -c redirection.c

piping.o: header.h piping.c
	$(CC) -g -c piping.c

env_var.o: header.h env_var.c
	$(CC) -g -c env_var.c

jobs.o: header.h jobs.c
	$(CC) -g -c jobs.c

fg_bg.o: header.h fg_bg.c
	$(CC) -g -c fg_bg.c

overkill.o: header.h overkill.c
	$(CC) -g -c overkill.c

exitHandler.o: header.h exitHandler.c
	$(CC) -g -c exitHandler.c
