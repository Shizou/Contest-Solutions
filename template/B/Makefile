CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} B.cpp -o B && ./B < ${input} && rm B

py: clear
	python3 B.py && < ${input}

java: clear
	javac B.java && java B < ${input} && rm B.class

clear:
	clear

