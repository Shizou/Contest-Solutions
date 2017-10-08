CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} F.cpp -o F && ./F < ${input} && rm F

py: clear
	python3 F.py < ${input}

java: clear
	javac F.java && java F < ${input} && rm F.class

clear:
	clear

