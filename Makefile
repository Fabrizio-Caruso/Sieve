ifneq ($(COMSPEC),)
DO_WIN:=1
endif
ifneq ($(ComSpec),)
DO_WIN:=1
endif 

ifeq ($(DO_WIN),1)
EXEEXT = .exe
endif

ifeq ($(DO_WIN),1)
COMPILEDEXT = .exe
else
COMPILEDEXT = .out
endif

BUILD_PATH ?= ./build


	
## C64 targets	
c64_sieve:
	cl65$(EXEEXT) -t c64 -O --codesize 800 -Cl sieve.c -o $(BUILD_PATH)/sieve.prg
	rm sieve.o

c64_sieve_ptr:
	cl65$(EXEEXT) -t c64 -O --codesize 800 -Cl sieve_ptr.c -o $(BUILD_PATH)/sieve_ptr.prg
	rm sieve_ptr.o

c64_sieve_compressed:
	cl65$(EXEEXT) -t c64 -O --codesize 800 -Cl sieve_compressed.c -o $(BUILD_PATH)/sieve_compressed.prg
	rm sieve_compressed.o


# 	
all: c64_sieve c64_sieve_ptr c64_sieve_compressed
	
clean:
	rm -rf *$(COMPILEDEXT)
	rm -rf *.prg
	rm -rf *.o
	rm -rf *.bin
	rm -rf ./build/*.prg
	rm -rf ./build/*.bin

    


	