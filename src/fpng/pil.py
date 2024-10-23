from typing import IO

from PIL import Image
from . import fpng_ext


fpng_ext.init()


def _save(im: Image.Image, fp: IO[bytes], filename) -> None:
    if im.mode == "RGB":
        num_chan = 3
    elif im.mode == "RGBA":
        num_chan = 4
    else:
        raise OSError(f"cannot write mode {im.mode} as FPNG")

    # make sure image data is available
    im.load()

    png = fpng_ext.encode_image_to_memory(im.tobytes(), im.width, im.height, num_chan)
    fp.write(png)

    if hasattr(fp, "flush"):
        fp.flush()


Image.register_save("FPNG", _save)

# Image.register_extension("FPNG", ".png")

# Image.register_mime("FPNG", "image/png")
