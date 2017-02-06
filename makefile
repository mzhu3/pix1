main: img.c
	gcc img.c -0 test
run:
	./test
clean:
	rm pic.ppm
	rm *~
	rm *#
