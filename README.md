# Roll2020
## A Cyberpunk2020 oriented dice roller and character creator built for the command line

**OPTIONS:**  
  -p&emsp;Prints a percentage.  
  -s&emsp;Sums the rolls of each respective die type.  
  -c&emsp;Creates a random character based on the "fast" method forgenerating character points. This means that no stat will be lower than 3.  

**EXAMPLES:**  
Roll a percentage.    
    &emsp;roll2020 -p&emsp;&emsp;&emsp;This will roll a percentage.  
    &emsp;roll2020 -p -p -p&ensp;&ensp;This will roll 3 percentage rolls.  
    &emsp;roll2020 -ppp		This will also roll 3 percentage rolls.  

  Roll d10s and/or d6s.  
    &emsp;roll2020 2 d6 4 d10		This will roll 2 d6 and 4 d10.  
    &emsp;roll2020 2 d6 d10		This will roll 2 d6 and 1 d10.  
    &emsp;roll2020 2 d6		This will roll 2 d6.  
    &emsp;roll2020 -s 2 d6 4 d10	This will roll 2 d6 and 4 d10 and return the sum of each.  

  Generate characters.
    roll2020 -c			This will generate a character (role, stats, and derived stats).
    roll2020 -c -c -c		This will generate 3 characters.
    roll2020 -ccc		This will also generate 3 characters.

  Errors.
    roll2020 4 2 d6		This will roll 2 d6. The 4 will be ignored.
    roll2020 -s			This will reseult in error (cannot sum without dice).
    roll2020 2 d6 d10 4		This will result in error (trailing numerical argument).
    roll2020 2 d6 4 d10 2 d10	This will result in error (trailing arguments).ums the rolls of each respective die type.  
  -c    Creates a random character based on the "fast" method for  
        generating character points. This means that no stat will be lower than 3.  
