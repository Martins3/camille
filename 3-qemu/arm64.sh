  qemu-system-aarch64 \
    -drive file=/home/maritns3/Downloads/core-image-minimal-qemuarm64.ext4,format=raw \
    -kernel /home/maritns3/core/arm64-linux/arch/arm64/boot/Image \
    -machine virt \
    -append "console=ttyS0 root=/dev/sda1 ro"
