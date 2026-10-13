-include config.mk

# Compiler settings
CROSS_COMPILE ?=
CC := $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Wextra -Iinclude

# Target application
TARGET := $(BUILD_DIR)/serial_echo
SRCS := main.c src/tty_settings.c
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean deploy
all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o  $@ $<

clean:
	rm -f  $(OBJS) $(TARGET)

deploy: $(TARGET)
	scp $(TARGET) $(DEPLOY_USER)@$(DEPLOY_HOST):$(DEPLOY_PATH)

