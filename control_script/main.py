#!/usr/bin/env python3

import click
import colour
import math
from time import sleep

from device import KeyboardDevice


def count_integers(minvalue, maxvalue):
    minvalue_ = math.floor(minvalue)
    maxvalue_ = math.ceil(maxvalue)
    for i, val in enumerate(range(minvalue_, maxvalue_+1)):
        if i == 0:
            yield val, minvalue - minvalue_
        elif i == maxvalue_ - minvalue_ - 1:
            yield val, maxvalue_ - maxvalue
        else:
            yield val, 1


# KEY_COORDS = [(0.5, 0.5, 1, 1), (2.5, 0.5, 1, 1), (3.5, 0.5, 1, 1), (4.5, 0.5, 1, 1), (5.5, 0.5, 1, 1), (7.0, 0.5, 1, 1), (8.0, 0.5, 1, 1), (9.0, 0.5, 1, 1), (10.0, 0.5, 1, 1), (11.5, 0.5, 1, 1), (12.5, 0.5, 1, 1), (13.5, 0.5, 1, 1), (14.5, 0.5, 1, 1), (15.75, 0.5, 1, 1), (16.75, 0.5, 1, 1), (17.75, 0.5, 1, 1), (0.5, 1.5, 1, 1), (1.5, 1.5, 1, 1), (2.5, 1.5, 1, 1), (3.5, 1.5, 1, 1), (4.5, 1.5, 1, 1), (5.5, 1.5, 1, 1), (6.5, 1.5, 1, 1), (7.5, 1.5, 1, 1), (8.5, 1.5, 1, 1), (9.5, 1.5, 1, 1), (10.5, 1.5, 1, 1), (11.5, 1.5, 1, 1), (12.5, 1.5, 1, 1), (14.0, 1.5, 2, 1), (15.75, 1.5, 1, 1), (16.75, 1.5, 1, 1), (17.75, 1.5, 1, 1), (19.0, 1.5, 1, 1), (20.0, 1.5, 1, 1), (21.0, 1.5, 1, 1), (22.0, 1.5, 1, 1), (0.75, 2.5, 1.5, 1), (2.0, 2.5, 1, 1), (3.0, 2.5, 1, 1), (4.0, 2.5, 1, 1), (5.0, 2.5, 1, 1), (6.0, 2.5, 1, 1), (7.0, 2.5, 1, 1), (8.0, 2.5, 1, 1), (9.0, 2.5, 1, 1), (10.0, 2.5, 1, 1), (11.0, 2.5, 1, 1), (12.0, 2.5, 1, 1), (13.0, 2.5, 1, 1), (14.25, 2.5, 1.5, 1), (15.75, 2.5, 1, 1), (16.75, 2.5, 1, 1), (17.75, 2.5, 1, 1), (19.0, 2.5, 1, 1), (20.0, 2.5, 1, 1), (21.0, 2.5, 1, 1), (22.0, 3.0, 1, 2), (0.875, 3.5, 1.75, 1), (2.25, 3.5, 1, 1), (3.25, 3.5, 1, 1), (4.25, 3.5, 1, 1), (5.25, 3.5, 1, 1), (6.25, 3.5, 1, 1), (7.25, 3.5, 1, 1), (8.25, 3.5, 1, 1), (9.25, 3.5, 1, 1), (10.25, 3.5, 1, 1), (11.25, 3.5, 1, 1), (12.25, 3.5, 1, 1), (13.875, 3.5, 2.25, 1), (19.0, 3.5, 1, 1), (20.0, 3.5, 1, 1), (21.0, 3.5, 1, 1), (1.125, 4.5, 2.25, 1), (2.75, 4.5, 1, 1), (3.75, 4.5, 1, 1), (4.75, 4.5, 1, 1), (5.75, 4.5, 1, 1), (6.75, 4.5, 1, 1), (7.75, 4.5, 1, 1), (8.75, 4.5, 1, 1), (9.75, 4.5, 1, 1), (10.75, 4.5, 1, 1), (11.75, 4.5, 1, 1), (13.625, 4.5, 2.75, 1), (16.75, 4.5, 1, 1), (19.0, 4.5, 1, 1), (20.0, 4.5, 1, 1), (21.0, 4.5, 1, 1), (22.0, 5.0, 1, 2), (0.625, 5.5, 1.25, 1), (1.875, 5.5, 1.25, 1), (3.125, 5.5, 1.25, 1), (6.875, 5.5, 6.25, 1), (10.625, 5.5, 1.25, 1), (11.875, 5.5, 1.25, 1), (13.125, 5.5, 1.25, 1), (14.375, 5.5, 1.25, 1), (15.75, 5.5, 1, 1), (16.75, 5.5, 1, 1), (17.75, 5.5, 1, 1), (19.5, 5.5, 2, 1), (21.0, 5.5, 1, 1)]
KEY_COORDS = [
    (0, 0),         (2, 0), (3, 0), (4, 0), (5, 0),         (7, 0), (8, 0), (9, 0), (10, 0), (11, 0), (12, 0), (13, 0), (14, 0),     (15, 0), (16, 0), (17, 0),
    (0, 1), (1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (6, 1), (7, 1), (8, 1), (9, 1), (10, 1), (11, 1), (12, 1),          (14, 1),     (15, 1), (16, 1), (17, 1),      (18, 1), (19, 1), (20, 1), (21, 1),
    (0, 2), (1, 2), (2, 2), (3, 2), (4, 2), (5, 2), (6, 2), (7, 2), (8, 2), (9, 2), (10, 2), (11, 2), (12, 2),          (14, 2),     (15, 2), (16, 2), (17, 2),      (18, 2), (19, 2), (20, 2), (21, 2),
    (0, 3), (1, 3), (2, 3), (3, 3), (4, 3), (5, 3), (6, 3), (7, 3), (8, 3), (9, 3), (10, 3), (11, 3),                   (14, 3),                                     (18, 3), (19, 3), (20, 3),
    (0, 4), (1, 4), (2, 4), (3, 4), (4, 4), (5, 4), (6, 4), (7, 4), (8, 4), (9, 4), (10, 4),                            (14, 4),              (16, 4),               (18, 4), (19, 4), (20, 4), (21, 4),
    (0, 5), (1, 5), (2, 5),                                 (7, 5),                          (11, 5), (12, 5), (13, 5), (14, 5),     (15, 5), (16, 5), (17, 5),      (18, 5), (19, 5), (20, 5),
]
image_width = 96
image_height = 6
with open('pid.bin', 'rb') as f:
    IMAGE = f.read()
    image_matrix = [[0 if IMAGE[(r*image_width+c)//8] & (1 << (r*image_width+c)%8) else 1 for c in range(image_width)] for r in range(image_height)]


@click.group()
@click.pass_context
def cli(ctx):
    ctx.obj = KeyboardDevice()


@cli.command()
@click.pass_obj
def toggle_backlight(kbd: KeyboardDevice):
    success, status = kbd.send_toggle_backlight()
    if success == 0:
        click.echo('New backlight status: ' + ('disabled', 'enabled')[status])
    else:
        click.echo('An error has occurred')


@cli.command()
@click.pass_obj
def bootloader(kbd: KeyboardDevice):
    kbd.send_bootloader()


@cli.command()
@click.pass_obj
def send_led_data(kbd: KeyboardDevice):
    while True:
        for scroll in range(image_width - 22):
            key_image_matrix = []
            for x, y in KEY_COORDS:
                key_image_matrix.append(image_matrix[y][scroll + x])

            bit = 0
            ints = []
            for val in key_image_matrix:
                if bit == 0:
                    ints.append(0)
                if val > 0:
                    ints[-1] += 1 << bit
                bit += 1
                if bit == 8:
                    bit = 0

            data = bytearray(ints)
            # for i in range(len(key_image_matrix))
            kbd.send_led_data(bytes(data))
            # kbd.send_led_data(b'\x01' + b'\0' * 103)
            sleep(.025)


@cli.command()
@click.argument('color')
@click.pass_obj
def set_led_color(kbd: KeyboardDevice, color):
    color = colour.Color(color)
    kbd.send_set_color(int(color.rgb[0] * 255), int(color.rgb[1] * 255), int(color.rgb[2] * 255))
    success, status = kbd.send_toggle_backlight()
    if not status:
        kbd.send_toggle_backlight()

if __name__ == '__main__':
    cli()
