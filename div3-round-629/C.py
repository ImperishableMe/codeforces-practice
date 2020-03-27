import io
import os
import sys
from io import BytesIO
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline