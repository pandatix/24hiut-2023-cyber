CC = gcc 
CFLAGS = -Wall -Wextra -O0
LDFLAGS = -static

GMP = guessmypass
GMP_SRC = $(GMP).c 

$(GMP): $(GMP_SRC)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ 


all: $(GMP)

clean:
	rm -f $(GMP)
