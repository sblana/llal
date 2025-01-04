@echo on
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -o gen.exe generator.c
gen.exe
gen.exe >llal.h
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -o llal.o llal.h