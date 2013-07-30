#######################################
# The Hybrid Front Translation Project
# Tiago Rezende
#
# Character Tile Graphics Translator
#######################################

# turns out that there's two character tile tables in Hybrid Front. One with mixed-width characters, and another, fixed-width one.
# I happened to extract the fixed-width one, and it is what the in-game text uses.
# Title screen, index and setup screens use the variable-width text.

# The variable-width table is a tilemap which reuses lots of data between characters.
# it starts around 000CA58E and ends in 000CC706
# there's a table with big 16x16 uppercase letters (EDCBA) and a cups symbol starting at 000CA4E.

from PIL import Image

# Character tiles start at 0x001845AE in rom, and are 1bpp.
# Each character is 4 tiles, top-bottom, then left-right

romstart = 0x001845CE
romend = 0x001904CE
charsize = 32 # bytes, 8x4
charcount = (romend - romstart) / charsize

def extract_tile(f, offset, charnum):
    f.seek(offset)
    img = Image.new("RGB",(16,16))
    try:
        for y in xrange(16):
            char = f.read(1)
            line = ord(char)
            for x in xrange(8):
                img.putpixel((x,y), (255,255,255) if (line & 0x80) else (0,0,0))
                line = line * 2
        for y in xrange(16):
            char = f.read(1)
            line = ord(char)
            for x in xrange(8):
                img.putpixel((8+x,y), (255,255,255) if (line & 0x80) else (0,0,0))
                line = line * 2
    finally:
        fname = "chars/0x{0:0>4x}.png".format(charnum)
        print "salvando tile "+fname
        img.save(fname)
        return fname
    
f = open("Hybrid_Front,_The_(J)_[a1].bin","rb")
f2 = open("hfchars.html","w")
f2.write("<!doctype html><html><body>\n")
offset = romstart
for c in xrange(charcount):
    fname = extract_tile(f, offset, c)
    f2.write("<img src=\"{0}\" />\n".format(fname))
    offset += charsize
f.close()
f2.write("</body></html>")
f2.close()
