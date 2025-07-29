# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# 目录定义
BUILD_DIR = build
UTILITY_DIR = utility

# 目标可执行文件
TARGET = main

# 源文件
SOURCES = main.cpp $(UTILITY_DIR)/Logger.cpp

# 对象文件（放在build目录中）
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Logger.o

# 默认目标
all: $(TARGET)

# 创建build目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 生成可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译main.cpp
$(BUILD_DIR)/main.o: main.cpp $(UTILITY_DIR)/Logger.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 编译Logger.cpp
$(BUILD_DIR)/Logger.o: $(UTILITY_DIR)/Logger.cpp $(UTILITY_DIR)/Logger.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# 重新编译
rebuild: clean all

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 声明伪目标
.PHONY: all clean rebuild run