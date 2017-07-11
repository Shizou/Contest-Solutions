CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} C.cpp -o C && ./C < ${input} && rm C

py: clear
	python3 C.py && < ${input}

java: clear
	javac C.java && java C < ${input} && rm C.class

clear:
	clear

