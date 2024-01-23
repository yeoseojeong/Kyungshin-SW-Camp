# AUTOSAR

#### AUTOSAR 란?
##### AUTOSAR(AUTomotive Open System ARchitecture) 

자동차의 개방형 시스템 구조

자동차 전자 제어 유닛(ECU) 및 소프트웨어의 개발, 통합 및 유지 관리를 위한 개방형 표준 아키텍처

'AUTOSAR'는 자동차 부품을 제어하기 위한 SW의 표준화를 목표로 하는 단체, 소프트웨어 플랫폼


#### AUTOSAR의 필요성

기술 발전으로 인해 크고 비싼 기계식 부품을 작고 저렴한 전자식 부품으로 대체 가능


But, 오작동 발생 가능성 증가 
(각 기능을 담당하는 전자 제어 장치는 다른 장치들과 네트워크로 연결되어 있어 소프트웨어에서 오류가 발생할 때 미치는 영향도 커졌기 때문임)

그 결과 자동차 관련 업체가 모여 연구 -> AUTOSAR 플랫폼

복잡한 자동차 시스템에서 공통적으로 사용하는 기능은 플랫폼에서 API로 제공

기능별로 통합하여 검증하게 되면 더 체계적으로 오류 발견 가능, 수정이 쉬워져 필요한 노력 절감



#### AUTOSAR OVERVIEW

<img src="https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/bc2e51b6-e013-4bb1-8d8b-7fa756a28a68" width=600>


크게 BSW, AUTOSAR RTE, AUTOSAR Software 총 3계층



#### BSW

- 다양한 전자 제어 장치 (ECU, Electronic Control Unit)에서 공통으로 사용하는 기능 구현되어 있는 계층 

- 여러 stack으로 이루어지고, 특징에 따라 다시 하드웨어 추상화 stack군과 표준 소프트웨어 stack 군으로 나눌 수 있음

- 하드웨어 추상화 stack 군 => ECU Abstraction, Complex Device Drivers

- 소프트웨어 추상화 stack 군 => OS, Service

- 각 stack은 interface를 통해 BSW 내부의 다른 stack과 다른 계층과 데이터를 주고받을 수 있음


<br>

#### AUTOSAR Software 

- 실제 ECU로 인해 동작하고자 하는 상세 기능들을 구현한 부분

- 각 기능은 Software 단위로 구분 

- Components는 단독으로 기능 구현에 사용될 수도 있고 연관된 component를 연결하여 하나의 component처럼도 구현 가능

- Component의 종류는 기능에 따라 Application Software Component, Actuator Software Component, Sensor Software Component 등이 있음

- Software Component에 따라 데이터를 주고 받는 방식 다름



<br>

#### AUTOSAR RTE (Runtime Environment)

- BSW와 AUTOSAR Software 간의 데이터 이동 통로 역할 

- VFB(Virtual Functional Bus) 통신 구조

- Component간의 통신을 가상의 환경에서 제공하는 구조라 변경이 쉽고 sw는 hw와 독립적으로 동작 가능




