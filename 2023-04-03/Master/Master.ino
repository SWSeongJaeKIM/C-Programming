#define RING_BUFFER_SIZE 8
#define TEMP_BUFFER_SIZE 64
static char ring_buff[RING_BUFFER_SIZE]={0,};
static int data = 0;

void setup(){
//put your setup code here, to run once:
  Serial.begin(38400); 
  pinMode (45,OUTPUT);
  
}

void clear_buff()
{
  for (int j = 1; j < RING_BUFFER_SIZE; j++) {
  ring_buff[j] = '0';
}
}

void loop()
{
  clear_buff(); 
  char read_temp[TEMP_BUFFER_SIZE]; // 온도 값을 읽어들일 배열 선언
  if (Serial.available() > 0) // 시리얼 통신으로 데이터가 들어온 경우
    {
      byte leng = Serial.readBytes(read_temp, TEMP_BUFFER_SIZE); // 시리얼 통신으로 들어온 데이터를 읽어들임
      digitalWrite(45, HIGH); // 45번 핀에 HIGH 값을 출력하여 전원을 공급
      delay(2); // 2ms의 딜레이
      digitalWrite(45, LOW); // 45번 핀에 LOW 값을 출력하여 전원을 차단
      Serial.print("INPUT data Lengh : "); 
      Serial.println(leng); // 들어온 데이터의 길이를 시리얼 모니터에 출력
     for (int i = 0; i < leng; i++) // 들어온 데이터의 길이만큼 반복
      {
        if(ring_buff[data] != 0)
        {
          ring_buff[data] = 0;
        }
        ring_buff[data] = read_temp[i]; // ring buffer에 들어온 데이터를 저장
        Serial.print(read_temp[i]); // 시리얼 모니터에 읽어들인 데이터 출력
        data++; // ring buffer에 데이터 저장 시 인덱스 값을 증가
        if (data >= RING_BUFFER_SIZE) data = 0; // ring buffer에 더 이상 데이터를 저장할 수 없는 경우 인덱스 값을 초기화
      }
  Serial.println(" "); 
  Serial.print("data no : "); 
  Serial.println(data); // 시리얼 모니터에 ring buffer에 저장된 데이터 수 출력
  for (int j = 0; j < RING_BUFFER_SIZE; j++) // ring buffer의 모든 데이터에 대해 반복
  {
    Serial.print(ring_buff[j]); // 시리얼 모니터에 ring buffer에 저장된 데이터 출력
  }
 
  Serial.println(" "); // 시리얼 모니터에 개행 출력
 }
  
}
