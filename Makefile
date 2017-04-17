
hw2.so: hw2_obj
	objcopy -R .comment -R .note.ABI-tag -R .gnu.version $< hw2.so

hw2_obj: hw2_strip
	strip $< -o hw2_obj

hw2_strip: inject.c
	gcc -o $@ -shared -fPIC $< -ldl
clean: 
	rm hw2_strip hw2_obj
