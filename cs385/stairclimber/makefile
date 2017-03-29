CXX      = g++
OBJS     = stairclimber.o
CXXFLAGS = -g -Wall -Werror -pedantic-errors -fmessage-length=0
TARGET   = stairclimber
all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)