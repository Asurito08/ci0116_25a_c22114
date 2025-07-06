EXEC = ejecutable

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

CPPFLAGS = -I$(SRC_DIR)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC) docs

run: $(EXEC)
	./$(EXEC)

doc:
	doxygen Doxyfile

opendoc:
	@xdg-open docs/html/index.html 2>/dev/null || open docs/html/index.html || echo "Abre docs/html/index.html manualmente"

.PHONY: all clean run doc opendoc
