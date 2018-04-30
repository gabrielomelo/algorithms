import numpy
import cv2 as cv

"""
        Author: Gabriel Melo. License: GPL v3.

	Implementação de reconhecimento facial com opencv e haar.
"""


#HAAR path
haar_path = "haarcascade_frontalface_default.xml"

#Inicializando a camera e convertendo a imagem de BGR para grayscale

cascade = cv.CascadeClassifier(haar_path)
camera = cv.VideoCapture(0)

while True:
	
	img_value, img = camera.read()
	img = cv.flip(img, 1)
	gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
	
	#Classificando em cascata, usando o haar
	positions = cascade.detectMultiScale(gray_img, 1.3, 5)
	
	for (x, y, w, h) in positions:
		cv.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)

        cv.imshow("Source", img)

	if cv.waitKey(1) == 27:
	    break
