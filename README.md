# py-fpng-nb

Very fast .PNG image writer for 24/32bpp images for Python.

py-fpng-nb is a Python wrapper of [fpng](https://github.com/richgel999/fpng)


## Installation

```sh
# ** not yet implemented **
pip install fpng
```

If installation fails, upgrade pip with `python -m pip install --upgrade pip` and try again.


## Usage

### with PIL

```python
import fpng
from PIL import Image

# ... process image ...
img.save('file_path.png', 'FPNG')
```

### with NDarray

n-dimensional arrays of NumPy, PyTorch, TensorFlow, JAX, and CuPy.

Must have 3 dimensions [height, width, channels] with RGB or RGBA format.

```python
import fpng

# ... process image ...

png_bytes = fpng.from_ndarray(img)

with open('file_path.png', 'wb') as f:
    f.write(png_bytes)
```


### with OpenCV

```python
import cv2
import fpng

img = cv2.imread(EXAMPLE_PNG)
png_bytes = fpng.from_cv2(img)

with open('file_path.png', 'wb') as f:
    f.write(png_bytes)
```
