DEPS = Image.h ImageImpl.h Video.h Utilities.h
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors
LDFLAGS=

all: Example1.exe Example2.exe Example3.exe TestBasics.exe TestReverse.exe TestAdd.exe TestAddAssign.exe TestExtract.exe TestRemove.exe TestSubstitute.exe TestInsertion.exe

# Example 1
Example1.exe: Example1.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

Example1.o: Example1.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

# Example 2
Example2.exe: Example2.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

Example2.o: Example2.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

# Example 3
Example3.exe: Example3.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

Example3.o: Example3.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<


# Test basics
TestBasics.exe: TestBasics.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestBasics.o: TestBasics.cpp $(DEPS) VideoTodoBasics.h
	$(CXX) $(CXXFLAGS) -c $<

# Test reverse function
TestReverse.exe: TestReverse.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestReverse.o: TestReverse.cpp $(DEPS) VideoTodoBasics.h VideoTodoReverse.h
	$(CXX) $(CXXFLAGS) -c $<

# Test operator +
TestAdd.exe: TestAdd.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestAdd.o: TestAdd.cpp $(DEPS) VideoTodoBasics.h VideoTodoAdd.h
	$(CXX) $(CXXFLAGS) -c $<

# Test operator +=
TestAddAssign.exe: TestAddAssign.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestAddAssign.o: TestAddAssign.cpp $(DEPS) VideoTodoBasics.h VideoTodoAddAssign.h
	$(CXX) $(CXXFLAGS) -c $<

# Test extract function
TestExtract.exe: TestExtract.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestExtract.o: TestExtract.cpp $(DEPS) VideoTodoBasics.h VideoTodoExtract.h
	$(CXX) $(CXXFLAGS) -c $<

# Test remove function
TestRemove.exe: TestRemove.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestRemove.o: TestRemove.cpp $(DEPS) VideoTodoBasics.h VideoTodoRemove.h
	$(CXX) $(CXXFLAGS) -c $<

# Test substitute function
TestSubstitute.exe: TestSubstitute.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestSubstitute.o: TestSubstitute.cpp $(DEPS) VideoTodoBasics.h VideoTodoSubstitute.h
	$(CXX) $(CXXFLAGS) -c $<

# Test operator <<
TestInsertion.exe: TestInsertion.o Utilities.o
	$(CXX) $(LDFLAGS) -o $@ $^

TestInsertion.o: TestInsertion.cpp $(DEPS) VideoTodoBasics.h VideoTodoInsertion.h
	$(CXX) $(CXXFLAGS) -c $<

# Common
Utilities.o: Utilities.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o
	rm -rf *.exe
