khalli_chaab_yefhem_RFID_QT
# Arduino scenario for qt
This code allows you to add an RFID scenario for login to your QT program such that when the user swipes his card qt verifies the existence of the UID code in the database if yes an I2C LCD display connected to the Arduino UNO card will display the user's name and the QT will redirect you to the corresponding wwidget, otherwise "Not Found" will be displayed.
## Steps
### Arduino Part

![rfid](https://user-images.githubusercontent.com/132101523/235252668-4c41c831-7b1a-49fa-9d6e-a21c05735c67.PNG)

* Download then upload the .ino file into the Arduino Card.

### QT part
* add " serialport " after the "QT += "to your .pro file.
* Add the Arduino class to your QT project and copy pase the code ( even if you have it copy paste the code "serial->waitreadyread(200)will make the difference).
* Add what's in the file "to_be_added.cpp" in the constructor of the Mainwindow.cpp.
* Add the "connect_rfid()" function in " private slots " of your Mainwindow.h file. 
* copy and paste the function "connect_RFID()" in the Maainwindow.cpp.

##### img src: https://surtrtech.com/2018/01/27/quick-guide-to-wire-and-use-the-rc522-rfid-module-with-arduino/


