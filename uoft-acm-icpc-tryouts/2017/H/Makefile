CFLAGS=-std=c++11 -W
input=input.txt

cpp: clear
	g++ ${CFLAGS} H.cpp -o H && ./H < ${input} && rm H 

py: clear
	python3 H.py < ${input}

java: clear
	javac H.java && java H < ${input} && rm H.class

clear:
	clear

