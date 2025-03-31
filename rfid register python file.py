import serial
import time

# Change 'COM3' to the correct port for your Arduino
# Windows Example: "COM3"

arduino_port = "COM3"
baud_rate = 9600

# Open serial connection to Arduino
try:
    ser = serial.Serial(arduino_port, baud_rate, timeout=1)
    time.sleep(2)  # Allow Arduino time to initialize
    print("Listening for RFID scans...")
except serial.SerialException:
    print("Error: Could not open serial port.")
    exit()

# Infinite loop to continuously read RFID tags
while True:
    try:
        # Read RFID UID from Arduino
        rfid_data = ser.readline().decode("utf-8").strip()
        
        if rfid_data:
            print(f"RFID Scanned: {rfid_data}")
            
            # Save the UID to a log file with the specified message
            with open("log.txt", "a") as file:
                file.write(f"{rfid_data} - the secured person is in\n")
                
    except KeyboardInterrupt:
        print("\nStopping program...")
        ser.close()
        break
    except Exception as e:
        print(f"Error: {e}")
