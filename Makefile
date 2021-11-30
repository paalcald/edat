CXX := g++
CXXFLAGS := -g -Wall

INC_DIR := include
TEST_DIR := tests
TEST_BIN_DIR := $(TEST_DIR)/bin

BINDIR=bin

ADTS = stack_array stack_list queue_array queue_list secuencias #binary_search_tree
TESTS = $(addprefix test_, $(ADTS))

INC_FLAGS := $(addprefix -I,$(INC_DIR))

CPPFLAGS := $(INC_FLAGS)

all:
	@echo "No programs are implemented yet"

.PHONY: check
check: $(TEST_BIN_DIR)/ $(TESTS)
	@echo "Cleaning up after tests"
	@rm -r $(TEST_BIN_DIR)

test_%: $(TEST_BIN_DIR)/test_% | $(TEST_BIN_DIR)/
	@./$<

$(TEST_BIN_DIR)/:
	@echo "Creating" $@
	@mkdir -p $@

$(TEST_BIN_DIR)/test_%_array: $(TEST_DIR)/test_%.cpp $(INC_DIR)/%_array.hpp
	@echo "Compiling tests for" $@
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -include $(word 2,$^) -o $@ $<
	@echo "done."

$(TEST_BIN_DIR)/test_%_list: $(TEST_DIR)/test_%.cpp $(INC_DIR)/%_list.hpp
	@echo "Compiling tests for" $@
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -include $(word 2,$^) -o $@ $<

$(TEST_BIN_DIR)/test_%: $(TEST_DIR)/test_%.cpp $(INC_DIR)/%.hpp
	@echo "Compiling tests for" $@
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
	@echo "done."

.PHONY: clean
clean:
	rm -r $(TEST_BIN_DIR)
