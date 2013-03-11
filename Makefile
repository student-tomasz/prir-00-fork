CC=gcc
CFLAGS=-Wall
LDFLAGS=

cw1: cw1.c
	$(CC) $(CFLAGS) $< -o $@ && ./$@

cw2: cw2.c
	$(CC) $(CFLAGS) $< -o $@ && ./$@

cw3: cw3.c
	$(CC) $(CFLAGS) $< -o $@ && ./$@

clean:
	rm cw?
