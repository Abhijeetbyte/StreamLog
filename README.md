# StreamLog
The idea of streamlining your data logging process. The library's functionality is it to format and log data your sensor data coming from Arduino in a streamlined manner. 

## Need ? 🙄

The StreamLog library simplifies the process of logging and formatting data from your Arduino sketch, allowing you to focus on your core logic without worrying about the intricacies of data formatting. With just one **function** call, you can log multiple data variables along with their corresponding names, and the library takes care of CSV formatting of your data, adding timestamps, and visualizing it directly on the Arduino Serial Console.

This streamlined approach eliminates the need for writing additional lines of code in your sketch for data logging purposes, saving you time and effort. You can easily use the logged data with any additional application for further analysis, visualization, or integration with other systems as it formats the raw Arduino data into a comma-separated file (CSV). Whether you're prototyping a project or developing a complex application where you want to monitor changes in data patterns over an extended period of time, StreamLog simplifies the process and enhances the efficiency of data logging and formatting within one platform without using any additional or third-party application.

## Working ⚙️

Import the [StreamLog](https://github.com/Abhijeetbyte/StreamLog.git) library in your Arduino sketch.
 
Call the inbuilt *function* in your sketch 

ex:
```
void setup (){

StreamLog.begin(9600); // intilize and define baud rate
}

void loop(){

StreamLog.data (delay, "dataName_1", data1Variable,  "dataName_2", "dataName_3", data3Variable, etc....);

}
```
Connect the board upload your sketch and turn on the serial monitor.<br/>
Here `delay` is the duration of the interval, you can also leave it as 0

<br/>


## Output 🚀

You can also enable the timestamp feature of the Serial monitor, otherwise that column will be zero.<br/>
Output on the Arduino **Serial** monitor, of an LDR connected as analog input.

```
Timestamp (HH:MM:SS.MMM), Light Intensity,  Timelasped  ( S )
16.53.45.687, 100, 0 
16.58.00.011, 75, 300
17.03.00.094, 46, 600
17.08.00.014,  17,900

```

This is data reading of sunset, the experiment was started just before sunset, and set to log data in an interval of every 5 minutes in `StreamLog.data(300, ..... );`



<br/>
<br/>

## Post Processing 👷‍♂️

* Now after completing the experiment, just click on Serial monitor windows and copy everything.
* Open any text editor, here I am opening Notepad, and pasting it there, Click on "Save As.." or click CTRl+Shift+S.
* Save it as **.CSV**

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/1fa30d83-23c3-4443-8a53-3a222a42032d)


* Change "Text Documents (*.txt) to "All Files (*.)"
* You are done, the file was already in CSV format, just open it in MS Excel or anywhere else.
Open it to see the changes in data over elapsed time or visualize the trend line

![image](https://github.com/Abhijeetbyte/StreamLog/assets/80936610/2d5b4005-2000-4ff3-b7c7-76c815e10f2d)



<br/>
<br/>

