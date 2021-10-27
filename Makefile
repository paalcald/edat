CPP=g++
CPPFLAGS=-g -Wall -Iinclude

INCDIR=include
TESTDIR=tests
TESTBINDIR=tests/bin

INCS=$(wildcard $(INCDIR)/*.hpp)
ADTS=$(filter-out $(INCDIR)/catch.hpp $(INCDIR)/pila.hpp, $(INCS))
TESTS=$(wildcard $(TESTDIR)/test_*.cpp)
TESTBINS=$(patsubst $(INCDIR)/%.hpp, $(TESTBINDIR)/test_%, $(ADTS))

all: tests

tests: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

.SECONDEXPANSION:
$(TESTBINDIR)/test_%: $(TESTDIR)/test_$$(word 1, $$(subst _, ,$$*)).cpp
	$(CPP) $(CPPFLAGS) -include $*.hpp -o $@ $(TESTDIR)/test_$(word 1,$(subst _, ,$*)).cpp

clean:
	rm -r $(TESTBINS)
