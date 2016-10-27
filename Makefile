main: #simple_main.cpp
	@echo ----------------- compiling simple_main.cpp to create executable program String -----------------
	g++ -g -std=c++11 String.cpp test_string.cpp -o test_string
	g++ -g -std=c++11 String.cpp standard_main.cpp -o standard_main 
clean:
	@echo ----------------- removing executable program simple_main -----------------
	/bin/rm String
	/bin/rm string_test

test:
	create_script String.cpp String
	create_script string_test.cpp string_test
