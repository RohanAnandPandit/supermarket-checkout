CC = clang++
CFLAGS = -Wall -g
BUILDDIR = build
TARGET = bin/main
SRCDIR = src

all: $(TARGET)

$(TARGET): $(BUILDDIR)/main.o $(BUILDDIR)/SupermarketCheckout.o $(BUILDDIR)/Order.o $(BUILDDIR)/Stock.o
	$(CC) $(CFLAGS) -o $(TARGET) $(BUILDDIR)/main.o $(BUILDDIR)/SupermarketCheckout.o $(BUILDDIR)/Order.o $(BUILDDIR)/Stock.o

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/SupermarketCheckout.h $(SRCDIR)/Stock.h $(SRCDIR)/Order.h
	$(CC) $(CFLAGS) -o $(BUILDDIR)/main.o -c $(SRCDIR)/main.cpp

$(BUILDDIR)/Order.o: $(SRCDIR)/Order.h
	$(CC) $(CFLAGS) -o $(BUILDDIR)/Order.o -c $(SRCDIR)/Order.cpp	

$(BUILDDIR)/SupermarketCheckout.o: $(SRCDIR)/SupermarketCheckout.h
	$(CC) $(CFLAGS) -o $(BUILDDIR)/SupermarketCheckout.o -c $(SRCDIR)/SupermarketCheckout.cpp

$(BUILDDIR)/Stock.o: $(SRCDIR)/Stock.h
	$(CC) $(CFLAGS) -o $(BUILDDIR)/Stock.o -c $(SRCDIR)/Stock.cpp

clean:
	$(RM) $(BUILDDIR)/*.o $(TARGET)
 
.PHONY: clean