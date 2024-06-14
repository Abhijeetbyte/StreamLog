
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

```
void setup (){

StreamLog.begin(9600); // intilize and define baud rate
}

void loop(){

  StreamLog.head("LDR1, LDR2, LDR3, etc....");
  StreamLog.data(5000, 3, LDR1intensity, LDR2intensity, LDR3ntensity, etc...);

}
```
Here,
*  `StreamLog.head` function is for sensor data headings/names of columns, this could be as many as you want.
*  In `StreamLog.data`
   - 5000: Time interval between data logs in milliseconds (5 seconds)
   - 3: Total number of variables ( sensor readings), including the delay and other values. This could be as many as you want.
     
<br/>
     
Upload the sketch and turn on the serial monitor.

<br/>

<br/>


## Output 🚀


Output on the Arduino **Serial** monitor as *CSV* format, of an LDR connected as analog input. <br/>
You can also enable the timestamp feature of the Serial monitor, otherwise timestamp column will be zero.<br/>

```
Timestamp (HH:MM:SS.MMM), Light Intensity,  Elapsed time ( S )
16.53.45.687, 100, 0 
16.58.00.011, 75, 300
17.03.00.094, 46, 600
17.08.00.014,  17,900

```

This is data reading of sunset, the experiment was started just before sunset, and set to log data in an interval of every 5 minutes in `StreamLog.data(300000, ..... );`



<br/>
<br/>

## Post Processing 👷‍♂️

* Now after completing the experiment, click on Serial monitor windows and copy everything.
* Open any text editor, here I am opening Notepad, and past it there, Click on "Save As.." or click Ctrl+Shift+S.
* Save it as **.CSV**

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/1fa30d83-23c3-4443-8a53-3a222a42032d)


* Change "Text Documents (.txt)" to "All Files"
* You are done, the file was already in CSV format, just open it in MS Excel or anywhere else.
Open it to see the changes in data over elapsed time or visualize the trend line

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/2d5b4005-2000-4ff3-b7c7-76c815e10f2d)



<br/>
<br/>



## Reporting Issues & Contributions

Feel free to report <b>[issues](https://github.com/Abhijeetbyte/StreamLog/issues/new)</b> and <b>contribute</b> to this repository


## License

Copyright © 2024 Abhijeet kumar. All rights reserved.

Licensed under the [MIT License](LICENSE).
