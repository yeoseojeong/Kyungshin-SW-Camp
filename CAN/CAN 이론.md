### CAN BUS OSI Architecture

<br>

<img src="https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/67191130-cf65-42cf-a31d-64529c64de27" width=700>

<br>

 ---
 
### CAN 프레임 구조

<br>

<img src="https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/f628f3e3-6944-4b22-93b5-30d58bd78f2e" width=700>

<br>


<br>


**1. SOF(Start Of Frame) 비트**

1 bit 구성

 메세지의 시작을 의미하는 주요한 비트로 버스의 노드(node)를 동기화하기 위해 사용

**2. Identifier(ID)**

 식별자로서 메세지의 내용을 식별하고 메시지의 우선순위를 부여 

 CAN 메세지에 있는 ID 의 길이에 따라서 표준 CAN과 확장 CAN 두가지 양식 (mode)로 구분

 표준 CAN은 11 비트 식별자, 확장 CAN은 29비트 식별자로 구분

 **3. Control**

  6 bits로 구성

 상위 2bit: 확장될 것을 위해 추가로 준비 / 하위 4 bit: DLC(Data Length Code)

 데이터의 길이(DLC)를 의미

 **4. Data**

 최대 8bit 로 구성

 DLC에 의해 Date의 바이트 수 결정
 
 전달하고자 하는 내용을 의미

 **5. CRC**

 메세지의 유효성 검증을 위한 방법

 프레임의 송신 오류 및 오류 검출에 사용

 **6. ACK 비트(Bit)**

오류가 없는 메세지가 전송되었다는 것을 의미하는 비트

CAN 제어기는 메세지를 정확하게 수신했다면 ACK(Acknowledgement) 비트 전송

전송 노드는 버스 상에서 ACK 비트가 발견되지 않는 다면 재전송 시도

**7. EOF(End Of Frame) 비트**

7개의 열성(1) bit으로 구성

프레임의 끝을 나타내고 종료를 의미
 
---
 

### CAN 통신의 동작 방법

CAN 버스에는 전체 노드를 제어하는 주인 (Master)이 없어서 CAN 버스에서 데이터를 쉽게 접근 가능

CAN 제어기는 CAN 버스 선이 사용 다른 제어기에 의해서 사용중인지 확인

CAN 버스 선이 사용중이지 않다면 모든 노드는 ID 값을 통해서 자신에게 필요한 메세지를 확인 ( 불필요한 메세지 무시, 필요한 메세지 수신)

다중 노드가 동시에 메세지를 CAN 버스에 전송하려는 경우에는 가장 낮은 ID값을 가진 최우선 노드가 자동으로 버스에 접근 (EX. 1>7)

우선 순위가 높은 메세지가 CAN 버스의 사용권한을 보장 받을 수 있으며 낮은 순위의 다른 노드들은 대기해야하며 자동으로 다음 버스 사이클에서 재전송 수행



