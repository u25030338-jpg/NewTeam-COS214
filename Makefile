CXX = g++
CXXFLAGS = -std=c++11

TARGET = campusguard
SOURCES = $(wildcard *.cpp)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(TARGET).exe 2>nul || exit 0
else
	rm -f $(TARGET)
endif