import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
#Inside the while loop we define the HSV ranges (low_red, high_red), we create the mask and we show only the object with the red colour.

    # Red colour
    low_red = np.array([0, 150, 50])
    high_red = np.array([10, 255, 255])
    red_mask = cv2.inRange(hsv_frame, low_red, high_red)
    red = cv2.bitwise_and(frame, frame, mask=red_mask)
#Same for the other colours:

    # Orange colour
    low_orange = np.array([10, 100, 20])
    high_orange = np.array([25, 255, 255])
    orange_mask = cv2.inRange(hsv_frame, low_orange, high_orange)
    orange = cv2.bitwise_and(frame, frame, mask=orange_mask)

    # Green colour
    low_green = np.array([25, 52, 72])
    high_green = np.array([102, 255, 255])
    green_mask = cv2.inRange(hsv_frame, low_green, high_green)
    green = cv2.bitwise_and(frame, frame, mask=green_mask)

    cv2.imshow('frame',frame)
    cv2.imshow('red',red)
    cv2.imshow('orange',orange)
    cv2.imshow('green',green)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
