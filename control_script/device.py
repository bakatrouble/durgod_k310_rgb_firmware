import enum

import hid


REPORT_ID_VENDOR = b'\x04'


def i2b(val: int):
    return val.to_bytes(1, 'big')


class KeyboardDevice:
    def __init__(self):
        self.dev = hid.Device(0x2f68, 0x0041)
        self.nonce = 0

    def send_command(self, command: int, args: bytes = b'', return_response=True):
        sent_nonce = self.nonce
        self.dev.write(REPORT_ID_VENDOR + i2b(sent_nonce & 0xFF) + i2b(command) + args)
        self.nonce += 1
        if return_response:
            for _ in range(100):
                recv = self.dev.read(0x40)
                if recv[0] == 4 and recv[1] == sent_nonce:
                    return recv[2:]

    def send_toggle_backlight(self):
        status, enabled = self.send_command(0x01)
        return status, enabled

    def send_bootloader(self):
        self.send_command(0xFF, return_response=False)

    def send_led_data(self, data: bytes):
        status = self.send_command(0x02, data)
        return status

    def send_set_color(self, r: int, g: int, b: int):
        status = self.send_command(0x03, i2b(min(0xFF, r)) + i2b(min(0xFF, g)) + i2b(min(0xFF, b)))
        return status
