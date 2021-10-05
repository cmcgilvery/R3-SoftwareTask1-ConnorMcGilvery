# R3-SoftwareTask1-ConnorMcGilvery
The program works by first reading in the potentiometers value into the potval 
variable. This value is then converted to a demical range of 0-99. Then the digits 
are seperated into the firstdigit and seconddigit variables. These variables are then 
converted into binary using the convertdecimal function. The convert decimal function works 
by comparing the decimal value to each bit of a 4 digit binary number. It start at the msg 
ends at the lsb, subtracting from the decimal value each time if it is equal to or greater 
than the bit it is being compared to. The binary values are then stored in firstdigitbinary 
and seconddigitbinary arrays. These arrays are then written to the ports 2-9 where each 
index of the arrays would be written to 1 port. Ports 2-5 represent the first digit and
ports 6-9 represent the second.

https://www.tinkercad.com/things/llB9GLq7Ru9-magnificent-leelo-hango/editel?sharecode=Ng-2Qij0nuLlrwaiD_1QwnYDtus5gQ2KFt5FrScwmjg
