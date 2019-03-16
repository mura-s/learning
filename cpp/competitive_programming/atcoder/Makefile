# tasks

# e.g. abc001
NAME :=
.PHONY: abc
abc: .check-name
	mkdir $(NAME)
	cp -r ../template $(NAME)/a
	cp -r ../template $(NAME)/b
	cp -r ../template $(NAME)/c
	cp -r ../template $(NAME)/d

.PHONY: agc
agc: .check-name
	mkdir $(NAME)
	cp -r ../template $(NAME)/a
	cp -r ../template $(NAME)/b
	cp -r ../template $(NAME)/c
	cp -r ../template $(NAME)/d
	cp -r ../template $(NAME)/e
	cp -r ../template $(NAME)/f

# e.g. abc001/a
DIR :=
.PHONY: dir
dir: .check-dir
	mkdir -p $(DIR)
	cp ../template/* $(DIR)/

# internal tasks
.check-name:
ifeq ($(NAME),)
	$(error NAME is required.)
endif

.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif
