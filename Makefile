#Defining the Executable
#
exec = bpl.out

#Defining where out source files are
#It is because our source files are going to be inside the src directory,
#and they have the extention .c
sources = $(wildcard src/*.c)

#Defining how we are creating the oblects (.o files)
#object files are the files that the compiler creates and links them together to create the executable. 
#renaming the .c extentions to .o extentions
objects = $(sources:.c=.o)

#Flags for out compiler
flags = -g 

#creating the executable
$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

#Creating the .o files
#Whenever it detects s change in our source files (.c), it is going to recreate the object files. 
%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@


#to make our executable (.out) globally accesable in out system, we need to:
#1. make the code
#2. copy the ececutable in the proper directory
#NOTE: Please use "sudo" while executing this command
install:
	make
	cp ./bpl.out /usr/local/bin/bpl

#Recompile everything from scratch.
#remove every .out file
#remove the .o files (object files) and .o files from the src/ directory
clean:
	-rm *.out 
	-rm *.o
	-rm src/*.o
