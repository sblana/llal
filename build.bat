@echo on
gcc -std=c17 -Wall -Wextra -Wpedantic -o gen.exe generator.c
pause
gen.exe >llal.h
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -c llal.c
gcc -std=c17 -Werror -Wall -Wextra -Wpedantic -c llal.c -D LLAL_USE_STATIC_INLINE