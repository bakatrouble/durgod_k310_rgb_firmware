#!/usr/bin/env bash

if [ $UID -ne 0 ]
then
  echo "Need sudo"
  exit
fi

python main.py bootloader

# shellcheck disable=SC2034
for i in $(seq 10)
do
  DEVICE=$(lsblk -o NAME,MODEL | grep "LPC1XXX IFLASH" | cut -f1 -d' ')
  if [ -n "$DEVICE" ]
  then
    break
  fi
  sleep 1
done

if [ -z "$DEVICE" ]
then
  echo "Device not found"
  exit
fi

mkdir -p "mountpoint"
mount /dev/$DEVICE "$(pwd)/mountpoint"
dd if=../.pio/build/lpc11u35/firmware.bin of="$(pwd)/mountpoint/firmware.bin" bs=1024 conv=nocreat,notrunc
umount "$(pwd)/mountpoint"
echo "Done"
