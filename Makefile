BUIDL_DIR = build

all:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)
	cmake --build $(BUIDL_DIR)

run:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)
	cmake --build $(BUIDL_DIR) --target run

test:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)
	cmake --build $(BUIDL_DIR) --target unit_tests
	cd $(BUIDL_DIR) && ctest --output-on-failure