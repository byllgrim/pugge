TARG = pugge
PREFIX = /usr/local
CFLAGS = -Os -pedantic-errors -std=c89 -Wall -Wextra

$(TARG): $(TARG).c
	$(CC) -o $@ $(CFLAGS) $<

install:
	mkdir -p $(PREFIX)/bin
	cp ./$(TARG) $(PREFIX)/bin/
	chmod 755 $(PREFIX)/bin/$(TARG)

clean:
	rm -f $(TARG)
