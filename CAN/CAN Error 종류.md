# CAN Error 의 종류

<img src="https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/282d64fe-9af5-4e6c-827d-454f7d7366c5" width=800>

---

### Bit Error

각각의 전송단은 전송된 신호의 레벨을 모니터링하고 있다가 전송된 신호와 Monitoring된 신호의 레벨이 다를 때 발생

중재기간 동안에는 Bit Error는 발생되지 않음

### Stuff Error

Transmitter가 data bit를 전송할 경우 동일 레벨의 bit가 5회 이상 계속되면, 6번째에는 연속된 bit level의 반전된 level의 bit가 자동삽입

NRZ coding을 사용하기 때문에 중간에 직렬 통신을 윟나 동기가 필요하기 때문

### CRC Error

수신된 CRC Sequence와 계산된 CRC Sequence가 일치하지 않을 때 CRC Error를 발생함 

### Form Error

CAN 메세지 중, CRC Delimiter, ACK Delimiter, EOF의 영역에 '0'(dominant) 값이 나타날 때 발생

### ACK Error

ACK Slot 동안 수신 장치가 '0'(dominant)을 보내주지 않을 때 발생

이 에러는 모든 수신 장치가 접속 되어 있지 않을 때, 즉 선로가 끊겼을 때 등의 경우에 발생 

