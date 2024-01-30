# 모델기반 설계 (MBD, Model-based Design)

복잡성, 다양성에 대응할 수 있는 설계 기법

제품 개발 주기 전체 단계에서 적용
- 제어대상(plant)을 모델링(modeling)
- 제어기를 설계 및 분석, 자동 코드 생성
- 제어대상과 제어기를 모의실험(simulation)
- 제어기의 적합성을 판단 후 제품에 적용

  ![image](https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/3ff800be-a575-411f-a5ba-c48e097e983e)


### 모델기반 설계의 장점
- Modeling & Simulation
- 
  새로운, 개선된 알고리즘 적용 시 성능 검증 용이
  
- Human Error & Human resource 감소
  
  Hand coding으로 인한 오류 감소
  
  테스트, 보고서 작성, 코딩 자동화에 따른 인력 감소
  
- Traceability (추적성)
  
  Requirement – System Design – Test 추적성 확보
  
- 비용 절감
  
  개발 프로세스 기간 단축
  
  개발 초기단계에서 오류 검출


### 제품 개발 주기 관리

  #### V-model
  ![image](https://github.com/yeoseojeong/Kyungshin-SW-Camp/assets/121150215/7eb6629c-993a-4225-8493-bb84e8b7db67)

  
- 하드웨어 &소프트웨어 개발의 각 단계마다
- MBD 적용
- 산출물 문서화


### 모델기반 설계의 개발 및 테스트 단계

MIL, SIL, HIL, VIL은 시스템 개발 및 검증 단계에서 사용되는 여러 가지 시험 단계를 나타내는 용어

**MIL (Model-in-the-Loop)**
   - 모델 기반 설계에서 시작
   - 개발된 모델이 시뮬레이션 환경에서 실행되어 검증
   - 모델의 동작이 예상대로 이루어지는지 확인 검증

**SIL (Software-in-the-Loop)**
   - SIL 단계에서는 모델 기반 개발에서 생성된 소프트웨어가 검증
   - 소프트웨어가 실제 하드웨어와 연결되어 동작하고 제대로 동작하는지를 확인
   - 이는 실제 하드웨어에 올리기 전에 소프트웨어의 동작 검증

**HIL (Hardware-in-the-Loop)**
   - HIL 단계에서는 실제 하드웨어가 시뮬레이션 환경에 연결
   - 실제 하드웨어와 소프트웨어가 함께 동작하며, 시스템의 동작을 검증
   - 이는 시스템이 실제 하드웨어에서 어떻게 동작할지를 확인 검증

**VIL (Vehicle-in-the-Loop)**
   - VIL 단계에서는 차량 시스템의 개발 검증
   - 실제 차량이 시험 환경에 연결되어 시스템의 동작을 검증
   - 이는 실제 도로 상황에서 시스템이 어떻게 동작할지를 확인 검증

