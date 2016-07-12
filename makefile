CPP=clang++
CPPFLAGS=-Wall -std=c++11 -stdlib=libc++
RM=rm -f
SRCS=edge.cpp edge_set.cpp graph.cpp matrix.cpp polynomial.cpp solution.cpp vertex.cpp
TEST_SRCS=tests.cpp polynomial_tests.cpp edge_tests.cpp edge_set_tests.cpp matrix_tests.cpp graph_tests.cpp solution_tests.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: app

tests: 
	$(CPP) $(CPPFLAGS) $(SRCS) $(TEST_SRCS) -o tests.out

app: $(OBJS)
	$(CPP) $(CPPFLAGS) main.cpp -o app.out $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CPP) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

include .depend