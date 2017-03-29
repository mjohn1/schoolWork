CXX      = g++
OBJS     = sieve.o
CXXFLAGS = -g -Wall -Werror -pedantic-errors -fmessage-length=0
TARGET   = sieve
# In the botton of the makefile, that is where we put the rules for building the project
#target: dependencies
# --Tab-- build command
all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
	# -o <output file> specifies the executable
clean:
	rm -f $(OBJS) $(TARGET)