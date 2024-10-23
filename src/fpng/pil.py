from typing import IO

import numpy as np
from PIL import Image, ImageFile
from . import fpng_ext


fpng_ext.init()


def _save(im: Image.Image, fp: IO[bytes], filename) -> None:
    if im.mode == "RGB":
        rawmode = "RGB"
        bpp = 8

    elif im.mode == "RGBA":
        rawmode = "RGBA"
        bpp = 8

    else:
        msg = f"cannot write mode {im.mode} as FPNG"
        raise OSError(msg)

    # make sure image data is available
    im.load()

    # TODO: make work without numpy
    png = fpng_ext.encode_ndarray(np.array(im))
    fp.write(png)

    if hasattr(fp, "flush"):
        fp.flush()


Image.register_save("FPNG", _save)

# Image.register_extension("FPNG", ".png")

# Image.register_mime("FPNG", "image/png")
