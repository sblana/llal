@echo on
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -o gen.exe generator.c
pause
gen.exe
gen.exe >llal.h
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -c llal.c