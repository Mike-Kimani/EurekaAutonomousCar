import os
from AMSpi import AMSpi
import picamera
import time
import uuid
import sys
import tty
import termios


TRAIN_DATA_DIR = 'traindata'
LBL_FILE = os.path.join(TRAIN_DATA_DIR, 'labels.txt')


class _Getch:
    def __call__(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(3)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch


if __name__ == '__main__':
    getch = _Getch()
    with picamera.PiCamera() as camera, open(LBL_FILE, 'a') as lblfile:
        camera.resolution = ('''XXX''', '''XXX''')
        while True:
            img_filename = '{0}.jpg'.format(uuid.uuid4().hex)
            img_filepath = os.path.join(TRAIN_DATA_DIR, img_filename)
            print('Command: ')
            cmd = getch()
            if cmd == 'XXX':
                # STOP
                pass
            elif cmd == '\x1b[A':
                # FORWARD
                camera.capture(img_filepath)
                lblfile.write(img_filename + '\t' + 'F' + '\n')
                pass
            elif cmd == '\x1b[B':
                # BACKWARD
                camera.capture(img_filepath)
                lblfile.write(img_filename + '\t' + 'B' + '\n')
                pass
            elif cmd == '\x1b[D':
                # LEFT
                camera.capture(img_filepath)
                lblfile.write(img_filename + '\t' + 'L' + '\n')
                pass
            elif cmd == '\x1b[C':
                # RIGHT
                lblfile.write(img_filename + '\t' + 'R' + '\n')
                camera.capture(img_filepath)
                pass
            else:
                print("Invalid input")
                continue
