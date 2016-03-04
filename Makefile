
CC := g++ -pthread -std=c++11
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner
TESTDIR := bin/tests

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
# LIB :=
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/sources
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
	@echo " $(RM) -r $(TESTDIR)"; $(RM) -r $(TESTDIR)

# Tests
tests:
	# sort of silly usage of make to run all unit tests in a directory.
	@echo "make test directory"; mkdir -p $(TESTDIR)
	@for sourcefile in ./test/*; do \
		file_name=$${sourcefile%.*}; \
		echo $(CC) $(CFLAGS) $$sourcefile $(INC) $(LIB) -o $(TESTDIR)/$$(basename $$file_name); \
		$(CC) $(CFLAGS) $$sourcefile $(INC) $(LIB) -o $(TESTDIR)/$$(basename $$file_name); \
	done
	@for test in $(TESTDIR)/*; do \
		./$$test; \
	done


.PHONY: clean
