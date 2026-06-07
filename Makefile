BUIDL_DIR = build
PROJ_NAME = particleLife
EXECUTABLE_PATH = ${BUIDL_DIR}/app/${PROJ_NAME}

prep:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)

run:
	@make prep
	cmake --build $(BUIDL_DIR)
	./${EXECUTABLE_PATH}

test:
	@make prep
	cmake --build $(BUIDL_DIR) --target unit_tests
	cd $(BUIDL_DIR) && ctest --output-on-failure

all:
	@make prep
	cmake --build $(BUIDL_DIR) --target unit_tests particleLife
	cd $(BUIDL_DIR) && ctest --output-on-failure
	./${EXECUTABLE_PATH}

cleanup:
	@rm -rf build

format:
	@find src/ tests/ -name '*.hpp' -o -name '*.cpp' | xargs clang-format -i -style=file
