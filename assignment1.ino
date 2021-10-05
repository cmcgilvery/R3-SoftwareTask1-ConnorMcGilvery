
void setup()
{
  Serial.begin(9600); 
}

int * convertdecimal(int decimal)
{
 int *binary = new int[4];//pointer array which represents the decimal value in binary
 //for loop converts the firstdigit and seconddigit variables into binary and storing the results in 
 //firstdigitbinary and seconddigitbinary. It works by comparing the decimal number 
  for (int i = 3; i > -1; i--)
  {
      //compares decimal to 8, if greater or equal set bit 3 to 1, then subtract 8 from decimal and continue comparing
        //if less than 8, set pin 3 to 0 and continue comparing
        if( i==3 & decimal>=8 ){
          
            binary[3] = 1;
            decimal=decimal-8;
        }
        else if (i==3)
        {
          binary[3] =0;
        }
      //compares decimal to 4, if greater or equal set bit 2 to 1, then subtract 4 from decimal and continue comparing
        //if less than 4, set pin 2 to 0 and continue comparing
        if( i==2 & decimal>=4 ){
          binary[2] =1;
            decimal=decimal-4;
        }
        else if (i==2)
        {
        binary[2] =0;
        }
      //compares decimal to 2, if greater or equal set bit 1 to 1, then subtract 2 from decimal and continue comparing
        //if less than 2, set pin 1 to 0 and continue comparing
        if( i==1 & decimal>=2 ){
          binary[1] =1;
            decimal=decimal-2;
        }
        else if (i==1)
        {
        binary[1] =0;
        }
      //compares decimal to 1, if greater or equal set bit 0 to 1, then subtract 1 from decimal and done comparing
        //if less than 1, set pin 0 to 0 and done comparing
        if( i==0 & decimal==1 ){
          binary[0] =1;
            decimal=0;
        }
        else if (i==0)
        {
        binary[0] =0;
        }
 }
  return binary;
}


void loop()
{
  int potval = analogRead(A0); //reads voltage from potentiometer into potval variable
  int decimalval = potval/10.333 ;//scales potentiometer value to be between 0-99 
  int firstdigit = decimalval%(10); //obtains the digit to be printed to the first 7 seg
  int seconddigit = (decimalval - firstdigit)/10; //obtains the digit to be printed to the second 7 seg
  int firstdigitbinary[4];// array that represents the first digit in binary
  int seconddigitbinary[4];// array that represents the second digit in binary
 
  // sets firstdigitbinary and seconddigitbinary to their decimal values that were converted to binary
  for (int i=0; i<4; i++)
  {
    firstdigitbinary[i] = *(convertdecimal(firstdigit)+i); 
    seconddigitbinary[i] = *(convertdecimal(seconddigit)+i) ;
  }
  
  
  //writes the binary representation of the first and second number 
  //to pins 2,3,4,5 for the first number and pins 6,7,8,9 for the second
  //where each pin represents 1 bit
  for (int i=0; i<4; i++)
  {
    digitalWrite(i+2, firstdigitbinary[i]);
    digitalWrite(i+6, seconddigitbinary[i]);
  }  
  Serial.println(decimalval);
  
  delay(1000);
}
