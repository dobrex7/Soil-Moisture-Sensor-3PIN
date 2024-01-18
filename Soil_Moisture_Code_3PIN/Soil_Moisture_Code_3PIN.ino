void setup() {
  Serial.begin(9600);
}

void loop() {
  int vrednostSenzorja = analogRead(A0); // vhod , v katerga je priključen senzor
  int procentVlage = map(vrednostSenzorja, 450, 0, 100, 0); //450 je max vrednost, ko je 100% in 0 min vrednost, ko je 0% 
 
 if(vrednostSenzorja>=450) //if pogoj, ki fiksira, vlažnost na 100%, če dobi vrednost nad 450, kar je avtomatsko max vlažnost

    {
      procentVlage = 100; //procent vlaznosti nastavimo na 100%
    }

  Serial.println(" "); //prazna vrsta

 // Izpis vlage v %
 Serial.print("Vlaga je ");
 Serial.print(procentVlage);
 Serial.println("%");

// Izpis vlage v enotah od 0 do 1018
  Serial.print("Vlaga je ");
  Serial.print(analogRead(A0));
  Serial.println(" enot");

  Serial.println(" "); //prazna vrsta

// Izpis vlage, ko je stanje kriticno oz. ko je pod 20% vlaznosti
  if (procentVlage<=20)
  {
  Serial.println("Stanje vlage je kriticno ");
  //Serial.print(analogRead(A0));
  Serial.print("Vlaga je ");
  Serial.print(procentVlage);
  Serial.println("%");
  }

// Izpis vlage, ko je stanje srednje oz. ko je nad 21% in pod 40% vlaznosti
  if (procentVlage>=21 & procentVlage<=40)
  {
  Serial.println("Stanje vlage je srednje ");
  //Serial.print(analogRead(A0));
  Serial.print("Vlaga je ");
  Serial.print(procentVlage);
  Serial.println("%");
  }

// Izpis vlage, ko je stanje visoko oz. ko je nad 41% vlaznosti
  if (procentVlage>=41)
  {
  Serial.println("Stanje vlage je visoko ");
  //Serial.print(analogRead(A0));
  Serial.print("Vlaga je ");
  Serial.print(procentVlage);
  Serial.println("%");
  }

  delay(2000); // 2 sekundi pavze
}
