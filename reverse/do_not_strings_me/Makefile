CC = gcc 
CFLAGS = -Wall -Wextra
LDFLAGS = -static

DNSM = do_not_strings_me
DNSM_SRC = $(DNSM).c 

$(DNSM): $(DNSM_SRC)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ 


all: $(DNSM)

clean:
	rm -f $(DNSM)
