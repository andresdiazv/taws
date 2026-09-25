test: build/test_units
	build/test_units


build/test_units: tests/test_units.c src/units.c tests/unity/unity.c src/units.h | build
	gcc -Wall -Wextra -Werror -DUNITY_INCLUDE_DOUBLE tests/test_units.c src/units.c tests/unity/unity.c -o build/test_units

build:
	# -p "parents" prevents error if dir exists
	mkdir -p build
 
clean:
	rm -rf build

.PHONY: test clean