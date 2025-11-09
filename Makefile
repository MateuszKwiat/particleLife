BUIDL_DIR = build

all:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)
	cmake --build $(BUIDL_DIR)

run:
	@mkdir -p $(BUIDL_DIR)
	cmake -S . -B $(BUIDL_DIR)
	cmake --build $(BUIDL_DIR) --target run