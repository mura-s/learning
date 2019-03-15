# e.g. abc001
DIR :=

.PHONY: abc
abc: .check-dir
	mkdir $(DIR)
	cp -r ../template $(DIR)/a
	cp -r ../template $(DIR)/b
	cp -r ../template $(DIR)/c
	cp -r ../template $(DIR)/d

.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif
