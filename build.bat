@echo off
set "cstd=-std=c17"
set "wflags=-Wall -Wextra -Wpedantic -Wduplicated-branches -Wduplicated-cond -Wshadow -Wstrict-prototypes -Wdisabled-optimization -Wdouble-promotion -Wconversion"
@echo on
gcc %cstd% %wflags% -o gen.exe generator.c
pause
gen.exe >llal.h
gcc %cstd% %wflags% -c llal.h -D LLAL_IMPLEMENTATION
gcc %cstd% %wflags% -c llal.h -D LLAL_IMPLEMENTATION -D LLAL_USE_STATIC_INLINE
