firmware:
	git submodule update --init --recursive
	ln -s $(shell pwd)/src qmk_firmware/keyboards/splitkb/kyria/keymaps/karl
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/karl