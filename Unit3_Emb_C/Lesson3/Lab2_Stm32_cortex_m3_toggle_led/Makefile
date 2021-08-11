#Copy right:Hassan
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name=learn_in_depth_cortex_m3

all: $(Project_name).bin
	@echo "======Build Is Done======="

%.o: %.c	 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(ASOBJ): $(AS)
	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin