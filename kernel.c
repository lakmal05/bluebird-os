# Bluebird OS Makefile

ASM = nasm
QEMU = qemu-system-i386

BOOT_SRC = boot/boot.asm
BUILD_DIR = build
OS_IMAGE = $(BUILD_DIR)/bluebird-os.bin

all: $(OS_IMAGE)

$(OS_IMAGE): $(BOOT_SRC)
	mkdir -p $(BUILD_DIR)
	$(ASM) -f bin $(BOOT_SRC) -o $(OS_IMAGE)

run: all
	$(QEMU) -drive format=raw,file=$(OS_IMAGE)

clean:
	rm -rf $(BUILD_DIR)
