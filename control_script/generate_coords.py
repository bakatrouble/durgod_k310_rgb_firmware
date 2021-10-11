data = [['Esc', {'x': 1}, 'F1', 'F2', 'F3', 'F4', {'x': 0.5}, 'F5', 'F6', 'F7', 'F8', {'x': 0.5}, 'F9', 'F10', 'F11', 'F12', {'x': 0.25}, 'PrtSc', 'Scroll Lock', 'Pause\n\n\n\n\n\nBreak'], [{'y': 0.5}, '~\n`', '!\n1', '@\n2', '#\n3', '$\n4', '%\n5', '^\n6', '&\n7', '*\n8', '(\n9', ')\n0', '_\n-', '+\n=', {'w': 2}, 'Backspace', {'x': 0.25}, 'Insert', 'Home', 'PgUp', {'x': 0.25}, 'Num Lock', '/', '*', '-'], [{'w': 1.5}, 'Tab', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{\n[', '}\n]', {'w': 1.5}, '|\n\\', {'x': 0.25}, 'Delete', 'End', 'PgDn', {'x': 0.25}, '7\nHome', '8\n↑', '9\nPgUp', {'h': 2}, '+'], [{'w': 1.75}, 'Caps Lock', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':\n;', '"\n\'', {'w': 2.25}, 'Enter', {'x': 3.5}, '4\n←', '5', '6\n→'], [{'w': 2.25}, 'Shift', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<\n,', '>\n.', '?\n/', {'w': 2.75}, 'Shift', {'x': 1.25}, '↑', {'x': 1.25}, '1\nEnd', '2\n↓', '3\nPgDn', {'h': 2}, 'Enter'], [{'w': 1.25}, 'Ctrl', {'w': 1.25}, 'Win', {'w': 1.25}, 'Alt', {'a': 7, 'w': 6.25}, '', {'a': 4, 'w': 1.25}, 'Alt', {'w': 1.25}, 'Win', {'w': 1.25}, 'Menu', {'w': 1.25}, 'Ctrl', {'x': 0.25}, '←', '↓', '→', {'x': 0.25, 'w': 2}, '0\nIns', '.\nDel']]

coords = []
y = 0
for row in data:
    x = 0
    w = 1
    h = 1
    for key in row:
        if isinstance(key, str):
            coords.append((x + w/2, y + h/2, w, h))
            x += w
            w = 1
            h = 1
        else:
            if 'x' in key:
                x += key['x']
            # if 'y' in key:
            #     y += key['y']
            if 'w' in key:
                w = key['w']
            if 'h' in key:
                h = key['h']
    y += 1

print(coords)