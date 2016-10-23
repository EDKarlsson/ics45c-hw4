main: #simple_main.cpp
	@echo ----------------- compiling simple_main.cpp to create executable program String -----------------
	g++ -ggdb -std=c++11 String.cpp string_test.cpp -o string_test

clean:
	@echo ----------------- removing executable program simple_main -----------------
	/bin/rm String
	/bin/rm string_test

test:
	create_script String.cpp String
	create_script string_test.cpp string_test
