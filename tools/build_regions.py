"""Builds embervale_regions.bin: 320x320 region ids (row 0 = north), 32 m per cell, 0 = no region."""
import sys, json, numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage
src, out_bin, out_json, preview = sys.argv[1:5]
a = np.fromfile(src, np.uint8).reshape(2048,2048,4)[...,:3]
x = np.asarray(Image.fromarray(a).resize((320,320), Image.BOX)).astype(float)/255
mx=x.max(-1); mn=x.min(-1); d=mx-mn+1e-6; r,g,b=x[...,0],x[...,1],x[...,2]
H=np.where(mx==r,((g-b)/d)%6,np.where(mx==g,(b-r)/d+2,(r-g)/d+4))*60%360; S=(mx-mn)/(mx+1e-6)
void = (H>255)&(H<318)&(S>0.14)
void = ndimage.binary_opening(void, iterations=1)
lab, n = ndimage.label(void)
edge = set(np.unique(np.concatenate([lab[0],lab[-1],lab[:,0],lab[:,-1]]))) - {0}
sea = np.isin(lab, list(edge))          # shroud connected to the map edge
land = ndimage.binary_closing(~sea, iterations=2)
regions = [  # name, polygon in 320-grid (x right, y down)
 ("Volcanic North",   [(112,62),(150,40),(170,10),(252,12),(270,55),(262,86),(230,88),(200,86),(172,96),(140,92),(112,86)]),
 ("Albaneve Summits", [(172,96),(200,86),(262,86),(292,88),(300,140),(296,192),(240,184),(176,178),(166,170),(186,140),(176,110)]),
 ("Veilwater Basin",  [(84,72),(140,72),(140,92),(172,96),(176,110),(186,140),(166,170),(150,180),(112,166),(112,120),(84,112)]),
 ("Revelwood",        [(55,112),(84,112),(112,120),(112,166),(150,180),(150,186),(112,184),(70,182),(52,168)]),
 ("Springlands",      [(25,182),(70,182),(112,184),(150,186),(158,214),(166,320),(20,320),(20,230)]),
 ("Nomad Highlands",  [(158,176),(240,184),(222,200),(216,258),(200,270),(168,282),(160,250),(156,214)]),
 ("Kindlewastes",     [(222,184),(300,190),(310,320),(184,320),(184,276),(216,260),(216,200)]),
]
ids = np.zeros((320,320), np.uint8)
for i,(name,poly) in enumerate(regions, start=1):
    m = Image.new('L',(320,320),0); ImageDraw.Draw(m).polygon(poly, fill=1)
    ids[(np.asarray(m)>0) & (ids==0) & land] = i
# land cells outside every polygon (small islands) join the nearest region
_, idx = ndimage.distance_transform_edt(ids==0, return_indices=True)
near = ids[idx[0], idx[1]]
ids = np.where(land & (ids==0), near, ids).astype(np.uint8)
ids.tofile(out_bin)
json.dump({"cell_metres": 32, "size": 320, "regions": [r[0] for r in regions]}, open(out_json,'w'), indent=2)
pal = np.array([[25,25,35],[230,110,40],[210,210,220],[70,140,230],[30,110,40],[140,210,90],[230,200,70],[240,170,190]],np.uint8)
img = Image.fromarray((x*255).astype(np.uint8)).resize((960,960))
ov = Image.fromarray(pal[ids]).resize((960,960),Image.NEAREST)
im = Image.blend(img, ov, 0.55); dr = ImageDraw.Draw(im)
for i,(name,poly) in enumerate(regions, start=1):
    ys,xs = np.nonzero(ids==i)
    if len(xs): dr.text((xs.mean()*3-40, ys.mean()*3), f"{i} {name}", fill=(255,255,255), stroke_width=2, stroke_fill=(0,0,0))
    print(i, name, int((ids==i).sum()), 'cells')
im.save(preview)
