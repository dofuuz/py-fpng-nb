import os.path as osp

import fpng
import fpng.pil

import numpy as np
from PIL import Image


EXAMPLE_PNG = osp.join(osp.dirname(__file__), '../fpng/example.png')


def test_ndarray():
    img = Image.open(EXAMPLE_PNG)
    png = fpng.fpng_ext.encode_ndarray(np.asarray(img))

    with open('out.png', 'wb') as outf:
        outf.write(png)


def test_pil():
    img = Image.open(EXAMPLE_PNG)
    img.save('pil.png', 'FPNG')


if __name__ == "__main__":
    test_ndarray()
    test_pil()
