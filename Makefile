firmware:
	git submodule update --init --recursive
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/karl
	ln -s $(shell pwd)/src qmk_firmware/keyboards/splitkb/kyria/keymaps/karl
	cd qmk_firmware; qmk lint -km karl -kb splitkb/kyria --strict
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/karl