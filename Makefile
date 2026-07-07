BUILD_DIR := build
COVERAGE_BUILD_DIR := build-coverage
PROJ_NAME := particleLife
EXECUTABLE_PATH := $(BUILD_DIR)/app/$(PROJ_NAME)

prep:
	mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)

run: prep
	cmake --build $(BUILD_DIR)
	./$(EXECUTABLE_PATH)

test: prep
	cmake --build $(BUILD_DIR) --target unit_tests
	cd $(BUILD_DIR) && ctest --output-on-failure

cov:
	mkdir -p $(COVERAGE_BUILD_DIR)
	cmake -S . -B $(COVERAGE_BUILD_DIR) -DENABLE_COVERAGE=ON
	cmake --build $(COVERAGE_BUILD_DIR) --target coverage

all: prep
	cmake --build $(BUILD_DIR) --target unit_tests particleLife
	cd $(BUILD_DIR) && ctest --output-on-failure
	./$(EXECUTABLE_PATH)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(COVERAGE_BUILD_DIR)

format:
	find src/ tests/ -name '*.hpp' -o -name '*.cpp' | xargs clang-format -i -style=file
