CC =gcc 
CFLAGS =-Wall -Wextra
LDFLAGS =-static -s
AR =ar

BIN =bin/
SRC =src/
LIB =lib/
TAC =tiny-AES-c/

AES =aes
AES_BIN =$(BIN)$(LIB)
AES_LIB =$(AES_BIN)lib$(AES).a 
AES_SRC =$(SRC)$(LIB)$(TAC)

DDS =dead_drops
DDS_SRC =$(SRC)$(DDS).c 
DDS_HEAD =$(SRC)$(DDS).h
DDS_OBJ =$(BIN)$(DDS).o
TARGET =$(BIN)$(DDS)


# AES static library 
$(AES_BIN)aes.o : $(AES_SRC)aes.c $(AES_SRC)aes.h
	@echo create object for $< "=>"
	$(CC) $(CFLAGS) -Os -o $@ -c $<
	@echo -------------------------

$(AES_LIB) : $(AES_BIN)aes.o
	@echo generate archive for $< "=>"
	$(AR) $(ARFLAGS) $@ $^
	@echo -------------------------

$(DDS_OBJ): $(DDS_SRC) $(DDS_HEAD)
	@echo generate object file for $< "=>"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -------------------------

$(TARGET): $(DDS_OBJ)
	@echo generate target $@ "=>"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ -L$(AES_BIN) -laes
	@echo -------------------------

start :
	@echo "Start building Challenge"
	@echo -------------------------
	@echo create necessary directory
	mkdir -p bin/
	mkdir -p bin/lib/
	@echo -------------------------

end :
	@echo "Challenge has been build"


.PHONY: clean end start  

all: start $(AES_LIB) $(TARGET) end


clean:
	rm -f $(TARGET) $(DDS_OBJ)
