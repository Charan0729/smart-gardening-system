1) Install Arduino IDE:

    -Download and install the Arduino IDE from the official website: Arduino Software.
    -Ensure you have the latest version installed, as older versions might lack support for the NodeMCU board.

2) Add ESP8266 Board Manager:

    -Open Arduino IDE.
    -Go to File > Preferences.
    -In the "Additional Board Manager URLs" field, add the following URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json.
    -Click "OK" to close the Preferences window.

3) Install ESP8266 Board Package:

    -Go to Tools > Board > Boards Manager....
    -Type "esp8266" in the search bar.
    -Select the "esp8266" platform by ESP8266 Community and click "Install".
    -Once installed, close the Boards Manager window.

4) Select NodeMCU Board:

    -Now that the ESP8266 board package is installed, you can select the NodeMCU board.
    -Go to Tools > Board and choose "NodeMCU 1.0 (ESP-12E Module)" from the list.

5) Select Port:

    -Connect your NodeMCU board to your computer using a USB cable.
    -Go to Tools > Port and select the port that corresponds to your NodeMCU board.

6) Verify Installation:

    -To ensure that everything is set up correctly, upload a simple example sketch to your NodeMCU board.
    -Go to File > Examples > ESP8266 > Blink.
    -This will open the Blink sketch, which blinks an LED connected to pin D4 on the NodeMCU board.
    -Click the "Upload" button (arrow icon) or press Ctrl + U to compile and upload the sketch to your NodeMCU board.
    -If everything is set up correctly, you should see the built-in LED on your NodeMCU board blinking.

Procedure :

 - Connect the circuit as given in the circuit diagram.

Components used:
   1) Ultrasonic sensor
   2) Temperature and humidity sensor(DHT11)
   3) LDR sensor
   4) Soil moisture sensor
   5) 5v Relay
   6) led
   7) Resistor (220 ohm)
   8) Nodemcu (esp8266)
   9) Jumper wires

- Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Search for and install the following libraries if you haven't already:
     - `ESP8266WiFi`
     - `ESPAsyncTCP`
     - `ESPAsyncWebServer`
     - `Wire`
     - "DHT"

Set Wi-Fi Credentials:
   - In the code, replace `"USERNAME"` with your Wi-Fi network's SSID and `"WIFI PASSWORD"` with the corresponding password.

1. Upload Code:
   - Copy the provided code and paste it into the Arduino IDE.
   - Make sure your ESP8266 board is selected under `Tools` > `Board`.
   - Select the correct port under `Tools` > `Port`.
   - Click the "Upload" button (arrow icon) or press `Ctrl + U` to compile and upload the code to your ESP8266 board.

2. Monitor Serial Output (Optional):
   - Open the Serial Monitor (`Ctrl + Shift + M`) to view debug messages and the IP address assigned to the ESP8266 board. The IP address           is crucial for accessing the web server.

3. Access Web Interface:
   - Once the code is uploaded successfully and the ESP8266 is connected to the Wi-Fi network, open a web browser on any device connected to the same network.
   - Enter the IP address of the ESP8266 (displayed in the Serial Monitor) in the browser's address bar and press Enter.

4. Control the Notice Board:
   - In the web interface, you should see a text input field. 
   - The OUTPUT readings will be displayed on the web page connected to the ESP8266 board.


5. Modify and Experiment:
   - Feel free to modify the code according to your requirements. You can change the HTML structure, add more functionality, or adjust the display settings as needed.

6. Troubleshooting:
   - If you encounter any issues, double-check your connections, Wi-Fi credentials, and ensure that the libraries are installed correctly.
   - Refer to the Serial Monitor for any error messages or debugging information to help diagnose the problem.