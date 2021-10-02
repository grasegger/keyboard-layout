.PHONY: firmware-qmk
firmware-qmk: prepare-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware ferris/sweep:karl
	cd qmk_firmware; git clean -df	

.PHONY: flash-qmk
flash-qmk: prepare-qmk
	make BUILD_DIR=$(shell pwd) -j4 -C qmk_firmware ferris/sweep:karl:flash
	cd qmk_firmware; git clean -df	

.PHONY: flash-qmk-left
flash-qmk-left: prepare-qmk
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
	ln -s $(shell pwd)/elite_c/ferris_sweep qmk_firmware/keyboards/ferris/sweep/keymaps/karl