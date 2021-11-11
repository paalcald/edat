CPP=g++
CPPFLAGS=-g -Wall 

INCDIR=include
TESTDIR=tests
TESTBINDIR=tests/bin
BINDIR=bin
PROFDIR=prof
PROFINC=profinc

INCS=$(wildcard $(INCDIR)/*.hpp)
ADTS=$(filter-out $(INCDIR)/catch.hpp $(INCDIR)/pila.hpp, $(INCS))
TESTS=$(wildcard $(TESTDIR)/test_*.cpp)
TESTBINS=$(patsubst $(INCDIR)/%.hpp, $(TESTBINDIR)/test_%, $(ADTS))

all: prof

prof: run_secuencias

run_secuencias: $(BINDIR)/secuencias
	./$(BINDIR)/secuencias

$(BINDIR)/secuencias: $(PROFDIR)/secuencias.cpp $(PROFINC)/secuencias.hpp
	$(CPP) $(CPPFLAGS) -I$(PROFINC) -o $@ $<

tests: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

.SECONDEXPANSION:
$(TESTBINDIR)/test_%: $(TESTDIR)/test_$$(word 1, $$(subst _, ,$$*)).cpp
	$(CPP) $(CPPFLAGS) -I$(INCDIR) -include $*.hpp -o $@ $(TESTDIR)/test_$(word 1,$(subst _, ,$*)).cpp

clean:
	rm -r $(TESTBINS)
