main: img.c
	gcc img.c -o test
run:
	./test
clean:
	rm pic.ppm
	rm test
	rm *~
	rm *#
