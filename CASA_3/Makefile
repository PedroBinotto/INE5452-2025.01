CXX := g++
CXXFLAGS := -Wall -Wextra -O2

SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=)

.PHONY: all run clean

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(EXECUTABLES)
	@for exe in $(EXECUTABLES); do \
	    input_file=$${exe}_in.txt; \
	    if [ -f $$input_file ]; then \
	        echo "Running $$exe with $$input_file"; \
	        ./$$exe < $$input_file; \
	        echo "---"; \
	    else \
	        echo "Skipping $$exe (no corresponding input file)"; \
	    fi; \
	done

clean:
	rm -f $(EXECUTABLES)
