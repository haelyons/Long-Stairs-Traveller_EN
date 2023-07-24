
#CPPFLAGS=-Wall -Wextra -std=c++17
#main: main.cpp loc.cpp map.cpp save.cpp colors.hpp loc_data.hpp stat.hpp names.cpp door.cpp

CFLAGS = -Wall -Wextra -std=c++17 -g
CPPFLAGS = -I.
LDFLAGS =

EXEC = main

all: $(EXEC) locale/en/$(EXEC).mo

$(EXEC): $(EXEC).cpp 
    $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

locale/en/$(EXEC).mo: locale/en/$(EXEC).po
    msgfmt --output-file=$@ $<

locale/en/$(EXEC).po: po/$(EXEC).pot
    msgmerge --update $@ $<

locale/$(EXEC).pot: $(EXEC).c
    xgettext -k_ -j -lC -c -s -o locale/main.pot main.cpp loc.cpp map.cpp save.cpp colors.hpp loc_data.hpp stat.hpp names.cpp door.cpp

clean:
    @rm -f $(EXEC) locale/en/*.mo *~

.PHONY: clean