.PHONY: firmware-qmk
firmware-qmk: lint-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware ferris/sweep:karl
	cd qmk_firmware; git clean -df	

.PHONY: flash-qmk
flash-qmk: prepare-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware ferris/sweep:karl:dfu-split-left
	cd qmk_firmware; git clean -df	

.PHONY: flash-qmk-right
flash-qmk-right: prepare-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware ferris/sweep:karl:dfu-split-right
	cd qmk_firmware; git clean -df	

.PHONY: prepare-qmk
prepare-qmk: 
	git submodule update --init --recursive
	cd qmk_firmware; git clean -df	
	mkdir -p qmk_firmware/keyboards/ferris/sweep/keymaps
	ln -s $(shell pwd)/src_qmk qmk_firmware/keyboards/ferris/sweep/keymaps/karl

.PHONY: lint-qmk
lint-qmk: prepare-qmk
	cd qmk_firmware; qmk lint -km karl -kb ferris/sweep --strict