# StreamLog
The idea of streamlining your data logging process. <br/>
Library functionality is to format and log sensor data, coming from your microcontroller in a streamlined manner. 

## Need ? 🙄

The StreamLog library simplifies the process of logging and formatting data from your Arduino sketch, allowing you to focus on your core logic without worrying about the intricacies of data formatting. With just one **function** call, you can log multiple data variables along with their corresponding names, and the library takes care of CSV formatting of your data, adding timestamps, and visualizing it directly on the Arduino serial console.

This streamlined approach eliminates the need for writing additional lines of code in your sketch for data logging purposes, saving your time and effort. You can easily use the logged data with any additional application for further analysis, visualization, or integration with other systems as it formats the raw Arduino data into a comma-separated file (CSV). Whether you're prototyping a project or developing a complex application where you want to monitor changes in data patterns over an extended period of time, StreamLog simplifies the process and enhances the efficiency of data logging and formatting within one platform without using any additional or third-party application.

## Working ⚙️

Import the [StreamLog](https://github.com/Abhijeetbyte/StreamLog.git) library in your Arduino sketch.
 
Call the **functions** of this library in your sketch, and put your data variables as arguments along with their names.

ex:
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

## Download 👇
<br/>

* You can download the latest release of this library as zip : [download](https://github.com/Abhijeetbyte/StreamLog/releases)
  <br/>
* Or you install it from you **Arduino IDE** library manager
  <br/>
  <br/>
![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/84307640-85d6-4601-97fe-05dfeccc6718)
