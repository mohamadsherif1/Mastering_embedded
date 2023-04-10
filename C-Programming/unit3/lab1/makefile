#prepared by Mohamad sherif

CC=arm-none-eabi-
CFlAGS=-mcpu=arm926ej-s  -g
INCS =-I .
LIBS=

startup.o: startup.s
		$(CC)as.exe $(CFlAGS) startup.s -o startup.o 2> log

app.o: app.c
		$(CC)gcc.exe $(CFlAGS) $(INCS) -c app.c -o app.o 

uart.o: uart.c
		$(CC)gcc.exe $(CFlAGS) $(INCS) -c uart.c -o uart.o 

learn-in-depth.elf: uart.o app.o startup.o
		$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o app.o uart.o  -o learn-in-depth.elf -Map=Map_file.map
		
learn-in-depth.bin: learn-in-depth.elf
		$(CC)objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin