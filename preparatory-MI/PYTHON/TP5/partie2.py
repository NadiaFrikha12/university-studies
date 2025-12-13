import numpy as np
import matplotlib.pyplot as plt

def lire_image(ImageName):
    image = plt.imread(ImageName)
    print (image.shape)
    print (image.dtype)
    return image

def affiche_image(ImageName):
    image = lire_image(ImageName)
    plt.inshow(image)
    plt.show()

def charger_img_rouge (Image):
    rouge = np.zeros

    