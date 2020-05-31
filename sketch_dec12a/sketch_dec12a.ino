int podanaLiczba;
String podanaLiczbaS;
int binarki[] = {128, 64, 32, 16, 8, 4, 2, 1};
int ledy[] = {2,3,4,5,6,7,8,9};
int odczytanaWartosc;
int val;
long tim;

void setup()
{
  for(int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  tim=millis();
  odczytanaWartosc = analogRead(A0);

// WPISYWANIE WARTOSCI RECZNIE
//  for(int j=0; j<8; j++)
//  {
//    digitalWrite(ledy[j],LOW);
//  }
//  Serial.println(odczytanaWartosc);
//  if(Serial.available() > 0)
//  {
//    podanaLiczbaS=Serial.readString();
//    podanaLiczba=podanaLiczbaS.toInt();  
//    if(podanaLiczba>255)
//    {
//      Serial.println("Podana liczba ("+String(podanaLiczba)+") jest za duza. Najwieksza liczba obslugiwana przez program to 255.");
//    }
//    else if(podanaLiczba<0)
//    {
//      Serial.println("Podana liczba ("+String(podanaLiczba)+") jest za mala. Najmniejsza liczba obslugiwana przez program to 0.");
//    }
//    else
//    {
//      Serial.println(podanaLiczba);
//      for(int i=0; i<8; i++)
//      {
//        if(podanaLiczba>=binarki[i])
//        {
//          podanaLiczba-=binarki[i];
//          digitalWrite(ledy[i],HIGH);
//          Serial.println(podanaLiczba);
//        }
//      }
//    }
//  }

//POTENCJOMETR
  //delay(500);
  val = map(odczytanaWartosc, 0, 1023, 0, 255);
  
  if(tim%1000==0)
  {
    Serial.println(val);
  }
  
  for(int i=0; i<8; i++)
  {
    if(val>=binarki[i])
    {
      val-=binarki[i];
      digitalWrite(ledy[i],HIGH);
    }
    else
    {
      digitalWrite(ledy[i],LOW);
    }
  }  
}
