CFLAGS = -Os -pedantic-errors -std=c89 -Wall -Wextra

pugge: pugge.c
	$(CC) -o $@ $(CFLAGS) $<

clean:
	rm -f pugge
