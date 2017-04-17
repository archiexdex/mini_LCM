
hw2.so: inject.c
	gcc -o $@ -shared -fPIC $< -ldl
