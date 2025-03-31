# RFID_Acess_Control
This project is an RFID-based access control system using an Arduino and MFRC522 RFID module. The system scans RFID cards and logs their presence on a connected computer. The Arduino reads the UID of each scanned RFID card and sends it over Serial Communication, while a Python script running on the computer listens for incoming data and saves it to a file (log.txt) with the message "the secured person is in". This setup ensures secure and trackable access logging. The project is ideal for attendance tracking, access control, or security systems. Simply upload the Arduino sketch, run the Python script, and scan RFID cards to log entries automatically! 🚀

