INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6) {
  digitalWrite(PD3,!digitalRead(PD3));
}

void setup() {
  disableInterrupts();
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);
  enableInterrupts();
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_IN_PU_IT);
  pinMode(PD3,OUTPUT);
  digitalWrite(PD3,LOW);
}

void loop() {
  
}

void EXTI_SetExtIntSensitivity(EXTI_Port_TypeDef Port, EXTI_Sensitivity_TypeDef SensitivityValue)
{
  switch (Port)
  {
  case EXTI_PORT_GPIOA:
    EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PAIS);
    EXTI->CR1 |= (uint8_t)(SensitivityValue);
    break;
  case EXTI_PORT_GPIOB:
    EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PBIS);
    EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
    break;
  case EXTI_PORT_GPIOC:
    EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PCIS);
    EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 4);
    break;
  case EXTI_PORT_GPIOD:
    EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PDIS);
    EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 6);
    break;
  case EXTI_PORT_GPIOE:
    EXTI->CR2 &= (uint8_t)(~EXTI_CR2_PEIS);
    EXTI->CR2 |= (uint8_t)(SensitivityValue);
    break;
  default:
    break;
  }
}
