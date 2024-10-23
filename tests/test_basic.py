import fpng
import numpy as np


def test_ndarray():
    img = np.zeros([640, 480, 3], dtype=np.uint8)
    png = fpng.fpng_ext.encode_ndarray(img)

    with open('out.png', 'wb') as outf:
        outf.write(png)
