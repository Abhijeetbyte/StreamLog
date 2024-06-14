
<p align="center">
    <h1 align="center">StreamLog</h1>
    <h4 align="center">
      The idea of streamlining your data logging process.
    </h4>
  <br>
</p>


<!-- Badge section -->

[![Releases](https://img.shields.io/badge/Github-Releases-blue)](https://github.com/Abhijeetbyte/StreamLog/releases)
![GitHub Tag](https://img.shields.io/github/v/tag/abhijeetbyte/StreamLog)
[![License](https://img.shields.io/github/license/abhijeetbyte/StreamLog)](LICENSE)
![GitHub top language](https://img.shields.io/github/languages/top/abhijeetbyte/streamlog)
[![arduino-library-badge](https://www.ardu-badge.com/badge/StreamLog.svg?)](https://downloads.arduino.cc/libraries/logs/github.com/Abhijeetbyte/StreamLog/)

<!--https://github.com/arduino/library-registry-->





Library functionality is to format and log sensor data, coming from your microcontroller in a streamlined manner. 

## Need ? 🙄

The **StreamLog library** revolutionizes how you log and format data in your Arduino or similar microcontroller sketches, letting you concentrate on your core project instead of dealing with data formatting hassles. With a single **function call**, you can effortlessly log multiple data variables along with their names. The library handles **CSV formatting**, adds timestamps, and even visualizes data directly on the Arduino serial console or any other terminal program.

By simplifying the data logging process, **StreamLog** saves you time and effort. You no longer need to write extra lines of code inside your microcontroller for logging—**StreamLog** does it all for you. The logged data is formatted into a **comma-separated file (CSV)**, making it easy to use with any application for further analysis, visualization, or system integration.

Whether you're **prototyping a new project** or developing a complex application where you need to monitor data patterns over time, **StreamLog** enhances efficiency. It simplifies the data logging and formatting process within a single platform, eliminating the need for additional or third-party applications.

**Experience streamlined data logging and focus on what truly matters—your project.**


## Features 🌟
* No, need to write extra codes for data formatting and printing on the serial monitor.
* Standard data output as a comma-separated file (CSV). 
* Support custom time intervals for data output ( second, minutes, hours etc..)
* Use any software to see your data ( Arduino serial monitor, PuTTY etc. ) as long it supports serial communication.
* Available as plug-and-play, just import/include the library in your sketch. 
<br/>

## Download 👇
<br/>

* You can [Download](https://github.com/Abhijeetbyte/StreamLog/releases) the latest release of this library as a zip and import it into your Arduino IDE.
  <br/>
  
  **Or**
  
* Available on the [**Arduino IDE**]() library manager, you can search for it directly there.

  <br/>
  <br/>
![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/84307640-85d6-4601-97fe-05dfeccc6718)


<br/>
<br/>

## Working ⚙️

* Import the [StreamLog](https://github.com/Abhijeetbyte/StreamLog.git) library in your Arduino sketch.
 
* Call the **functions** of this library in your sketch, and put your data variables as arguments along with their names.

**Example**:

```cpp
void setup() {

  // Initialize serial communication with a baud rate of 9600
  sensorLogger.begin(9600); 

  // Log the sensor data headings
  sensorLogger.head("Light Intensity"); // Variable name or column heading
}

```

```cpp
void loop() {

  // Read the analog value from the LDR sensor
  int lightIntensity = analogRead(LDR_PIN);

  // Log the sensor data
  sensorLogger.data(300000, 1, lightIntensity); // Variable
}

```
Here,
*  `StreamLog.head` function is for sensor data heading/name of columns, this could be as many as you want.
*  In `StreamLog.data`
   - 300000: Time interval between data logs in milliseconds ( 5 minutes)
   - 1: Total number of variables ( sensor readings), this could be as many as you want.
     
<br/>
     
Upload the sketch and turn on the serial monitor.

<br/>

<br/>


## Output 🚀


Output on the Arduino **Serial** monitor as *CSV* format, of an LDR connected as analog input. <br/>
You can also enable the timestamp feature of the Serial monitor, otherwise timestamp column will be zero.<br/>

```
Timestamps (HH:MM:SS), Elapsedtime (S), Light Intensity
16.53.05.687,          300,                100
16.58.10.011,          600,                75
17.03.08.094,          900,                46
17.08.06.014,          1200,               17

```

This is **data** reading of sunset, the experiment was started just before sunset, and set to log data in an interval of every 5 minutes in `StreamLog.data(300000, ..... );`



<br/>
<br/>

## Post Processing 👷‍♂️

* Now after completing the experiment, click on the Serial monitor window and copy everything.
* Open any text editor, here I am opening Notepad, and past it there, Click on "Save As.." or click Ctrl+Shift+S.
* Save it as **.CSV**

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/53bb7a71-031a-490e-a604-66660909e372)


* Change "Text Documents (.txt)" to "All Files"
* You are done, the file was already in CSV format, just open it in MS Excel or anywhere else.
Open it to see the changes in data over elapsed time or visualize the trend line

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/00167a72-2240-4bfa-bbe7-f9a80184c3b2)


<br/>
<br/>



## Reporting Issues & Contributions

Feel free to report <b>[issues](https://github.com/Abhijeetbyte/StreamLog/issues/new)</b> and <b>contribute</b> to this repository


## License

Copyright © 2024 Abhijeet kumar. All rights reserved.

Licensed under the [MIT License](LICENSE).
