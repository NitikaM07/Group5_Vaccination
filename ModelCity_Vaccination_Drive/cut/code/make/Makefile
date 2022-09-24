OBJS = main.o
HEAD = header.hpp
PM = main.cpp
FUN = functions.cpp
FL = file.cpp
CL = *.o
G = g++ -o
C = g++ -c
T = test

test: $(OBJS) $(HEAD) 
	$(G) $(T) $(OBJS) -lpthread
	
main.o: $(PM) $(HEAD)
	$(C) $(PM)

functions.o: $(FUN) header.h
	$(C) $(FUN)
	
file.o: $(FL) $(HEAD)
	$(C) $(FL)

clean: 
	rm $(CL)
	rm $(T)
