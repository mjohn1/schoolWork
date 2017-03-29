CXX      = g++
OBJS     = knapsack.o
CXXFLAGS = -g -Wall -Werror -pedantic-errors -fmessage-length=0
TARGET   = knapsack
all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)