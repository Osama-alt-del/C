// This is the header file that contains the function declarations

// tell the compiler the declarations so that it can compile obj file, and then link the definitions you want to link together
// if you include everything in a header file, then every single include will have it's own copies of the symbols.
// so make a header file have the delcarations you need to include and then write down all of the definitions in the c file, which you will link later.
// If you want to change something in the main, you still have to compile the ENTIRE header file, along with the definitions, which is bad.  
// sometimes I just want to change 1 thing in main.

int add(int a, int b);

int subtract(int a, int b);

int divide(int a, int b);

int multiply(int a, int b);

