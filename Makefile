.PHONY: firmware-qmk
firmware-qmk: lint-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl
	cd qmk_firmware; git clean -df	

.PHONY: flash-qmk
flash-qmk: prepare-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware splitkb/kyria:karl:flash
	cd qmk_firmware; git clean -df	

.PHONY: prepare-qmk
prepare-qmk: 
	git submodule update --init --recursive
	cd qmk_firmware; git clean -df	
	ln -s $(shell pwd)/src_qmk qmk_firmware/keyboards/splitkb/kyria/keymaps/karl

.PHONY: lint-qmk
lint-qmk: prepare-qmk
	cd qmk_firmware; qmk lint -km karl -kb splitkb/kyria --strict