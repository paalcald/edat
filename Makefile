CPP=g++
CPPFLAGS=-g -Wall -Iinclude

INCDIR=include
TESTDIR=tests
TESTBINDIR=tests/bin

ADTS=$(wildcard $(INCDIR)/*.hpp)
TESTS=$(wildcard $(TESTDIR)/test_*.cpp)
TESTBINS=$(patsubst $(TESTDIR)/%.cpp, $(TESTBINDIR)/%, $(TESTS))

all: tests

tests: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done 

$(TESTBINDIR)/test_%: $(TESTDIR)/test_%.cpp $(INCDIR)/%.hpp
	$(CPP) $(CPPFLAGS) -o $@ $<


clean:
	rm -r $(TESTBINS)
