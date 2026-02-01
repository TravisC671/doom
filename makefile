BUILD_DIR=build

all:
	cmake -S . -B $(BUILD_DIR) -G "MinGW Makefiles"
	cmake --build $(BUILD_DIR)

clean:
	rmdir /S /Q $(BUILD_DIR)
