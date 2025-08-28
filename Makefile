CC=g++

CFLAGS=-c -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-security -Wformat=2 -Wignored-qualifiers -Winit-self -Winline -Wlogical-op -Wmain -Wmissing-declarations -Wno-missing-field-initializers -Wmissing-include-dirs -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wswitch-default -Wswitch-enum -Wtype-limits -Wundef -Wunreachable-code -Wwrite-strings -fexceptions -g -pipe -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC

all: SolveSquare

SolveSquare: main.o io.o floating.o unit_test.o solve.o flag_parse.o
	$(CC) main.o io.o floating.o unit_test.o solve.o flag_parse.o -o SolveSquare

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

io.o: io.cpp
	$(CC) $(CFLAGS) io.cpp

floating.o: floating.cpp
	$(CC) $(CFLAGS) floating.cpp

unit_test.o: unit_test.cpp
	$(CC) $(CFLAGS) unit_test.cpp

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp

flag_parse.o: flag_parse.cpp
	$(CC) $(CFLAGS) flag_parse.cpp
