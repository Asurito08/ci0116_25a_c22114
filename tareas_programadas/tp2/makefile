target: bin/programa

bin/programa: 
	mkdir -p bin
	g++ source/main.cpp -o bin/programa

run: bin/programa
	./bin/programa

doc:
	doxygen Doxyfile

opendoc: doc
	xdg-open doc/html/index.html

clean: 
	rm -rf bin doc