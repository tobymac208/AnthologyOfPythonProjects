import qrcode

DIRECTORY = "/home/nikf/Pictures/qrcodes"

data = "Don't you forget about me."

qr = qrcode.QRCode(version=1.0, box_size=10, border=5)
qr.add_data(data)
qr.make(fit=True)

img = qr.make_image(fill_color='red', background_color='white')

img.save(f'{DIRECTORY}/myqrcodeCOLORED.png')
