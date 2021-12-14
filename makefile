
CC = gcc

CFLAGS += -Werror -Wall
CFLAGS += -Wfatal-errors

CPPFLAGS += -D _GNU_SOURCE
CPPFLAGS += -I .

BUILDTYPE ?= release

ifeq ($(BUILDTYPE), release)
CPPFLAGS += -D RELEASE
CPPFLAGS += -D FORTIFY_SOURCE=2

CFLAGS += -O2
CFLAGS += -flto

LDFLAGS += -static
else ifeq ($(BUILDTYPE), testing)
CPPFLAGS += -D TESTING

CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable

else
CPPFLAGS += -D DEBUGGING

CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-value
CFLAGS += -Wno-maybe-uninitialized
endif

USE_GMP ?= system

BUILDPATH = BUILDTYPE=$(BUILDTYPE)/USE_GMP=$(USE_GMP)

default: gen/pl

gen/pl: gen/$(BUILDPATH)/pl
	cp $< $@

.PRECIOUS: %/
%/:
	mkdir -p $@

ifeq ($(USE_GMP), local)

include gmp.mk
include gmp/installed.mk

CPPFLAGS += -I ./include/

LDFLAGS += -L ./lib/

endif

LDLIBS += -lgmp

YACC = bison
YFLAGS += --warnings=error=all

LEX = flex

%.c %.h: %.y
	$(YACC) $(YFLAGS) --output=$*.c --defines=$*.h $< 

%.c %.h: %.l
	$(LEX) $(LFLAGS) --outfile=$*.c --header-file=$*.h $< 

SRCDIRS += avl
SRCDIRS += cmdln
SRCDIRS += defines
SRCDIRS += enums
SRCDIRS += expression
SRCDIRS += macros
SRCDIRS += memory
SRCDIRS += label_scope
SRCDIRS += next_ll
SRCDIRS += parser
SRCDIRS += scope
SRCDIRS += statement
SRCDIRS += string
SRCDIRS += value
SRCDIRS += main.c

gen/srclist.mk: | gen/
	find $(SRCDIRS) -name '*.c' | sed 's/^/srcs += /' > $@

srcs += parser/scanner.c parser/parser.c

include gen/srclist.mk

ARGS += -v

#ARGS += -d 'x = 3'
#ARGS += -d 'x = 9'
#ARGS += -d 'a = 3' -d 'b = 5' -d 'c = 2'
#ARGS += -d 'a = 2' -d 'b = 5' -d 'c = 3'
ARGS += -d 'a = 3' -d 'b = 2' -d 'c = 5'

#ARGS += ./test.txt
#ARGS += ./examples/arith.txt
#ARGS += ./examples/sort-3.txt
#ARGS += ./examples/goto.txt
ARGS += ./examples/multiple-labels.txt

run: gen/$(BUILDPATH)/pl
	$< ${ARGS}

valrun: gen/$(BUILDPATH)/pl
	valgrind -- $< ${ARGS}

valrun-stop: gen/$(BUILDPATH)/pl
	valgrind --gen-suppressions=yes -- $< ${ARGS}

valrun-leak: gen/$(BUILDPATH)/pl
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -- $< ${ARGS}

gen/$(BUILDPATH)/pl: $(patsubst %.c,gen/$(BUILDPATH)/%.o,$(srcs))
	$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

gen/$(BUILDPATH)/%.d: %.c | gen/$(BUILDPATH)/%/
	$(CPP) $(CPPFLAGS) $< -MM -MT $@ -MF $@

gen/$(BUILDPATH)/%.o: %.c gen/$(BUILDPATH)/%.d | gen/$(BUILDPATH)/%/
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

gen/PL.zip: $(SRCDIRS) examples/ *.h *.tex *.mk *.txt makefile README.md
	zip -r $@ $^

docs: gen/proposal.pdf
docs: gen/prelim-design.pdf
docs: gen/comp-design.pdf
docs: gen/testing-design.pdf
docs: gen/final-report.pdf

gen/%.pdf: %.tex
	cd $(@D); pdflatex ../$<

clean:
	for l in $$(cat .gitignore); do rm -rvf $$l; done

ifneq "$(MAKECMDGOALS)" "clean"
include $(patsubst %.c,gen/$(BUILDPATH)/%.d,$(srcs))
endif












