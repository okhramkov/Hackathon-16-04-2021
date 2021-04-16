SRCS := $(wildcard src/*.c)
HDRS := $(wildcard inc/*.h)

WFLGS := $(addprefix -W, all extra error pedantic)

CJSON_DIR = ../frameworks/cjson
CJSON_FILES:= $(CJSON_DIR)/libcjson.a
CJSON_INC_FILES:= $(CJSON_DIR)/inc

LIB_DIR = ../frameworks/libmx
LIB_FILES:= $(LIB_DIR)/libmx.a
LIB_INC_FILES:= $(LIB_DIR)/inc

LIBS_FLAGS = -lcjson\
			 -L$(CJSON_DIR) -I$(CJSON_INC_FILES) \

GTK_LINK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

all: install

install: $(CJSON_FILES) $(LIB_FILES) uchat

uchat:
	@clang -std=c11 -lcjson $(WFLGS) $(SRCS) $(HDRS) $(GTK_LINK_FLAGS) $(LIB_INC) $(LIBS_FLAGS)
	@mv a.out ../$@

$(CJSON_FILES):
	@make -sC $(CJSON_DIR)

$(LIB_FILES):
	@make -sC $(LIB_DIR)

clean:
	@rm -rf inc/*.gch

uninstall: clean
	@rm -rf ../uchat

reinstall: uninstall install

.PHONY: all install uninstall clean reinstall
