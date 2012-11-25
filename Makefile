# Author: Oleg Selivanov <oleg.a.selivanov@gmail.com>

install: vvim re vm greplace
	mkdir -p ~/bin
	for binfile in vvim re vm greplace ; do \
	  ln -sf $$(realpath $$binfile) ~/bin/$$binfile ; \
	done
