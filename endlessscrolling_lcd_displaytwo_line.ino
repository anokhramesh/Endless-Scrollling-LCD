#include <LiquidCrystal.h>
int rs=9;
int en=8;
int d4=7;
int d5=6;
int d6=5;
int d7=4;

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

// Change following variables as per your need
char * LargeText = "    HALLOW EVERYBODY.I AM RAMESH HERE.WELCOME TO ANOKH AUTOMATION.    ";

int iLineNumber = 0;                                                                   // Line number to show your string (Either 0 or 1)

int iCursor = 1;

void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{ 
  lcd.setCursor (0,1);
  lcd.print("+971557407961");
 
 
  UpdateLCDDisplay();                                                                 // Scoll text by 1 character
  delay(500);                                                                         // Change delay to change speed for scrollig text. 
}

void UpdateLCDDisplay()
{
  int iLenOfLargeText = strlen(LargeText);                                            // Calculate lenght of string.
  if (iCursor == (iLenOfLargeText - 1) )                                              // Reset variable for rollover effect.
  {
    iCursor = 0;
  }
  //lcd.clear();
  lcd.setCursor(0,iLineNumber);
  
  if(iCursor < iLenOfLargeText - 16)                                                  // This loop exicuted for normal 16 characters.
  {
    for (int iChar = iCursor; iChar < iCursor + 16 ; iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
  }
  else
  {
    for (int iChar = iCursor; iChar < (iLenOfLargeText - 1) ; iChar++)                //  This code takes care of printing charecters of current string.
    {
      lcd.print(LargeText[iChar]);
    }
    for (int iChar = 0; iChar <= 16 - (iLenOfLargeText - iCursor); iChar++)           //  Reamining charecter will be printed by this loop.
    {
      lcd.print(LargeText[iChar]);   
    }
  }
  iCursor++;
}
 
