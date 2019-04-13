# parameter
# e.g. abc001 or abc001/a
DIR :=

# tasks
.PHONY: abc
abc: .check-dir
	mkdir $(DIR)
	cp -r ../template $(DIR)/a
	cp -r ../template $(DIR)/b
	cp -r ../template $(DIR)/c
	cp -r ../template $(DIR)/d

.PHONY: agc
agc: .check-dir
	mkdir $(DIR)
	cp -r ../template $(DIR)/a
	cp -r ../template $(DIR)/b
	cp -r ../template $(DIR)/c
	cp -r ../template $(DIR)/d
	cp -r ../template $(DIR)/e
	cp -r ../template $(DIR)/f

.PHONY: dir
dir: .check-dir
	mkdir -p $(DIR)
	cp ../template/* $(DIR)/

# internal tasks
.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif
