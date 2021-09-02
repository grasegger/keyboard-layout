.PHONY: firmware
firmware: lint
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl
	cd qmk_firmware; git clean -df	

.PHONY: flash
flash: prepare
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl:flash
	cd qmk_firmware; git clean -df	

.PHONY: prepare
prepare: 
	git submodule update --init --recursive
	cd qmk_firmware; git clean -df	
	ln -s $(shell pwd)/src qmk_firmware/keyboards/splitkb/kyria/keymaps/karl

.PHONY: lint
lint: prepare
	cd qmk_firmware; qmk lint -km karl -kb splitkb/kyria --strict