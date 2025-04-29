Operating Systems IT 2244

Day 01 Practical(14/03/2015)

COMMAND PROMPT PRACTICAL

Practical 01: Creating a Batch Script for Directory Structure Creation

Procedure       :
1.Open a Text Editor
2.Open your preferred text editor (e.g., Notepad++, Visual Studio Code, or Notepad).
We have used Notepad++
3.Write the Script
In the text editor, type the following script. This script uses basic batch commands like mkdir
(make directory) and cd (change directory) to create a structured hierarchy.

mkdir criteria_1
cd criteria_1
mkdir standard_1
mkdir standard_2
cd..
mkdir criteria_2
cd criteria_2
mkdir standard_1
mkdir standard_2
cd..
mkdir criteria_3
cd criteria_3
mkdir standard_1
mkdir standard_2
mkdir standard_3
cd..
mkdir criteria_4
cd criteria_4
mkdir standard_1
mkdir standard_2
mkdir standard_3
cd..
mkdir criteria_5
cd criteria_5
mkdir standard_1
mkdir standard_2
mkdir standard_3
cd..
mkdir criteria_6
cd criteria_6
mkdir standard_1
mkdir standard_2
mkdir standard_3

4.Running the Batch Script:

4.1.Save the Script:
After typing the script, save the file with a .bat extension. For example, save it as create_directories.bat
4.2.Execute the Script:
Locate the .bat file in File Explorer.
Double-click on the file to execute the script.
The script will automatically create the directory structure in the location where the .bat file is executed.


Output          :


Conclusion      :
mkdir   : Creates directories.
cd      : Changes the current working directory
cd..    : Moves to the prevoius directoryOutput  
        :
-------------------------------------------------------------------------------------------------------------------------------
Practical 02 : Creating a Batch Script for Displaying System Information

Procedure       :

1.Open a Text Editor
Open your preferred text editor (e.g., Notepad++, Visual Studio Code, or Notepad). We have used Notepad++.

2.Write the Script
In the text editor, type the following script. This script displays system information (username, version,
date, and time) .

@echo off
echo username:%username%
echo version:
ver
echo date:%date%
echo time:
time
pause

3.Save and Execute the Script

3.1.Save the Script:
Save the file with a .bat extension. For example, save it as system_info.bat.

3.2.Execute the Script:

Locate the .bat file in File Explorer.
Double-click on the file to run the script.
The script will display the system information and pause until
press any key.

Output          :
username : ASUS
version:

Microsoft Windows [Version 10.0.26100.3476]
date: Sun 03/23/2025
time:
The current time is: 19:12:13.54
Enter the new time:
Press any key to continue

Conclusion      :
@echo off: Hides the command prompt output, making the script cleaner.

echo: Displays text to the user.

%username%: Displays the current user's name.

ver: Displays the Windows version.

%date% and time: Display the current date and time.

pause: Keeps the command prompt window open until the user presses any key.


-------------------------------------------------------------------------------------------------------------------------------

Practical 03: Creating a Batch Script for Age Calculation

Procedure       :
 1.Open a Text Editor:
2.Write the  following Script:

@echo off
set /p birth_year=Enter your birth year:
set /a age=%date:~10,4% - %birth_year%
echo your age is:%age%
pause

3.Running the Batch Script:

3.1.Save the Script:
After typing the script, save the file with a .bat extension.

3.2.Execute the Script:
Locate the .bat file in File Explorer.
Double-click on the file to execute the script.
It will ask you to input your birth year, and then it will calculate and display your age.

Output          :
Enter your birth year: 2000
Your age is: 25
Press any key to continue

Conclusion      :
set /p: Prompts the user to input a value. In this case, it asks for the user's birth year.

set /a: Performs arithmetic operations. It calculates the user's age by subtracting the input birth year from the current year.

%date:~10,4%: Extracts the current year from the %date% variable (the year part of the system date).

echo: Displays the calculated age to the user.

pause: Keeps the command prompt open until the user presses any key.

The batch script successfully calculates and displays the user's age based on the current date and their birth year.
It demonstrates basic batch scripting techniques like user input, arithmetic calculations, and system date handling.
-------------------------------------------------------------------------------------------------------------------------------
Practical 04  : Basic Commands in CMD
1. color A
Explanation:
The color command in the Command Prompt is used to change the text and background color of the command window.
color A changes the text color to green.

0 = Black       8 = Gray
1 = Blue        9 = Light Blue
2 = Green       A = Light Green
3 = Aqua        B = Light Aqua
4 = Red         C = Light Red
5 = Purple      D = Light Purple
6 = Yellow      E = Light Yellow
7 = White       F = Bright White

Conclusion:
color A: This command is useful for customizing the appearance of the Command Prompt window by changing the text
color, making the interface more visually.

2.  dir

