CPP=g++
CPPFLAGS=-g -Wall -Iinclude

INCDIR=include
TESTSDIR=tests

ADTS=$(wildcard $(INCDIR)/*.hpp)
TESTS=$(patsubst $(INCDIR)/%.hpp, $(TESTSDIR)/test_%, $(ADTS))

all: tests

tests: $(TESTS)

$(TESTDIR)/test_%: $(TESTDIR)/test_%.cpp $(INCDIR)/%.hpp
	$(CPP) $(CPPFLAGS) -o $@ $<


clean:
	rm -r $(TESTS)
