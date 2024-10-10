// Определяем пины
const int smokeSensorPin = A0;  // Аналоговый пин для датчика задымления
const int buzzerPin = 9;         // Цифровой пин для зумера

// Порог задымления (нужно калибровать для вашего датчика)
const int smokeThreshold = 300;  // Измените это значение на основании ваших тестов

void setup() {
  // Настройка пинов
  pinMode(smokeSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Инициализация последовательного монитора
  Serial.begin(9600);
}

void loop() {
  // Считываем данные с датчика
  int smokeLevel = analogRead(smokeSensorPin);
  
  // Печатаем данные о задымлении в монитор для отладки
  Serial.print("Smoke level: ");
  Serial.println(smokeLevel);

  // Если уровень задымления превышает порог, включаем зумер
  if (smokeLevel > smokeThreshold) {
    tone(buzzerPin, 1000);  // Включаем зумер с частотой 1000 Гц
  } else {
    noTone(buzzerPin);       // Выключаем зумер
  }

  // Задержка для стабильности
  delay(500);
}