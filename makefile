$(V).SILENT:

LINUX_MAKEFILE = makefile.lnx
WINDOWS_MAKEFILE = makefile.win

CREATE_DIR_COMMAND = mkdir
REMOVE_DIR_COMMAND = rm -rf
REMOVE_FILE_COMMAND = rm -f

COMPILE_DIR = bin
TMP_DIR = tmp

win:
	make -sf makefile.win

	$(eval REMOVE_DIR_COMMAND := rmdir /S /Q)
	$(eval REMOVE_FILE_COMMAND := del /S /Q)
	$(eval CREATE_DIR_COMMAND := mkdir )

lnx:
	make -sf makefile.lnx

	$(eval REMOVE_DIR_COMMAND := rm -rf)
	$(eval REMOVE_FILE_COMMAND := rm -f)
	$(eval CREATE_DIR_COMMAND := mkdir -p)

create_dirs:
	$(CREATE_DIR_COMMAND) bin

clear:
	$(REMOVE_DIR_COMMAND) $(COMPILE_DIR)

all: clear create_dirs compile_programs dice_throw

compile_programs: coin_flip pass_gen

coin_flip:
	gcc "Coin Flip/coin_flip.c" -o ./${COMPILE_DIR}/coin_flip

pass_gen:
	gcc "Password Generator/pass_gen.c" -o ./${COMPILE_DIR}/pass_gen

dice_throw:
	gcc "Dice Throw/dado.c" -c -o bin/dado.o -Wall
	gcc "Dice Throw/dice_throw.c" ./${COMPILE_DIR}/dado.o -o ./${COMPILE_DIR}/dice_throw
