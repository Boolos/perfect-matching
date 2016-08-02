CPP=g++-5
CPPFLAGS=-std=c++11 -fopenmp
RM=rm -f
SRCS=edge.cpp graph.cpp matrix.cpp perfect-matching.cpp polynomial.cpp solution.cpp vertex.cpp
TEST_SRCS=tests.cpp polynomial_tests.cpp matrix_tests.cpp graph-tests.cpp solution_tests.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: app

tests: 
	g++-5 $(CPPFLAGS) $(SRCS) $(TEST_SRCS) -o tests.out

app: $(OBJS)
	g++-5 $(CPPFLAGS) main.cpp -o app.out $(OBJS)

clean:
	$(RM) $(OBJS)

