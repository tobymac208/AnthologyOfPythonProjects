from pyzbar.pyzbar import decode
from PIL import Image

img = Image.open("/home/nikf/Pictures/qrcodes/myqrcodeCOLORED.png")

results = decode(img)

print(results)
