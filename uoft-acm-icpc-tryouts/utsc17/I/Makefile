CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} I.cpp -o I && ./I < ${input} && rm I

py: clear
	python3 I.py < ${input}

java: clear
	javac I.java && java I < ${input} && rm I.class

clear:
	clear

