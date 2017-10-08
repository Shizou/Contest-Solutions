CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} A.cpp -o A && ./A < ${input} && rm A 

py: clear
	python3 A.py < ${input}

java: clear
	javac A.java && java A < ${input} && rm A.class

clear:
	clear