Explanation:
The dir command displays a list of files and directories in the current directory.
Running dir will show the contents of the folder you're currently in, including files,
directories, and additional information like size and date modified.

Output:
C:\Users\ASUS\Desktop>dir
Volume in drive C is OS
Volume Serial Number is 4C71-DB6D

Directory of C:\Users\ASUS\Desktop

03/23/2025  01:53 AM    <DIR>          .
03/22/2025  12:23 AM    <DIR>          ..
03/23/2025  01:53 AM               523 .ABC.tsv.un~
03/22/2025  08:54 PM             3,131 .abc.txt.un~
03/22/2025  09:46 PM               523 .pqr.csv.un~
03/22/2025  08:55 PM            12,288 .xysCUsersASUS.swp
03/22/2025  08:57 PM               523 .xyz.txt.un~
03/22/2025  08:54 PM                33 abc.txt
03/20/2025  10:11 PM                 0 abc.txt~
12/27/2023  06:17 PM    <DIR>          Android
03/22/2025  08:55 PM            17,931 ATTRIB
03/22/2025  08:55 PM             1,033 babun.lnk
03/16/2025  02:30 PM               290 batchFile.bat
03/17/2025  11:26 PM               727 Documents - Shortcut (2).lnk
03/20/2025  08:54 AM               727 Documents - Shortcut (3).lnk
08/17/2024  10:14 AM               727 Documents - Shortcut.lnk
03/21/2025  10:22 PM             2,126 functios.js
03/11/2025  09:08 PM             2,370 GitHub Desktop.lnk
01/16/2025  10:22 PM             2,590 GMUN - Chrome.lnk
02/12/2025  01:21 AM    <DIR>          GMUN 2025
03/22/2025  03:34 PM    <DIR>          JS
03/16/2025  03:48 PM    <DIR>          linux practice
10/02/2024  06:55 PM    <DIR>          MercuryMail
03/22/2025  12:14 AM             1,383 Opera Browser.lnk
03/23/2025  04:49 PM    <DIR>          OS
03/22/2025  10:26 PM                48 pqr.csv
03/22/2025  09:43 PM                 0 pqr.csv~
03/22/2025  11:10 PM                24 pqrNew.csv
07/22/2024  09:31 AM             1,625 Proteus 8 Professional.lnk
03/22/2025  11:16 PM                24 rows.csv
05/20/2024  01:50 PM             1,930 Zoom.lnk
32 File(s)        253,080 bytes
16 Dir(s)  67,814,019,072 bytes free

Conclusion  :
dir: This is a fundamental command for viewing the contents of a directory, useful for navigation and file management.

3. date
Explanation:
The date command displays or sets the system's current date.
If run without parameters, it shows the current date and allows the user to set a new date if needed.

Output:
C:\Users\ASUS\Desktop>date
The current date is: Sun 03/23/2025
Enter the new date: (mm-dd-yy)
Conclusion:
date: The date command helps users view and modify the system date, which may be required for specific tasks or configurations.

4.  dir /w

Explanation:
The dir /w command lists the contents of the current directory in wide format.
Unlike the regular dir, which shows detailed information (like size, date), dir /w displays only the filenames in multiple columns,
making it easier to view a large number of files.

Output :
C:\Users\ASUS\Desktop>dir /w
Volume in drive C is OS
Volume Serial Number is 4C71-DB6D

Directory of C:\Users\ASUS\Desktop

[..]
.ABC.tsv.un~                   .abc.txt.un~
.pqr.csv.un~                   .xysCUsersASUS.swp
.xyz.txt.un~                   [2.1Seniors]
[2.2 Notes]                    ABC.tsv
abc.txt                        abc.txt~
[Android]                      ATTRIB
babun.lnk                      batchFile.bat
[C exercises]                  campus letter.jpg
CodeBlocks.lnk                 [contrib]
[Day_2_JS]                     [Design and Analysis]
Desktop - Shortcut.lnk         [Dip in English]
Documents - Shortcut (2).lnk   Documents - Shortcut (3).lnk
Documents - Shortcut.lnk       functios.js
GitHub Desktop.lnk             GMUN - Chrome.lnk
[GMUN 2025]                    [JS]
[linux practice]               [MercuryMail]
Opera Browser.lnk              [OS]
pqr.csv                        pqr.csv~
pqrNew.csv                     Proteus 8 Professional.lnk
rows.csv                       SALES AGREEMENT_shaha.docx
[SOFTWERE]                     WhatsApp (Outdated).lnk
WhatsApp.lnk                   xyz.txt
xyz.txt~                       Zoom.lnk
32 File(s)        253,080 bytes
16 Dir(s)  67,811,373,056 bytes free

Conclusion :
dir /w: This command provides a more compact and readable way to view directory contents, especially when there are
many files in the current directory.
