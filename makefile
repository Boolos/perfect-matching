CPP=clang++
CPPFLAGS=-Wall -std=c++11
RM=rm -f
SRCS=edge.cpp edge_set.cpp graph.cpp main.cpp matrix.cpp polynomial.cpp solution.cpp vertex.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: app

tests: 
	$(CPP) $(CPPFLAGS) tests.cpp -o tests.out

app: $(OBJS)
	$(CPP) -o app.out $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CPP) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

include .depend