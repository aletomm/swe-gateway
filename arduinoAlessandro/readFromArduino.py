import serial
import time
ser = serial.Serial('/dev/cu.usbmodem14201', 9600)
time.sleep(2)
# Read and record the data
data =[] 
while True:                      # empty list to store the data
	for i in range(50):
	    b = ser.readline()         # read a byte string
	    string_n = b.decode()  # decode byte string into Unicode  
	    string = string_n.rstrip() # remove \n and \r
	      
	    print(string)
	    data.append(string)           # add to the end of data list
	    time.sleep(0.01)      

	# show the data

	for line in data:
	    print(line)    
