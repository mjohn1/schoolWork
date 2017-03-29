CXX      = g++
OBJS     = waterjugpuzzle.o
CXXFLAGS = -g -Wall -Werror -pedantic-errors -fmessage-length=0
TARGET   = waterjugpuzzle
all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)