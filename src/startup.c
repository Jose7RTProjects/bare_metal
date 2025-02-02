extern unsigned int _stored_data, _sdata, _edata, _sbss, _ebss, _estack, _erodata;
extern int main(void);

void Reset_Handler(void)
{
  unsigned int *src, *dst;
  src = (unsigned int *)&_stored_data;
  dst = (unsigned int *)&_sdata;
  while (dst != (unsigned int *)&_edata) {
    *dst++ = *src++;
  }

  dst = (unsigned int *)&_sbss;
  while (dst != (unsigned int *)&_ebss) {
    *dst++ = 0;
  }
  
  main();
}

void NMI_Handler(void)
{
  while(1);
}

void HardFault_Handler(void)
{
  while(1);
}

void MemManage_Handler(void)
{
  while(1);
}

void BusFault_Handler(void)
{
  while(1);
}

void UsageFault_Handler(void)
{
  while(1);
}

void SVC_Handler(void)
{
  while(1);
}

void DebugMon_Handler(void)
{
  while(1);
}

void PendSV_Handler(void)
{
  while(1);
}

void SysTick_Handler(void)
{
  while(1);
}

__attribute__((section(".isr_vector")))
void (* const isr_vector[])(void) = 
{
  (void (*)(void))(&_estack),
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0, 
  0, 
  0, 
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler
  
  // External interrupts...
};