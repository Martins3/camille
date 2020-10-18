# https://github.com/cirosantilli/linux-cheat/blob/4c8ee243e0121f9bbd37f0ab85294d74fb6f3aec/ubuntu-18.04.1-desktop-amd64.sh


# qemu-img create -f qcow2 ${img}  30G
# qemu-system-x86_64 -hda ${img} -boot d -cdrom ${iso} -m 512 -enable-kvm

# Tested on: Ubuntu 18.10.
# https://askubuntu.com/questions/884534/how-to-run-ubuntu-16-04-desktop-on-qemu/1046792#1046792

set -eux

# Parameters.
id=ubuntu
disk_img="${id}.img.qcow2"
disk_img_snapshot="${id}.snapshot.qcow2"
iso=/home/maritns3/Documents/ubuntu-16.04.5-desktop-amd64.iso

# Get image.
if [ ! -f "$iso" ]; then
  wget "http://releases.ubuntu.com/18.04/${iso}"
fi

# Go through installer manually.
if [ ! -f "$disk_img" ]; then
  qemu-img create -f qcow2 "$disk_img" 1T
  qemu-system-x86_64 \
    -cdrom "$iso" \
    -drive "file=${disk_img},format=qcow2" \
    -enable-kvm \
    -m 2G \
    -smp 2 \
  ;
fi

# Snapshot the installation.
if [ ! -f "$disk_img_snapshot" ]; then
  qemu-img \
    create \
    -b "$disk_img" \
    -f qcow2 \
    "$disk_img_snapshot" \
  ;
fi

kernel=../core/linux/arch/x86/boot/bzImage
# kernel=../core/tm-linux/arch/x86/boot/bzImage

# Run the installed image.
if [[ $# == 1 ]];then
  qemu-system-x86_64 \
    -drive "file=${disk_img_snapshot},format=qcow2" \
    -kernel  ${kernel} \
    -append "console=ttyS0 root=/dev/sda1 ro" \
    -enable-kvm \
    -m 8G \
    -smp 8 \
    -soundhw hda \
    -vga virtio \
    "$@" \
  ;
else
  qemu-system-x86_64 \
    -drive "file=${disk_img_snapshot},format=qcow2" \
    -enable-kvm \
    -m 8G \
    -smp 8 \
    -soundhw hda \
    -vga virtio \
    "$@" \
  ;
fi
