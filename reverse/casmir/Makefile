CC = gcc 
CFLAGS = -Wall -Wextra
LDFLAGS = -S -fverbose-asm -masm=intel 

CSR = casmir
CSR_ASM = $(CSR).s
CSR_SRC = $(CSR).c 

$(CSR_ASM): $(CSR_SRC)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ 

$(CSR): $(CSR_SRC)
	$(CC) $(CFLAGS) -o $@ $^ 

all: $(CSR_ASM) $(CSR)

clean:
	rm -f $(CSR_ASM) $(CSR)
